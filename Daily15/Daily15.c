/***********************************************
 Author: Luke MacVicar
 Date: November 27 2022
 Purpose: This program prompts the user to see if they want to convert wieghts or lengths. Then the program calls a function based on the user input.
Sources of Help: none
Time Spent: 30 mins
***********************************************/
#include <stdio.h>

void convert_lengths(void);
void convert_weights(void);
void length_to_us(void);
void length_to_metric(void);
void weight_to_us(void);
void weight_to_metric(void);
void clear_keyboard_buffer(void);

int main(int argc, char * argv[])
{
    int input = -1;
    int noc;
    while(1)
    {
        printf("Do you want to convert Legnths(1) or Weights(2)? Enter 0 to exit: ");
        noc = scanf("%d", &input);
        clear_keyboard_buffer();
        while(input != 1 && input != 2 && input != 0)
        {
            printf("I'm sorry the input you gave was not valid: ");
            noc = scanf("%d", &input);
            clear_keyboard_buffer();
        }
        if(input == 1)
        {
            convert_lengths();
        }
        else if(input == 2)
        {
            convert_weights();
        }
        else if(input == 0)
        {
            return 0;
        }
    }
}

void convert_lengths(void)
{
    int input;
    int noc;
    printf("You have selected to convert lengths.\n");
    while(1)
    {
        printf("Do you want to convert feet/inches to meters/centimeters(1) or meters/centimeters to feet/inches(2)? Enter 0 to exit: ");
        noc = scanf("%d", &input);
        clear_keyboard_buffer();
        while(input != 1 && input != 2 && input != 0)
        {
            printf("I'm sorry the input you gave was not valid: ");
            noc = scanf("%d", &input);
            clear_keyboard_buffer();
        }
        if(input == 1)
        {
            length_to_metric();
        }
        else if(input == 2)
        {
            length_to_us();
        }
        else if(input == 0)
        {
            return;
        }
    }
}

void convert_weights(void)
{
    int input;
    int noc;
    printf("You have selected to convert weights.\n");
    while(1)
    {
        printf("Do you want to convert pounds/ounces to kilograms/grams(1) or kilograms/grams to pounds/ounces(2)? Enter 0 to exit: ");
        noc = scanf("%d", &input);
        clear_keyboard_buffer();
        while(input != 1 && input != 2 && input != 0)
        {
            printf("I'm sorry the input you gave was not valid: ");
            noc = scanf("%d", &input);
            clear_keyboard_buffer();
        }
        if(input == 1)
        {
            weight_to_metric();
        }
        else if(input == 2)
        {
            weight_to_us();
        }
        else if(input == 0)
        {
            return;
        }
    }
}

void length_to_us(void)
{
    //stub function
    printf("length to us\n");
}

void length_to_metric(void)
{
    //stub function
    printf("length to metric\n");
}

void weight_to_us(void)
{
    //stub function
    printf("weight to us\n");
}

void weight_to_metric(void)
{
    //stub function
    printf("weight to metric\n");
}

void clear_keyboard_buffer(void)
{
    char c;
    scanf("%c",&c);
    while(c != '\n')
    {
       scanf("%c",&c);
    }
}
