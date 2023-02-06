/***************************************************************
 Author: Luke MacVicar
 Date: September 24th
 Answer to question: Stack overflow occurs becasue we are calling a function each time before completing the orginal function. This causes the computer to pause previous function and start new one instead of killing old function.
 ******************************************************************/

#include <stdio.h>

void recursive_down_to_zero(int number);
void recursive_up_to_int(int number);

int main(int argc, char * argv[]){
    int x = 10;
    recursive_down_to_zero(x);
    printf("****\n");
    recursive_up_to_int(x);
    return 0;
}

void recursive_down_to_zero(int number){
    if(number >= 0){
        printf("%d\n",number);
        recursive_down_to_zero(number-1);
    }
}

void recursive_up_to_int(int number){
    if(number >= 0){
        recursive_up_to_int(number-1);
        printf("%d\n",number);
        
    }
}

