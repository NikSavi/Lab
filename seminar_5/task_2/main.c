#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h> 
#include "calc.h"

#define MAXOP 100
#define NUMBER '0'

int getop (char []);

int main() {
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push (atof (s));
                break;

            /*  ARITHMETIC  */    
            case '+':
                push (pop() + pop());
                break;
            case '*':
                push (pop() * pop());
                break;
            case '-':
                op2 = pop();
                push (pop() - op2);
                break;
            case '/' :
                op2 = pop();
                if (op2 != 0.0){
                    push (pop() / op2);
                }
                else{
                    printf("error: zero divisor\n");
                    return -1;
                }
                break;
            case '%' :
                op2 = pop();
                 if (op2 != 0.0){
                    push(trunc(pop() / op2)); 
                }
                else{
                    printf("error: zero divisor\n");
                    return -1;
                }
                break;
            case '^':
                push(pow(pop(), pop()));
                break;

            /*  TRIGONOMETRY  */ //new
            case 'c': 
                push(cos(pop()));
                break;
            case 's': 
                push(sin(pop()));
                break;

            /*  WORK'S CASES  */
            case '\n' :
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                return -1;
        }
    }
    return 0;
}

int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getchar()) == ' ' || c == '\t' )
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getchar()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getchar()))
            ;
    s[i] = '\0';
    return NUMBER;
}