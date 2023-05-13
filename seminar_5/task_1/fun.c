#include <stdio.h>

void get_u(char array[], int trial[], int reg);

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
    /*  There we create the array of the flags that show having the letters */
    int trial[26];
    for(int i = 0; i < 27; i++){
        trial[i] = 0;
    }

    get_u(array_2, trial, reg_2);

    int pose; // there we store the letter's number in array
    char symbol; // there we store the letter
    int flag = 0;

    for(int i = 0; i < reg_1; i++){
        for(int j = 0; j < 27; j++){
            if((trial[j] == 1) && (array_1[i] == (j+97)) && (flag == 0)){
                pose = i;
                symbol = array_1[i];
                flag = 1;
            }   
        }
    }
    if(flag == 0){
        printf("-1");
    }
    else{
        printf("The letter is %c\n", symbol);
        printf("The index is %d", pose);
    }

}

/*      Creating the trial's array      */
void get_u(char array[], int trial[], int reg){
    for(int i = 0; i < reg; i++){
        trial[(array[i] - 97)] = 1;
    }
}