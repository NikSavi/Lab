#include <stdio.h>
#include "fun.h"
#define LEN 100

int main(){
    char string[100];
    printf("Enter the string:\n");
    int re = get_array(string);
    printf("Result:\n");
    get_alg(string, re);
}


