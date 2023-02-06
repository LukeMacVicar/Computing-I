/***********************************************
Author: Luke MacVicar
Date: 10/19/22
Purpose: This program reads in an input from the user and then determines if the input is valid. It does this by checking the value of the input and if it does not meet the standards it asks again until you get the proper input. This program will succeed if it is a negative integer and fail if it is not.
Time Spent: 15 mins
***********************************************/
void clear_keyboard_buffer(void);

#include<stdio.h>

int main(int argc, char * argv[]){
    int x = 0;
    int noc = 0;
    printf("Please enter a negative integer: ");
    noc = scanf("%d",&x);
    clear_keyboard_buffer();
    printf("%d\n", x);
    while(x >= 0 || noc != 1){
        printf("I'm sorry, you must enter a number less than zero: ");
        noc = scanf("%d",&x);
        clear_keyboard_buffer();
    }
    return 0;
}

void clear_keyboard_buffer(void){
    char c;
    scanf("%c",&c);
    while(c != '\n')
    {
       scanf("%c",&c);
    }
}

