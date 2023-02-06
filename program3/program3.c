#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//precondition: Must have a file that is formated correctly. If it is not you will reciceve errors
//postcondtion: None
void get_full_name(FILE* fp, int size, char* file_name);

//precondition: Must have a file that is formated correctly. If it is not you will reciceve errors
//postcondtion: None
void get_average(FILE* fp, int size, char* file_name);

#define SIZE (15)

int main(int argc, char * argv[])
{
    char* file_name_quiz = "/Users/lukemacvicar/Desktop/c projects/program3/quiz.txt";
    char* file_name_average = "/Users/lukemacvicar/Desktop/c projects/program3/average.txt";
    
    FILE* fp;
    fp = fopen(file_name_quiz, "r");

    if(fp == NULL){
        perror("Error");
    }
    for(int i = 0; i < 10; i++)
    {
        get_full_name(fp, 15, file_name_average);
        get_average(fp, 15, file_name_average);
    }

    fclose(fp);
    
    FILE* average;
    average = fopen(file_name_average, "r");

    if(average == NULL){
        perror("Error");
    }
    
    FILE* quiz;
    quiz = fopen(file_name_quiz, "w");

    if(quiz == NULL){
        perror("Error");
    }
    
    char c;
    int noc;
    
    noc = fscanf(average, "%c", &c);
    if (noc == EOF)
    {
        if (noc == 1)
        {
            ungetc(c, average);
        }
    }
    
    noc = fscanf(average, "%c", &c);
    while (noc == 1)
    {
        fprintf(quiz,"%c",c);
        noc = fscanf(average, "%c", &c);
    }
    if (noc == 1)
    {
        ungetc(c, average);
    }

    fclose(quiz);
    fclose(average);
    return 0;
}

void get_full_name(FILE* fp, int size, char* file_name)
{
    char first_name[SIZE];
    char last_name[SIZE];

    int noc;
    char c;
    int i = 0;

    noc = fscanf(fp, " %c", &c);
    if(noc != 1 || size < 2)
    {
        if(noc == 1)
        {
            ungetc(c, fp);
        }
        printf("failed to read\n");
    }

    first_name[i] = c;
    i++;

    noc = fscanf(fp, "%c", &c);
    while(noc == 1 && !isspace(c) && i < size - 1)
    {
        first_name[i] = c;
        i++;
        noc = fscanf(fp, "%c", &c);
    }

    if(noc == 1)
    {
        ungetc(c, fp);
    }

    first_name[i] = '\0';

    i = 0;

    noc = fscanf(fp, " %c", &c);
    if(noc != 1 || size < 2)
    {
        if(noc == 1)
        {
            ungetc(c, fp);
        }
        printf("failed to read\n");
    }

    last_name[i] = c;
    i++;

    noc = fscanf(fp, "%c", &c);
    while(noc == 1 && !isspace(c) && i < size - 1)
    {
        last_name[i] = c;
        i++;
        noc = fscanf(fp, "%c", &c);
    }

    if(noc == 1)
    {
        ungetc(c, fp);
    }

    last_name[i] = '\0';

    FILE* fp1;
    fp1 = fopen(file_name, "a");

    if(fp == NULL){
        perror("Error");
    }

    fprintf(fp1,"%s, %-20s", last_name, first_name);

    fclose(fp1);

}

void get_average(FILE* fp, int size, char* file_name)
{
    int quiz_score[10];
    int noc;
    char c;
    int x = 0;
    int i = 0;
    int average = 0;

    noc = fscanf(fp, " %c", &c);
    if (noc == EOF || size < 2)
    {
        if (noc == 1)
        {
            ungetc(c, fp);
        }
        printf("FAILED");
    }
    
    FILE* fp1;
    fp1 = fopen(file_name, "a");

    if(fp == NULL){
        perror("Error");
    }
    
    
    ungetc(c, fp);
    quiz_score[i] = x;
    noc = fscanf(fp, "%d", &x);
    while (noc == 1 && i < size - 1)
    {
        if (isdigit(c))
        {
            quiz_score[i] = x;
            fprintf(fp1, "%4d ", quiz_score[i]);
            noc = fscanf(fp, "%d", &x);
            i++;
        }
    }
    
    if(noc == 1)
    {
        ungetc(c, fp);
    }
    for(int z = 0; z < i-1; z++)
    {
        average = quiz_score[z] + average;
    }
    while (i < 10)
    {
        fprintf(fp1, "%4d ", 0);
        i++;
    }

    average = average / 10;

    fprintf(fp1,"%10d\n",average);

    fclose(fp1);
}
