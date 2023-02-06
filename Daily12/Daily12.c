/*
 Author: Luke MacVicar
 Date: 10/27/22
 Purpose: This is a rocks paper scissors game, it reads in input from two users and returns the winner
 Time Spent: 1 hour
 */
#include <stdio.h>

void clear_keyboard_buffer(void);
char player1_input(void);
char player2_input(void);
void game(void);

int main(int argc, char * argv[]){
    int noc = 0;
    char play_again;
    game();
    printf("Would you like to play again?(y/n)");
    noc = scanf(" %c",&play_again);
    clear_keyboard_buffer();
    
    while(play_again != 'n' && play_again != 'N' && play_again != 'y' && play_again != 'Y' && noc != 0){
        printf("I'm sorry you must enter y or n.\n");
        printf("Would you like to play again?(y/n)");
        noc = scanf(" %c", &play_again);
        clear_keyboard_buffer();
    }
    
    while(play_again == 'Y' || play_again == 'y'){
        game();
        printf("Would you like to play again?(y/n)");
        noc = scanf(" %c",&play_again);
        clear_keyboard_buffer();
    }
    
    return 0;
}

// Checks the output of player1_input and player2_input then prints the winner of the game
void game(void){
    char player1;
    char player2;
    player1 = player1_input();
    player2 = player2_input();
    switch(player1){
        case 'r':
            if(player2 == 'r'){
                printf("You have tied!\n");
            }
            if(player2 == 'p'){
                printf("Player2 wins!\n");
            }
            if(player2 == 's'){
                printf("Player1 wins!\n");
            }
            break;
        case 'p':
            if(player2 == 'r'){
                printf("Player1 wins!\n");
            }
            if(player2 == 'p'){
                printf("You have tied!\n");
            }
            if(player2 == 's'){
                printf("Player2 wins!\n");
            }
            break;
        case 's':
            if(player2 == 'r'){
                printf("Player2 wins!\n");
            }
            if(player2 == 'p'){
                printf("Player1 wins!\n");
            }
            if(player2 == 's'){
                printf("You have tied!\n");
            }
            break;
    }
}

//Reads the input from player one and makes sure the output is correct
char player1_input(void){
    int noc = 0;
    char p1;
    printf("Player1 it is your turn!\n");
    printf("Please choose (r)ock, (p)aper, or (s)cissors: ");
    noc = scanf(" %c", &p1);
    clear_keyboard_buffer();
    
    while(p1 != 'r' && p1 != 'p' && p1 != 's' && p1 != 'R' && p1 != 'P' && p1 != 'S' && noc != 0){
        printf("I'm sorry you must enter r, p, or s.\n");
        printf("Please choose (r)ock, (p)aper, or (s)cissors: ");
        noc = scanf(" %c", &p1);
        clear_keyboard_buffer();
    }
    switch(p1)
    {
        case 'R':
        case 'r':
            p1 = 'r';
            break;
        case 'P':
        case 'p':
            p1 = 'p';
            break;
        case 'S':
        case 's':
            p1 = 's';
            break;
    }
    return p1;
}

//Reads the input from player two and makes sure the output is correct
char player2_input(void){
    int noc = 0;
    char p2;
    printf("Player2 it is your turn!\n");
    printf("Please choose (r)ock, (p)aper, or (s)cissors: ");
    noc = scanf(" %c", &p2);
    clear_keyboard_buffer();
    
    while(p2 != 'r' && p2 != 'p' && p2 != 's' && p2 != 'R' && p2 != 'P' && p2 != 'S' && noc != 0){
        printf("I'm sorry you must enter r, p, or s.\n");
        printf("Please choose (r)ock, (p)aper, or (s)cissors: ");
        noc = scanf(" %c", &p2);
        clear_keyboard_buffer();
    }
    switch(p2)
    {
        case 'R':
        case 'r':
            p2 = 'r';
            break;
        case 'P':
        case 'p':
            p2 = 'p';
            break;
        case 'S':
        case 's':
            p2 = 's';
            break;
    }
    return p2;
}

void clear_keyboard_buffer(void){
    char c;
    scanf("%c",&c);
    while(c != '\n')
    {
       scanf("%c",&c);
    }
}
