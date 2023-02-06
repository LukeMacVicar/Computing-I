/***********************************************
Author: Luke MacVicar
Date: 10/19/22
Purpose: This program reads in an input from the user and then determines if the input is valid. It does this by checking the value of the input and if it does not meet the standards it asks again until you get the proper input. It then prints out the number of asterisks that the user input.
Time Spent: 15 mins
***********************************************/
void clear_keyboard_buffer(void);

#include<stdio.h>

int main(int argc, char * argv[]){
    int asterisks = 0;
    int noc = 0;
    
    printf("Please enter a number of asterisks in your line: ");
    noc = scanf("%d",&asterisks);
    clear_keyboard_buffer();

    while(asterisks < 1 || asterisks > 79 || noc != 1){
        printf("I'm sorry, you must enter a number between [1-79]: ");
        noc = scanf("%d",&asterisks);
        clear_keyboard_buffer();
    }
    
    int x = 0;
    while(x < asterisks){
        printf("*");
        x++;
    }
    printf("\n");
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


