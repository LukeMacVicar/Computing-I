/***********************************************
 Author: Luke MacVicar
 Date: 10/19/22
 Purpose: This program takes in an integer from the user, if the integer is even it divides it by two, if it is odd it multiplies it by three then adds one. We then print the result. 
 ***********************************************/
#include <stdio.h>

int main(int argc, char * argv[]){
    int number = 0;
    printf("Please enter a positive non zero integer: ");
    scanf("%d",&number);
    if(number%2==0){
        number /= 2;
    }
    else{
        number = (number * 3) + 1;
    }
    printf("The next value of the integer is: %d\n", number);
    return 0;
}

