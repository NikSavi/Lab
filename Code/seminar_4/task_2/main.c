#include<stdio.h>
#include "fun.h"
#define LEN 100

int main(){
    char array[LEN];
    printf("Enter the number:  ");
    int reg = get_array(array);
    get_alg(array, reg);
}