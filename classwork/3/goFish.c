#define INPUT_SIZE 25

#include <stdio.h>

int main(int argc, char * argv[]){

    int input[INPUT_SIZE];
    // not essential but nice
    for(int i = 0 ; i < INPUT_SIZE; i++)
        input[i]=0;
    int entryNumber = 0;
    
    do{
        printf("\nEnter a number: ");
        scanf("%d", &input[entryNumber]);
    }while( input[entryNumber++] != -9999 && entryNumber < INPUT_SIZE);

    // for(int i = 0; i < INPUT_SIZE; i++){
    //     printf("%d: %d\n", i, input[i]);
    // }

    if(entryNumber != INPUT_SIZE){
        input[--entryNumber] = 0; // Don't include the -9999
    }
    entryNumber--; //Don't include the end input (now zero)

    int sum = 0;
    for(int i = 0; i <= entryNumber; i++)
        sum += input[i];

    printf("-------------------");
    printf("\nSum: %d", sum);
    printf("\nCount of elements: %d", (entryNumber+1));
    printf("\nAverage: %f\n", ( ((float)sum)/((float)entryNumber+1) ));
    

}