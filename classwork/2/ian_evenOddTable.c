#define LOWER_LIMIT -10
#define UPPER_LIMIT 10

#include <stdio.h>
#include <string.h>

int square(int);

int main(int argc, char *argv[]){
    
    int lower = LOWER_LIMIT;
    int upper = UPPER_LIMIT;
    char parity[5];
    int evenCount = 0;
    int oddCount = 0;

    for(int i = lower; i <= upper; i++){
        if(i % 2 == 0){
            strcpy(parity, "EVEN");
            evenCount++;
        } else {
            strcpy(parity, "ODD");
            oddCount++;

        }
        printf("%5d\t%5d\t%4s\n",i, square(i), parity);
    }
    printf("# odd numbers = %d\n", oddCount);
    printf("# even numbers = %d\n", evenCount);
}

inline int square(int b){
    return b * b;
}