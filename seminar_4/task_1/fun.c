#include <stdio.h>

#define LENGTH 100 // number of allowed digit in the string

int input(char array[]);
int little(char array[]);
int trans(char array[], int count);


/* This is the main function */
void foo(){
    char array[LENGTH];
    int count;
    int sum;
    printf("Enter the number in hex:  ");
    input(array);
    count = little(array);
    sum = trans(array, count);
    printf("There we have:  ");
    printf("%d\n", sum);
}

/* This function ask the cymbols*/
int input(char array[]){
    char b;
    int limb;
    for(int i = 0;(b = getchar()) != '\n'; i++){
        array[i] = b;
        limb = i;
    }
    array[limb+1] = '\0'; // to prevent from element number i+1 that has a value
}

/* This make little from big like: to a from A*/
int little(char array[]){
    int count;
    for(int i = 0; array[i] != '\0'; i++){
       if((64 < array[i]) && (array[i] < 71) ){
            array[i] += 32;
       }
       count = i;
    }
    return count;
}

/* This make the sum - ten-base number*/
int trans(char array[], int count){
    int sum = 0;
    for(int mult = 1; count != -1; count--, mult *= 16){
        if((96 < array[count]) && (array[count]< 103)){
            array[count] -= 87;
        }
        else{
            array[count] -= 48;
        }
        sum += array[count]*mult;
    }
    return sum;
}
