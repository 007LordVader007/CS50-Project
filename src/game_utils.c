#include "game_utils.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

void show_Menu()
{
    printf("Welcome! \n ");
    printf("Game options:\n\t1. High Low\n\t2. Rock Paper Scissors\n\t3. Craps\n");
    printf("Enter a game, using its index no.\ne.g. High Low's index no. is 1.\nWhat is your choice? ");
}

void print_CrapsHelp(char needHelp)
{
    printf("2, 3, 12: \n\t-Pass loses\n\t-Don't Pass wins (Draw on 12)\n");
    printf("7, 11: \n\t-Pass wins\n\t-Don't Pass loses\n");
    printf("All other numbers need a repeat before 7 for Pass to win.\n");
    printf("E.g. 8 rolled, another 8 must come before 7.\n");
    printf("Full rules here: https://en.wikipedia.org/wiki/Craps#Rules_of_play\n");
}

void print_HlHelp(char needHelp)
{  
    printf("High: Your guess > Given number\n");
    printf("Low: Your guess < Given number\n");
    printf("Jackpot: Your guess = Given number\n");
}

void str_Guess(machineGuess)
{
    printf("Machine played: ");
    if (machineGuess == 1)
    {
        printf("Rock\n");
    }
    else
    {
        if (machineGuess == 2)
        {
            printf("Paper\n");
        }
        else
        {
            printf("Scissors \n");
        }
        
    }
}

void print_Endgame(playerPoints, machinePoints)
{
    printf("Final score:\nYou: %d, Program: %d\n", playerPoints, machinePoints);
    printf("Good game! \nGame ending...\n");
}

int generate_Randno1(limit)
{
    srand(time(NULL));
    int no = (rand() / ((double) RAND_MAX + 1)) * limit;
    no = round(no);
    return no;
}

int generate_Randno2(limit)
{
    int no1 = rand() % limit;
    no1 = round(no1);
    return no1;
}

int rps_Result(playerGuess, machineGuess)
{
    int pPoints = 0, mPoints = 0, tie = 0;
    if ((playerGuess < 1) || (playerGuess > 3))
    {
        printf("Invalid input. Neither wins. \nEnter only 1, 2 or 3.\n");
        return 0;
    }
    // player gives valid input
    else
    {
        if ((playerGuess - machineGuess == 1) || (playerGuess - machineGuess == -2))
        {
            printf("You won!\n");
            str_Guess(machineGuess);
            return 1;
        }
        else
        {
            if (playerGuess == machineGuess)
            {   
                printf("Draw. \n");
                str_Guess(machineGuess);
                return 2;
            }
            else
            {
                printf("You lost. \n");
                str_Guess(machineGuess);
                return 0;
            }
        }
    }
}

int craps_Result(playerGuess, sum, limit, dice1, dice2)
{
    if (sum == 2 || sum == 3 || sum == 12)
    {
        if (playerGuess == 1)
        {
            printf("You lost.\n");
            return 0;
        }
        else
        {
            if (sum == 12)
            {
                printf("Draw.\n");
                return 2;
            }
            else
            {
                printf("You won.\n");  
                return 1;
            }
        }
    }
    else
    {
        if (sum == 7 || sum == 11)
        {
            if (playerGuess == 1)
            {
                printf("You won.\n");
                return 1;
            }
            else
            {
                printf("You lost.\n");
                return 0;
            }
        }
        else
        {
            int sum2 = -1, dice3 = 0, dice4 = 0; 
            while (sum2 != sum && sum2 != 7) 
            {
                printf("Rolling again...\n");
                dice3 = rand() %limit;
                dice3 += 1;
                printf("Dice 1: %d\n", dice3);
                dice4 = rand() %limit;
                dice4 += 1;
                printf("Dice 2: %d\n", dice4);
                sum2 = dice3 + dice4;
            }
            if (sum2 == sum)
            {
                if (playerGuess == 1)
                {
                    printf("You won.\n");
                    return 1;
                }
                else
                {
                    printf("You lost.\n");
                    return 0;
                }
            }
            else
            {
                if (playerGuess == 2)
                {
                    printf("You won.\n");
                    return 1;
                }
                else
                {
                    printf("You lost.\n");
                    return 0;
                }
            }
        }
    }
    return 0; 
}
   
bool rematch(char newRound)
{
    if (strcmp(&newRound, "N")==0)
    {
        return false;
    }
    return true;
}
