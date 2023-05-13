#include<stdio.h>

void print_horizontal(int array[]){
    for(int i =0; i < 10; i++){
        printf("%d: ", i);
        for(int j = 0; array[i] != 0; j++){
            printf("#");
            array[i] = array[i] - 1;
        }
        printf("\n");
    }
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
    return limb;
}


void print_vertical(int array[]){
    while(1){
        int M[10] = {0};
        int max = 0;
        for(int i = 0; i < 10; i++){
            if(array[i] > max){
                max = array[i];
            }
        }
        if(max == 0){
            break;
        }
        for(int i =0; i < 10; i++){
            if(array[i] == max){
                M[i] = 1;
                array[i] = array[i] - 1;
            }
        }
        for(int i =0; i <10; i++){
            if(M[i] == 1){
                printf(" # ");
            }
            else{
                printf("   ");
            }
        }
        printf("\n");
    }
    printf(" 0  1  2  3  4  5  6  7  8  9 ");
}


int count_num(char array[], int dia[], int point){
    for(int i =0; i < point+1; i++){
        if((47 < array[i]) && (array[i] < 58)){
            dia[array[i]- 48] += 1;
        }
    }
}