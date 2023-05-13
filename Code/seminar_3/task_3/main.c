#include <stdio.h>
#include "fun.h"
#define LEN 100

int main(){
    char st[LEN];
    int dia[10] = {0};
    printf("Enter your text thet you need to analyise:\n");
    int point = input(st);
    count_num(st, dia, point);

    printf("Press v to vertical or h to horisontal\t");
    char cymbol = getchar();
    printf("\n\n\n");
    if(cymbol == 'v'){
        print_vertical(dia);
    }
    else{
        print_horizontal(dia);
    }
}
