/****************************************************************
 Author: Luke MacVicar
 Date: 9/24/22
 Description: This program takes in an integer and prints its binary representaion. This is acheived by dividing the number by two and finding the remainder, we then do this until we get to zero. We use recursion to call the funtion over and over until we reach zero and then print our output.
 ******************************************************************/
#include <stdio.h>

void print_binary(int number);

int main(int argc, char * argv[]){
    int x = 123456789;
    print_binary(x);
    printf("\n");
    return 0;
}

void print_binary(int number){
    if(number > 1){
        print_binary(number/2);
    }
    int remainder = number % 2;
    printf("%d",remainder);
}
