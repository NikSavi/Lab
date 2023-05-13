#include<stdio.h>
#define LEN_BIN 100

int get_digit(char symbol);

int get_array(char array[]){
    char symbol;
    int counter = 0;
    while((symbol = getchar()) != '\n'){
        array[counter] = symbol;
        counter++;
    }
    array[counter] = '\0'; // to prevent from trach value of the next element after end element
    return counter;
}

void get_alg(char array[], int reg){
    int binary[LEN_BIN];
    int reg_b = LEN_BIN;
    for(int i = reg - 1; i > -1; i--){
        char symbol = array[i];
        int digit = get_digit(symbol);
        for(int j = reg_b-1; j > reg_b-5; j--){
            binary[j] = digit % 2;
            digit /= 2;
        }
        reg_b -= 4;
    }

    int sum = 0;

    for(int i = reg_b; i < LEN_BIN ; i++){
       //printf("\n%d         %d\n", i, binary[LEN_BIN-i]); 
       printf(" %d ", binary[i]);
    }

    for(int i = 0; (reg_b - 1) < (LEN_BIN - 1 -2*i); i++){
        if(binary[LEN_BIN - 1 -2*i]&1 == 1){
            sum++;
        }
    }
    printf("\n%d", sum);
}

int get_digit(char symbol){
    int digit;
    if((symbol > 96) && (symbol < 123)){
        digit = symbol - 87;
    }
    else if ((symbol > 64) && (symbol < 91)){
        digit = symbol - 55;
    }
    else{
        digit = symbol - 48;
    }
    return digit;
}