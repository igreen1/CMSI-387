#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUT_SIZE 25

int main(int argc, char * argv[]){

    int input[INPUT_SIZE],
        entryNumber = 0;
    char buffer[10];
    char inputString[INPUT_SIZE*11]; // guestimate on the size of the string needed
    // not essential but nice to clear
    for(int i = 0 ; i < INPUT_SIZE; i++){
        input[i]=0;
        inputString[i] = 0;
    }
    
    do{
        printf("\nEnter a number: ");
        scanf("%d", &input[entryNumber]);
    }while( input[entryNumber++] != -9999 && entryNumber < INPUT_SIZE);

    if(entryNumber != INPUT_SIZE){
        input[--entryNumber] = 0; // Don't include the -9999
    }
    entryNumber--; //Don't include the value after the last value (since iteration occurs while checking)

    int sum = 0;
    for(int i = 0; i <= entryNumber; i++)
        sum += input[i];

    printf("-------------------");
    printf("\nSum: %d", sum);
    printf("\nCount of elements: %d", (entryNumber+1));
    printf("\nAverage: %f\n", ( ((float)sum)/((float)entryNumber+1) ));

    for(int i = 0; i <= entryNumber; i++){
        sprintf(buffer, "%d", input[i]);
        strcat(inputString, buffer);
    }

    int sevenCounter = 0;
    for(int i = 0; i <= entryNumber; i++){
        if(inputString[i] == 0) break;
        else if (inputString[i] == '7') sevenCounter++;
    }

    printf("%s\n", inputString);
    printf("7 count: %d\n", sevenCounter);

    

}
