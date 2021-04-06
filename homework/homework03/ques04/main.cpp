#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ofstream out("hehe.txt");
  
  for (int i = 0; i < 1000000; i++) {
    for (char ch = 'a'; ch <= 'z'; ch++) out<<ch;
    for (char ch = 'A'; ch <= 'Z'; ch++) {
      if (ch != 'X') out <<ch;
    }
  }
  out << 'X';
  out.close();

  return 1;
}