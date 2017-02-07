/*
	*	
	*		Justin Harper 
	*		PA6 - Battleship
	*		Version 0.1
	*
    */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define SIZE 10
#define SHIPS 5




void battleShip (void);

void startGame(char p1Boats[SIZE] [SIZE], char p1Shots [SIZE][SIZE], char p2Boats[SIZE] [SIZE], char p2Shots[SIZE] [SIZE]);

void getCoord(char shots [SIZE] [SIZE], char boats [SIZE] [SIZE]);

void printBoard (char board [SIZE] [SIZE]);

void placeShips (char board [SIZE][SIZE]);

int menu (void);

void placeCarrier(char board [SIZE] [SIZE]);

void placeCruser (char board [SIZE] [SIZE]);

void placeBattleship(char board [SIZE] [SIZE]);

void placeSubmarine(char board [SIZE] [SIZE]);

void placeDestroyer(char board [SIZE] [SIZE]);

int checkIfPlaceable (char board[SIZE] [SIZE], int dir, int size, int x, int y);

void playGame(char p1Boats[SIZE] [SIZE], char p1Shots [SIZE][SIZE], char p2Boats[SIZE] [SIZE], char p2Shots[SIZE] [SIZE], int player);

void player1 (char p1Shots [SIZE][SIZE], char p2Boats[SIZE] [SIZE]);

void player2 (char p2Shots [SIZE][SIZE], char p1Boats[SIZE] [SIZE]);

int checkWinner(char boats [SIZE] [SIZE]);

void gameWinner (int player);

void taunght (int loser);