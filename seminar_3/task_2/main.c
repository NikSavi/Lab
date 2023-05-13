#include <stdio.h>
#include "fun.h"
#define LEN 100

int main(){
    char string_1[LEN];
    char string_2[LEN];
    printf("------------------------------------------------------------------------------------");
    printf("\nEnter the first string: ");
    int reg_1 = get_array(string_1);
    printf("Enter the second string:  ");    
    int reg_2 = get_array(string_2);
    printf("The result:\n");
    get_alg(string_1, string_2, reg_1, reg_2);
    printf("\n------------------------------------------------------------------------------------");

}