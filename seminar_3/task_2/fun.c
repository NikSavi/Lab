#include <stdio.h>

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

void get_alg(char array_1[], char array_2[], int reg_1, int reg_2){
    
    int mask[100];
    for(int c = 0; c < 100; c++){
        mask[c] = 1;
    }

    int flag;

    for(int i = 0; i < reg_1; i++){

        flag = 1;

        for(int j = 0; j < reg_2; j++){
            if(array_1[i+j] != array_2[j]){
                flag = 0;
            }
        }

        if(flag == 1){
            for(int d = i; d < i+reg_2; d++){
                mask[d] = 0;
            }
        }       
    }

    for(int i = 0; i < reg_1 + 1; i++){
        if(mask[i] == 1){
            char symbol = array_1[i];
            printf("%c", symbol);
        }
    }
}
