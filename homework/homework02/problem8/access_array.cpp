#include <iostream>
#include <string>
#include <sstream>
#include <string.h>
#include <sys/time.h>
#include <fstream>
using namespace std;

const int OUTER_LOOPS = 100;

int main(int argc, const char* argv[]) {
    if (argc != 2) {
        cerr << "invalid arguments!\nusage: ./access_array <array size(4096 bytes)>" << endl;
        return -1;
    }

    int array_size = 0;
    stringstream ss;
    ss << argv[1];
    ss >> array_size;
    if (array_size <= 0) {
        cerr << "array size should be positive!\n";
        return -1;
    }
    array_size *= 4096;
    char *array = new char[array_size];
    memset(array, 'c', sizeof(char)*array_size);
    //warm up
    for (int i = 0; i < OUTER_LOOPS; ++i) {
        for (int j = 4095; j < array_size; j += 4096) {
             array[j] = 'b';
        }
    }
    timeval time_s, time_e;
    gettimeofday(&time_s, NULL);
    for (int i = 0; i < OUTER_LOOPS; ++i) {
        for (int j = 4095; j < array_size; j += 4096) {
             array[j] = 'b' + i % 3;
        }
    }
    gettimeofday(&time_e, NULL);
    double elapsed_time = (time_e.tv_sec - time_s.tv_sec) * 1e6 + (time_e.tv_usec - time_s.tv_usec);
    double average_time = elapsed_time / (OUTER_LOOPS * (array_size / 4096));
    //cout << "elapsed time: " << elapsed_time << endl;
    //cout << "total accesses: " << OUTER_LOOPS * (array_size / 4096) << endl;
    //cout << "array size: " << array_size << " average access time: " << average_time << "us\n";
    ofstream of("test_result.txt", fstream::app);
    if (!of.is_open()){
        cerr << "error opening test_result.txt!\n";
        exit(-1);
    }
    of << array_size/4096 << ',' << average_time << '\n';
    of.close();
    delete [] array;
}
