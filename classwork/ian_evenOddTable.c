#define LOWER_LIMIT -10
#define UPPER_LIMIT 10

#include <stdio.h>
#include <string.h>

int square(int);

int main(int argc, char *argv[]){
    
    int lower = LOWER_LIMIT;
    int upper = UPPER_LIMIT;
    char parity[5];

    for(int i = lower; i <= upper; i++){
        if(i % 2 == 0){
            strcpy(parity, "EVEN");
        } else {
            strcpy(parity, "ODD");

        }
        printf("%5d\t%5d\t%4s\n",i, square(i), parity);
    }   
}

inline int square(int b){
    return b * b;
}