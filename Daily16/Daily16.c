/***********************************************
 Program: Final iteration
 Author: Luke MacVicar
 Date: November 27 2022
 Purpose: This program prompts the user to see if they want to convert wieghts or lengths. Then the program calls a function based on the user input.
Sources of Help: none
Time Spent: 30 mins
***********************************************/
#include <stdio.h>
/*
 -Precondition: None
 -Postcondition: Convert mesurements into proper unit
 */
void convert_lengths(void);
/*
 -Precondition: None
 -Postcondition: Convert measurements into proper unit
 */
void convert_weights(void);
/*
 -Precondition: mesurements must be in metric
 -Postcondition: convert mesurements into proper unit
 */
void length_to_us(void);
/*
 -Precondition: mesurements must be in us
 -Postcondition: convert mesurements into proper unit
 */
void length_to_metric(void);
/*
 -Precondition: mesurements must be in metric
 -Postcondition: convert mesurements into proper unit
 */
void weight_to_us(void);
/*
 -Precondition: mesurements must be in us
 -Postcondition: convert mesurements into proper unit
 */
void weight_to_metric(void);
/*
 -Precondition: scanf must be used
 -Postcondition: none
 */
void clear_keyboard_buffer(void);
/*
 -Precondition: None
 -Postcondition: users input must be valid
 */
void length_to_us_input(double *length);
/*
 -Precondition: measurements must be in proper range, positive
 -Postcondition: measurements must be converted
 */
void length_to_us_conversion(double *length, double *converted);
/*
 -Precondition: Must have something to output
 -Postcondition: none
 */
void length_to_us_output(double *length, double *converted);
/*
 -Precondition: None
 -Postcondition: users input must be valid
 */
void length_to_metric_input(double *length);
/*
 -Precondition: measurements must be in proper range, positive
 -Postcondition: measurements must be converted
 */
void length_to_metric_conversion(double *length, double *converted);
/*
 -Precondition: Must have something to output
 -Postcondition: none
 */
void length_to_metric_output(double *length, double *converted);
/*
 -Precondition: None
 -Postcondition: users input must be valid
 */
void weight_to_us_input(double *weight);
/*
 -Precondition: measurements must be in proper range, positive
 -Postcondition: measurements must be converted
 */
void weight_to_us_conversion(double *weight, double *converted);
/*
 -Precondition: Must have something to output
 -Postcondition: none
 */
void weight_to_us_output(double *weight, double *converted);
/*
 -Precondition: None
 -Postcondition: users input must be valid
 */
void weight_to_metric_input(double *weight);
/*
 -Precondition: measurements must be in proper range, positive
 -Postcondition: measurements must be converted
 */
void weight_to_metric_conversion(double *weight, double *converted);
/*
 -Precondition: Must have something to output
 -Postcondition: none
 */
void weight_to_metric_output(double *weight, double *converted);

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

void length_to_us(void)
{
    double length = 0.0;
    double *plength = &length;
    double converted = 0.0;
    double *pconverted = &converted;

    printf("length to us\n");
    length_to_us_input(plength);
    length_to_us_conversion(plength, pconverted);
    length_to_us_output(plength, pconverted);
}

void length_to_us_output(double *length, double *converted)
{
    printf("%lf centimeters is %lf inches.\n", *length, *converted);
}

void length_to_us_conversion(double *length, double *converted)
{
    *converted = *length * 0.3048;
}

void length_to_us_input(double *length)
{
    double input;
    int noc;
    printf("You have selected to convert from meters/centimeters to feet/inches.\n");
    printf("Enter a distance in centimeters: ");
    noc = scanf("%lf", &input);
    clear_keyboard_buffer();
    while(noc != 1 && input < 0)
    {
        printf("I'm sorry the input you gave was not valid: ");
        noc = scanf("%lf", &input);
        clear_keyboard_buffer();
    }
    *length = input;
}

void length_to_metric(void)
{
    double length = 0.0;
    double *plength = &length;
    double converted = 0.0;
    double *pconverted = &converted;

    printf("length to metric\n");
    length_to_metric_input(plength);
    length_to_metric_conversion(plength, pconverted);
    length_to_metric_output(plength, pconverted);
}

void length_to_metric_output(double *length, double *converted)
{
    printf("%lf inches is %lf centimeters.\n", *length, *converted);
}


void length_to_metric_conversion(double *length, double *converted)
{
    *converted = *length / .3048;
}

void length_to_metric_input(double *length)
{
    double input;
    int noc;
    printf("You have selected to convert from feet/inches to meters/centimeters.\n");
    printf("Enter a distance in inches: ");
    noc = scanf("%lf", &input);
    clear_keyboard_buffer();
    while(noc != 1 && input < 0)
    {
        printf("I'm sorry the input you gave was not valid: ");
        noc = scanf("%lf", &input);
        clear_keyboard_buffer();
    }
    *length = input;
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

void weight_to_us(void)
{
    double weight = 0.0;
    double *pweight = &weight;
    double converted = 0.0;
    double *pconverted = &converted;

    printf("weight to us\n");
    weight_to_us_input(pweight);
    weight_to_us_conversion(pweight, pconverted);
    weight_to_us_output(pweight, pconverted);
}

void weight_to_us_output(double *weight, double *converted)
{
    printf("%lf grams is %lf ounces.\n", *weight, *converted);
}

void weight_to_us_conversion(double *weight, double *converted)
{
    *converted = ((*weight / 1000) * 2.2046) * 16;
}

void weight_to_us_input(double *weight)
{
    double input;
    int noc;
    printf("You have selected to convert from kilograms/grams to pounds/ounces.\n");
    printf("Enter a weight in grams: ");
    noc = scanf("%lf", &input);
    clear_keyboard_buffer();
    while(noc != 1 && input < 0)
    {
        printf("I'm sorry the input you gave was not valid: ");
        noc = scanf("%lf", &input);
        clear_keyboard_buffer();
    }
    *weight = input;
}

void weight_to_metric(void)
{
    double weight = 0.0;
    double *pweight = &weight;
    double converted = 0.0;
    double *pconverted = &converted;

    printf("weight to metric\n");
    weight_to_metric_input(pweight);
    weight_to_metric_conversion(pweight, pconverted);
    weight_to_metric_output(pweight, pconverted);
}

void weight_to_metric_output(double *weight, double *converted)
{
    printf("%lf ounces is %lf grams.\n", *weight, *converted);
}


void weight_to_metric_conversion(double *weight, double *converted)
{
    *converted = ((*weight / 16) / 2.2046) * 1000;
}

void weight_to_metric_input(double *weight)
{
    double input;
    int noc;
    printf("You have selected to convert from pounds/ounces to kilgrams/grams.\n");
    printf("Enter a weight in ounces: ");
    noc = scanf("%lf", &input);
    clear_keyboard_buffer();
    while(noc != 1 && input < 0)
    {
        printf("I'm sorry the input you gave was not valid: ");
        noc = scanf("%lf", &input);
        clear_keyboard_buffer();
    }
    *weight = input;
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
