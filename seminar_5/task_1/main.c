#include<stdio.h>
#include "fun.h"
#define LEN 100

int main(){
    char array_1[LEN];
    char array_2[LEN];
    printf("---------------------------------------------------------------------------------------------------");
    printf("\nAttention! The program is working olny with lowwer letters\n");
    printf("Enter the first string:  ");
    int reg_1 = get_array(array_1);
    printf("Enter the second string: ");
    int reg_2 = get_array(array_2);
    printf("The result:\n");

    get_alg(array_1, array_2, reg_1, reg_2);
    printf("\n---------------------------------------------------------------------------------------------------");
}