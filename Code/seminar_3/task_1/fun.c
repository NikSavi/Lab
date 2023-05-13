#include <stdio.h>

/*
This is the brief documentation:
    - function get_array is used as scanf
    - function get_alg is the biggest and the main; it contain algorithm of the executing programme
    - function get_type return int digit; it has only three states: 1, 2, 3. 0 - mean that this char don't exist
    - get_raw print the chars between combination of two elements of the same type and '-' between
*/

/*  This signatures had written becouse this two function are used in this file */
int get_type(char symbol);
int get_raw(int value_1, int value_2);


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

/* advice - read the comment; it help you to understand the structure of the alg    */
void get_alg(char array[], int regi){

    int flag_of_type_1 = 0;
    int flag_of_type_2 = 0;
    int value_1;
    int value_2;
    int flag_line = 0;

    for(int counter = 0; counter < regi; counter++){

        char symbol = array[counter];

        /*   Is this symbol the '-'?    */
        /*   Yes, it is.  */
        if(symbol == '-'){

            /*  Is this '-' the first?    */
            /*  Yes, it is.    */
            if(flag_line == 0){         

                /*  Are there any chars?    */  
                /*  No, thre is not.  */
                if(flag_of_type_1 == 0){
                    printf("-");
                }

                /*  Yes, there is.   */
                else{
                    flag_line = 1;
                }
            }

            /*  No, it is not.   */
            else{

                /*  Are there any chars?    */
                /*  No, there is not. */
                if(flag_of_type_1 == 0){
                    printf("--");
                    flag_line = 0;
                }

                /*  Yes, there is.   */
                else{
                    printf("%c--", value_1);
                    flag_line = 0;
                    value_1 = 0;
                    flag_of_type_1 = 0;

                }
            }
        }

        /*  No, it is not.   */
        else{
            /*  Are there any chars?    */
            /*  No, it is not.  */
            if(flag_of_type_1 == 0){
                flag_of_type_1 = get_type(symbol);
                value_1 = symbol;
            }

            /*  Yes, it is. */
            else{

                flag_of_type_2 = get_type(symbol);
                value_2 = symbol;

                /*  Are there any '-'?  */
                /*  No, it is not.   */
                if(flag_line == 0){
                    printf("%c", value_1);
                }
                else{
                    if(flag_of_type_1 == flag_of_type_2){
                        value_2 = get_raw(value_1, value_2);
                    }
                    else{
                        printf("%c-", value_1);
                    }
                }
                value_1 = value_2;
                value_2 = 0;
                flag_of_type_1 = flag_of_type_2;
                flag_of_type_2 = 0;
                flag_line = 0;
            }
        }
    }

    if(flag_of_type_1 != 0){
        printf("%c", value_1);
    }
    if(flag_line != 0){
        printf("-");
    }
}


int get_type(char symbol){

    /* from 'a' to 'z'  */
    if((symbol < 123) && (symbol > 96)){
        return 3;
    }

    /* from 'A' to 'Z'  */
    else if((symbol < 91) && (symbol > 64)){
        return 2;
    }

    /*  from '0' to '9' */
    else{
        return 1;
    }
}


int get_raw(int value_1, int value_2){
    int step;

    if(value_1 < value_2){
        step = 1;
    }
    else{
        step = -1;
    }

    while(value_1 != value_2){
        printf("%c", value_1);
        value_1 += step;
    }
    return value_1;
}