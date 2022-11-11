#ifndef GAME_UTILS_H
#define GAME_UTILS_H
#include <stdbool.h>

void show_Menu(void);
void print_CrapsHelp(char needHelp);
void print_HlHelp(char needHelp);
void str_Guess(int machineGuess);
void print_Endgame(int playerPoints, int machinePoints);

int generate_Randno1(int limit);
int generate_Randno2(int limit);
int rps_Result(int playerGuess, int machineGuess);
int craps_Result(int playerGuess, int sum, int limit, int dice1, int dice2); 

bool rematch(char newRound, int playerPoints, int machinePoints);

#endif
