/***********************************************
 Author: Luke MacVicar
 Date: November 27 2022
 Purpose: This program reads two files and sorts their contents into a third file numbers in order of smallest to largest.
Sources of Help: github perror to see the specific file error
Time Spent: 2 hours
***********************************************/
#include <stdio.h>
/*
 -Precondition: None
 -Postcondition: Needs to return something from the file
 */
int read_file1(int counter, char* file_name);
/*
 -Precondition: None
 -Postcondition: Needs to return something from the file
 */
int read_file2(int counter, char* file_name);
/*
 -Precondition: None
 -Postcondition: None
 */
int write_to_file(int num1, int num2, char* file_name);

int main(int argc, char * argv[])
{
    int counter1 = 0;
    int counter2 = 0;
    int num_file1;
    int num_file2;
    int return_counter;
    
    char* numbers1 = "/Users/lukemacvicar/Desktop/c projects/Daily17/numbers1.txt";
    char* numbers2 = "/Users/lukemacvicar/Desktop/c projects/Daily17/numbers2.txt";
    char* output3 = "/Users/lukemacvicar/Desktop/c projects/Daily17/output3.txt";
    
    num_file1 = read_file1(counter1, numbers1);
    num_file2 = read_file2(counter2, numbers2);
    return_counter = write_to_file(num_file1, num_file2, output3);
    
    while((num_file1 != -1 || num_file2 != -1) && return_counter != -1){
        if(return_counter == 0 || num_file2 == -1)
        {
            counter1++;
        }
        else if(return_counter == 1 || num_file1 == -1)
        {
            counter2++;
        }
       
        num_file1 = read_file1(counter1, numbers1);
        num_file2 = read_file2(counter2, numbers2);
        return_counter = write_to_file(num_file1, num_file2, output3);
    }
    return 0;
}

int read_file1(int place_holder1, char* file_name)
{
    FILE *fp1;
    int num;
    int noc;
    int counter = 0;
    fp1 = fopen(file_name, "r");
    
    if(fp1 == NULL){
        perror("Error");
    }

    noc = fscanf(fp1, "%d", &num);
    while(noc != 1)
    {
        printf("failed to read\n");
    }
    
    while(noc == 1 && !feof(fp1))
    {
        if(counter == place_holder1)
        {
            return num;
        }
        counter++;
        noc = fscanf(fp1, "%d", &num);
    }
    
    fclose(fp1);
    return -1;
}

int read_file2(int place_holder2, char* file_name)
{
    FILE *fp2;
    int num;
    int noc;
    int counter = 0;
    fp2 = fopen(file_name, "r");
    
    if(fp2 == NULL){
        perror("Error");
    }

    noc = fscanf(fp2, "%d", &num);
    while(noc != 1)
    {
        printf("failed to read\n");
    }
    
    while(noc == 1 && !feof(fp2))
    {
        if(counter == place_holder2)
        {
            return num;
        }
        counter++;
        noc = fscanf(fp2, "%d", &num);
    }
    
    fclose(fp2);
    return -1;
}

int write_to_file(int num1, int num2, char* file_name)
{
    FILE *fp3;
    fp3 = fopen(file_name, "a");
    
    if(fp3 == NULL){
        perror("Error");
    }

    if(num1 == -1 && num2 != -1)
    {
        fprintf(fp3, "%d\n", num2);
        fclose(fp3);
        return 1;
    }
    else if(num1 != -1 && num2 == -1)
    {
        fprintf(fp3, "%d\n", num1);
        fclose(fp3);
        return 0;
    }
  
    if(num1 < num2)
    {
        fprintf(fp3, "%d\n", num1);
        fclose(fp3);
        return 0;
    }
    else if(num1 > num2)
    {
        fprintf(fp3, "%d\n", num2);
        fclose(fp3);
        return 1;
    }
    
    return -1;
}
