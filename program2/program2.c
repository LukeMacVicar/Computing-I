/*
Author: Luke MacVicar
Date: November 27 2022
Purpose: This program uses fibinaci sequence to show growth over time. It takes in an initial size of population and a number of days for growth. It adds the previous two growth results to get the current one.
Time Spent: 2 hours
***********************************************/
#include <stdio.h>
/*
 -Preconditon: integers must be non negative
 -Postcondition: none
 */
void compute(int init_size, int num_days);
/*
 -Precondition: scanf must be called
 -Postcondition: none
 */
void clear_keyboard_buffer(void);

int main(int argc, char * argv[])
{
    int init_size;
    int num_days;
    int noc;
    char c = 'y';
    
    while(c == 'Y' || c == 'y')
    {
        printf("Enter an initial size of the green crud: ");
        noc = scanf("%d", &init_size);
        clear_keyboard_buffer();
        while(noc != 1 || init_size < 0)
        {
            printf("I'm sorry the input you gave was not valid. Please provide a non negative number: ");
            noc = scanf("%d", &init_size);
            clear_keyboard_buffer();
        }
        
        printf("Enter a number of days: ");
        noc = scanf("%d", &num_days);
        clear_keyboard_buffer();
        while(noc != 1 || num_days < 0)
        {
            printf("I'm sorry the input you gave was not valid. Please provide a non negative number: ");
            noc = scanf("%d", &num_days);
            clear_keyboard_buffer();
        }
        
        compute(init_size, num_days);
        
        printf("Would you like to continue?: ");
        noc = scanf("%c", &c);
        clear_keyboard_buffer();
        while(noc != 1 || (c != 'Y' && c != 'N'&& c != 'y' && c != 'n'))
        {
            printf("I'm sorry the input you gave was not valid. Please provide a Y or N: ");
            noc = scanf("%c", &c);
            clear_keyboard_buffer();
        }
    }
    return 0;
}

void compute(int init_size, int num_days)
{
    int i;
    int first_size = init_size;
    int second_size = first_size;
    int result = first_size + second_size;
    
    if(num_days < 10)
    {
        printf("With an initial size of %d, and %d number of days. The final result is %d pounds.\n", init_size, num_days, first_size);
    }
    else if(num_days == 10)
    {
        result = first_size + second_size;
        printf("With an initial size of %d, and %d number of days. The final result is %d pounds.\n", init_size, num_days, result);
    }
    else
    {
        for(i = 11; i <= num_days; i++)
            {
                int temp;
                if(i % 5 == 0 && i != 0){
                    temp = second_size;
                    second_size = result;
                    first_size = temp;
                    result = first_size + second_size;
                }
                if(i == num_days)
                {
                    printf("With an initial size of %d, and %d number of days. The final result is %d pounds.\n", init_size, num_days, result);
                }
            }
    }
}

void clear_keyboard_buffer(void){
    char c;
    scanf("%c",&c);
    while(c != '\n')
    {
       scanf("%c",&c);
    }
}
