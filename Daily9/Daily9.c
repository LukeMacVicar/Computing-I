/***********************************************
 Author: Luke MacVicar
 Date: 10/19/22
 Answer to question: When you give this progam a large integer it will continue to work until it is done. This is different than daily 6 because we never reach stack overflow. The reason is we are only calling the function once, so we only put one thing on the stack. It will take a very long time but eventually it will complete the task. 
 ***********************************************/

#include<stdio.h>
int loop_down_to_zero(int x);
int loop_up_to_int(int x);

int main(int argc, char * argv[]){
    int x = 0;
    printf("Please enter a positive integer: ");
    scanf("%d",&x);
    printf("\n");
    loop_down_to_zero(x);
    printf("****\n");
    loop_up_to_int(x);
    return 0;
}

int loop_down_to_zero(int x){
    while(x >= 0){
        printf("%d\n",x);
        x--;
    }
    return x;
}

int loop_up_to_int(int x){
    int y = 0;
    while(y <= x){
        printf("%d\n",y);
        y++;
    }
    return x;
}
