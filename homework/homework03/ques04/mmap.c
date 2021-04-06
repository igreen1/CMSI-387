#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define target 'X'

int main(int argc, char* argv[]) {
    int fd;
    struct stat st;
    char* mmapp;

    if (argc < 4) {
        printf("Usage: ./mmapp file1.txt file2.txt file3.txt.\n");
        return -1;
    }

    for (int i = 1; i < argc; i++) {
        printf("\n");
        clock_t start, end;
        
        if ((fd = open(argv[i], O_RDONLY)) < 0) {
            printf("Can not open the %s filr.\n", argv[i]);
            continue;
        }

        if ((fstat(fd, &st)) == -1) {
            printf("Can not get the structure of the file: %s.\n", argv[i]);
            return -1;
        }

        if ((mmapp = mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, fd, 0)) == (void*)-1) {
            printf("mmap calling error for file: %s.\n", argv[i]);
            return -1;
        }
        start = clock();
        for (int j = 0; j < st.st_size; j++) {
            if (mmapp[j] == target) {
                printf("Found the target character %c from the mmap file %s.\n", target, argv[i]);
                break;
            }
        }

        end = clock();
        double seconds = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Running time for file %s is %.10fs.\n\n", argv[i], seconds);

        if ((munmap((void*)mmapp, st.st_size)) == -1) {
            printf("munmap error for file %s.\n", argv[i]);
            return -1;
        }
    }
    return 0;
}
