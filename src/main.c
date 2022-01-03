#include "game_utils.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    char gameChoice, newRound, needHelp, guess;
    int limit = 0, result, playerGuess, machineGuess;
    bool continuePlay = true;
    int playerPoints = 0, machinePoints = 0;

    // Implements menu
    show_Menu();
    scanf("%s", &gameChoice);

    //Validates menu, refer to readme.md for credits
    for (;;)
    {
        if (strcmp(&gameChoice,"1")==0 || strcmp(&gameChoice,"2")==0 || strcmp(&gameChoice,"3" )==0)
        {
            break;
        }
        else
        {
            printf("Invalid option. Enter only numbers of 1, 2 or 3.\nWhat is your choice? ");
            scanf("%s", &gameChoice);
        }
    }
    
    //checks that only games in menu are selected
    for (;;)
    {
        if (isdigit(gameChoice))
        {
            break;
        }
        else
        {
            printf("Invalid option. Enter only numbers of 1, 2 or 3.\nWhat is your choice? ");
            scanf("%s", &gameChoice);
        }
    }
    

    // Implements high low game
    if (strcmp(&gameChoice, "1")==0)
    {
        printf("You are playing: High Low.\n");
        char hlOption;
        int hint, actual;
        const int incrementStd = 1, incrementJPot = 5; 
        limit = 100;
        
        //prompts players if they need help
        printf("Do you need help? Y/N: ");
        scanf("%s", &needHelp);
        needHelp = toupper(needHelp);
        if (strcmp(&needHelp, "Y")==0)
        {
            print_HlHelp(needHelp);
        }

        //implements actual game
         while (continuePlay == true)
        {
            //generates numbers needed for game
            hint = generate_Randno1(limit);
            actual = generate_Randno2(limit);
            hint = round(hint);
            printf("Hint: %d\n", hint);
            
            //get players to guess numbers
            printf("What is your guess? \nEnter H for high, L for low or J for Jackpot: ");
            scanf("%s", &hlOption);
            
            //validates guesses
            hlOption = toupper(hlOption);
            for (;;)
            {
                if (strcmp(&hlOption, "H")==0 || strcmp(&hlOption,"L")==0 || strcmp(&hlOption,"J")==0)
                {
                    break;
                }
                else
                {
                    printf("Invalid guess. Enter only H, L, or J.\nWhat is your guess? ");
                    scanf("%s", &hlOption);
                    hlOption = toupper(hlOption);
                }
            }
            
            // checks guesses if they are correct
            if ((strcmp(&hlOption, "H")==0 && actual > hint) || (strcmp(&hlOption,"L")==0 && actual < hint))
            {
                printf("Your guess is correct! The answer is: %d\n", actual);
                playerPoints += incrementStd;
            }
            else 
            {
                if (strcmp(&hlOption,"J")==0 && actual == hint)
                {
                    printf("Your guess is correct! The answer is: %d\n", actual);
                    playerPoints += incrementJPot;
                }
                else
                {
                     printf("Your guess is incorrect. The answer is: %d\n", actual);
                     machinePoints += incrementStd;
                }
            }
            
            //asks users if they want replay
            printf("New round? Y/N: ");
            scanf("%s", &newRound);
            newRound = toupper(newRound);
            continuePlay=rematch(newRound); 
        }
        print_Endgame(playerPoints, machinePoints);
    }

    //Implements Rock Paper Scissors game
    if (strcmp(&gameChoice, "2")==0)
    {
        limit = 3;
        printf("You are playing: Rock Paper Scissors.\n");
        printf("\t1. Rock \n\t2. Paper \n\t3. Scissors\n");
        while (continuePlay == true)
        {
            printf("Enter one of the above index numbers. e.g. 1 is to play 'Rock'.\n");
            printf("What is your guess? ");
            scanf("%s", &guess);
            for (;;)
            {
                if (strcmp(&guess, "1")==0 || strcmp(&guess,"2")==0 || strcmp(&guess,"3")==0)
                {
                    break;
                }
                else
                {
                    printf("Invalid guess. Enter only 1, 2 or 3.\nWhat is your guess? ");
                    scanf("%s", &guess);
                }
            }
            playerGuess = atoi(&guess);
            machineGuess = generate_Randno1(limit);
            machineGuess += 1; 
            
            //show result
            result = rps_Result(playerGuess, machineGuess);
            if (result == 1)
            {
                playerPoints += 1;
            }
            else 
            {
                if (result == 0)
                {
                    machinePoints += 1;
                }
                else
                {
                    printf("No points won by either you or program.\n");
                }
            }
            
            // new round
            printf("New round? Enter Y for yes: ");
            scanf("%s", &newRound);
            newRound = toupper(newRound);
            continuePlay = rematch(newRound);
        }
        print_Endgame(playerPoints, machinePoints);
    }
    
    if (strcmp(&gameChoice, "3")==0)
    {
        int dice1 = 0, dice2 = 0, sum, sum1, sum2;
        limit = 6;
        bool win;
        printf("You are playing: Craps\n");
        printf("Do you need help? Y/N: ");
        scanf("%s", &needHelp);
        needHelp = toupper(needHelp);
        if (strcmp(&needHelp, "Y")==0)
        {
            print_CrapsHelp(needHelp);
        }
        while (continuePlay == true)
        {
            printf("\t1. Pass\n\t2. Don't pass\nWhat is your guess?\nEnter 1 or 2: ");
            scanf("%s", &guess);
            for (;;)
            {
                if (strcmp(&guess, "1")==0 || strcmp(&guess,"2")==0)
                {
                    break;
                }
                else
                {
                    printf("Invalid guess. Enter only 1 or 2.\nWhat is your guess? ");
                    scanf("%s", &guess);
                }
            }
            playerGuess = atoi(&guess);
            dice1 = generate_Randno1(limit);
            dice1 += 1;
            dice2 = generate_Randno2(limit);
            dice2 += 1;
            printf("Dice 1: %d\n", dice1);
            printf("Dice 2: %d\n", dice2);
            sum = dice1 + dice2;
            result = craps_Result(playerGuess, sum, limit, dice1, dice2);
            switch (result)
            {
                case 1:
                playerPoints += 1;
            
                case 0:
                machinePoints += 1;
            }
            printf("New round? Enter Y for yes: ");
            scanf("%s", &newRound);
            newRound = toupper(newRound);
            continuePlay = rematch(newRound);
        }
        print_Endgame(playerPoints, machinePoints);
    }
}
