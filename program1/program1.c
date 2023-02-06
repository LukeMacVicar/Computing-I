/***********************************************
 Author: Luke MacVicar
 Date: 11/18/22
 Purpose: User enters a starting point and ending point, the program preforms calcuations to determine how many steps it will take to get to 1 using the collatz conjecture. The results are then displayed onto the screen.
Time Spent: 2 hours
***********************************************/
#include <stdio.h>
/*
-Precondition: input counter must be greater than zero
-Postcondition: output needs to be greater than or equal to 1
 */
int hopto(int input_counter);
/*
 -Precondition: none
 -Postcondition: must return an int that is greater than 1 and less than 1000
 */
int user_input1(void);
/*
 -Precondition: none
 -Postcondition: must return an int that is greater than 1 and less than 10000
 */
int user_input2(void);
/*
 -Precondition: input1 and input2 must be greater than zero and input2 must be more than input1
 -Postcondition: none
 */
void display_results(int input1, int input2, int * steps_to_one);
/*
 -Precondition: scanf must be called
 -Postcondition: none
 */
void clear_keyboard_buffer(void);

const int SIZE = 10000;

int main(int argc, char * argv[])
{
    int i;
    int input1;
    int input2;
    int x[SIZE];
    
    
    input1 = user_input1();
    
    input2 = user_input2();
    
    for(i = input1; i <= input2; i++)
    {
        x[i] = hopto(i);
    }
    display_results(input1,input2, x);
    printf("\n");
    return 0;
}

int hopto(int input_counter){
    int current_number = input_counter;
    int counter = 0;
    while(current_number != 1)
    {
        if(current_number % 2 == 0)
        {
            current_number = current_number / 2;
            counter++;
        }
        else
        {
            current_number = (current_number * 3) + 1;
            counter++;
        }
    }
    return counter;
}

void display_results(int input1, int input2, int* steps_to_one)
{
    int i;
    int columns = 0;
    for(i = input1; i <= input2; i++){
        if(columns % 7 != 0 || columns == 0)
        {
            printf("%5d:%-5d",i,steps_to_one[i]);
            columns++;
        }
        else
        {
            printf("\n%5d:%-5d",i,steps_to_one[i]);
            columns++;
        }
    }
}

int user_input1(void)
{
    int input;
    int noc;
    printf("Enter a Starting Point: ");
    noc = scanf("%d", &input);
    clear_keyboard_buffer();
    while(noc != 1 || input < 2 || input > 1000)
    {
        printf("I'm sorry the number you gave was not valid. Please provide a number between 2 and 1000: ");
        noc = scanf("%d", &input);
        clear_keyboard_buffer();
    }
    return input;
}

int user_input2(void)
{
    int input;
    int noc;
    printf("Enter a Ending Point: ");
    noc = scanf("%d", &input);
    clear_keyboard_buffer();
    while(noc != 1 || input < 2 || input > 10000)
    {
        printf("I'm sorry the number you gave was not valid. Please provide a number between previous number and 10000: ");
        noc = scanf("%d", &input);
        clear_keyboard_buffer();
    }
    return input;
}

void clear_keyboard_buffer(void){
    char c;
    scanf("%c",&c);
    while(c != '\n')
    {
       scanf("%c",&c);
    }
}
