   /*
	*	
	*		Justin Harper 
	*		PA6 - Battleship
	*		Version 0.1
	*
    */





#include "pa6.h"





void battleShip (void)//initilizes the board arrays and starts the game
{
	
	

	int x = 0, y=0, choice = 0;
	
	char p1Shots [SIZE][SIZE] = {
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'}
								  };




	char p1Boats[SIZE] [SIZE] = {
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'}
								  };

	
	
	char p2Shots[SIZE] [SIZE] = {
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'}
								  };

	char p2Boats[SIZE] [SIZE] = {
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
								{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'}
								  };

	fclose(fopen("output.txt", "w")); // emptys the file for each run


	choice = menu();

	system("cls");

	switch (choice)
	{
	case 1: startGame(p1Boats, p1Shots, p2Boats, p2Shots);
		break;
	case 0: return;

	}
	

	


	return;
}

int menu (void)//display the menu to start the game
{
	int choice = 0;

	printf("Hello! Welcome to BATTLESHIP\n");
	printf("Please choose from the following list of options\n");
	printf("1) play game\n");
	

	printf("0) exit\n");

	scanf(" %d", &choice);

	return choice;



}

void startGame(char p1Boats[SIZE] [SIZE], char p1Shots [SIZE][SIZE], char p2Boats[SIZE] [SIZE], char p2Shots[SIZE] [SIZE])//starts the place ships process as well as determins who goes first
{
	int whoGoesFirst = 0;
	
	printf("player 1 please press any key to place your ships\n");
	system("pause");
	placeShips(p1Boats);

	printf("player 1 boats placed...press any key to hand off to player 2\n");

	system("pause");
	system("cls");

	printf("player 2, please press any key to place your ships\n");
	system("pause");

	placeShips(p2Boats);

	printf("player 2 boats placed....FIGHT!\n");
	system("pause");
	system("cls");

	whoGoesFirst = rand() % 2 + 1;

	playGame (p1Boats, p1Shots, p2Boats, p2Shots, whoGoesFirst);

	return;
}


void printBoard (char board [SIZE][SIZE])//prints the board to the console as well as a file 
{
	FILE * output = NULL;
	

	int i = 0, j = 0;

	output = fopen("output.txt", "a");

	printf("    0 1 2 3 4 5 6 7 8 9 \n\n");
	fprintf(output, "    0 1 2 3 4 5 6 7 8 9 \n\n");

	for(i=0; i<10; i++)
	{

		printf("%2d  ", i);
		fprintf(output, "%2d  ", i);

		for(j=0; j<10; j++)
		{
			printf("%c ", board[i][j]);
			fprintf(output, "%c ", board[i][j]);
		}
				
		printf("\n\n");
		fprintf(output, "\n\n");
	}

		fprintf(output, "\n    ---------------------\n\n");


	fclose(output);
	return;
}

void getCoord(char shots [SIZE] [SIZE], char boats [SIZE] [SIZE]) //gets input coords and checks to see if the coords are a hit or not...also checks if the coords have been shot yet
{
	int xTemp = 0;
	int yTemp = 0;
	int redo = 1;

	while (redo)
	{
		printBoard(shots);


		printf("please enter coords to shoot; x y\n");
		scanf(" %d %d", &xTemp, &yTemp);
		if(shots [yTemp] [xTemp] == '~')
		{
			redo = 0;
			if(boats [yTemp] [xTemp] != '~')
			{//hit
				shots [yTemp] [xTemp] = 'X';
				boats [yTemp] [xTemp] = 'X';
			}
			else
			{
				shots [yTemp] [xTemp] = 'M';
			}

		}
		else
		{
			printf("already shot here! please try again\n");
			system("pause");
			system("cls");
		}
	}
	system("cls");
	return;
}

void placeShips (char board [SIZE][SIZE]) // calls the place funcions and prints the board at the end
{
	placeCarrier(board); //5

	placeCruser(board); //3

	placeBattleship(board); //4

	placeSubmarine(board); //3

	placeDestroyer(board); //2

	printBoard(board);
	
	return;
}

void placeCarrier(char board [SIZE] [SIZE])//gets input and places ship
{
	int ship = 5;
	int x = 0, y = 0, dir = 0, error = 0, count = 0, temp = 0;;
	
	do
	{
	printf("Player please place the Carrier on the board\nNote Carrier = %d units\n", ship);
	printBoard(board);
	
	printf("please enter top / left coordinate: x y\n");
	scanf(" %d %d", &x , &y);
	printf("please enter direction -1 for vertical, 1 for horizantal:\n");
	scanf(" %d", &dir);

	if(dir == 1 && x > SIZE - ship)
	{
		system("cls");
		printf("error please try again (horizantal error)\n");
		error = 1;
	}

	if(dir == -1 && y > SIZE - ship)
	{
		system("cls");
		printf("error please try again (vertical error)\n");
		error = 1;
	}

	if(checkIfPlaceable(board, dir, ship, x, y) != 0)
	{
		system("cls");
		printf("placeable error\n");
		error = 1;
	}

	}
	
	while(error);

	while (count < ship)
	{
		if( dir == 1)
		{
			board[y][x + temp] = 'c';
			temp++;
		}
		else
		{
			board[y + temp] [x] = 'c';
			temp++;
		}

		count++;


	}
	printf("sucsess!");
	system("pause");
	system("cls");
	return;
}

void placeCruser(char board [SIZE] [SIZE])//gets input and places ship
{
	int ship = 3;
	int x = 0, y = 0, dir = 0, error = 0, count = 0, temp = 0;;
	
	do
	{
	printf("Player please place the Cruser on the board\nNote Cruser = %d units\n", ship);
	printBoard(board);
	
	printf("please enter top / left coordinate: x y\n");
	scanf(" %d %d", &x , &y);
	printf("please enter direction -1 for vertical, 1 for horizantal:\n");
	scanf(" %d", &dir);

	if(dir == 1 && x > SIZE - ship)
	{
		system("cls");
		printf("error please try again (horizantal error)\n");
		error = 1;
	}

	if(dir == -1 && y > SIZE - ship)
	{
		system("cls");
		printf("error please try again (vertical error)\n");
		error = 1;
	}

	if(checkIfPlaceable(board, dir, ship, x, y) != 0)
	{
		system("cls");
		printf("placeable error\n");
		error = 1;
	}

	}
	
	while(error);

	while (count < ship)
	{
		if( dir == 1)
		{
			board[y][x + temp] = 'r';
			temp++;
		}
		else
		{
			board[y + temp] [x] = 'r';
			temp++;
		}

		count++;


	}
	printf("sucsess!");
	system("pause");
	system("cls");
	return;
}

void placeBattleship(char board [SIZE] [SIZE])//gets input and places ship
{
	int ship = 4;
	int x = 0, y = 0, dir = 0, error = 0, count = 0, temp = 0;;
	
	do
	{
	printf("Player please place the Battleship on the board\nNote Battleship = %d units\n", ship);
	printBoard(board);
	
	printf("please enter top / left coordinate: x y\n");
	scanf(" %d %d", &x , &y);
	printf("please enter direction -1 for vertical, 1 for horizantal:\n");
	scanf(" %d", &dir);

	if(dir == 1 && x > SIZE - ship)
	{
		system("cls");
		printf("error please try again (horizantal error)\n");
		error = 1;
	}

	if(dir == -1 && y > SIZE - ship)
	{
		system("cls");
		printf("error please try again (vertical error)\n");
		error = 1;
	}

	if(checkIfPlaceable(board, dir, ship, x, y) != 0)
	{
		system("cls");
		printf("placeable error\n");
		error = 1;
	}

	}
	
	while(error);

	while (count < ship)
	{
		if( dir == 1)
		{
			board[y][x + temp] = 'b';
			temp++;
		}
		else
		{
			board[y + temp][x] = 'b';
			temp++;
		}

		count++;


	}
	printf("sucsess!");
	system("pause");
	system("cls");
	return;
}

void placeSubmarine(char board [SIZE] [SIZE])//gets input and places ship
{
	int ship = 3;
	int x = 0, y = 0, dir = 0, error = 0, count = 0, temp = 0;;
	
	do
	{
	printf("Player please place the Submarine on the board\nNote Submarine = %d units\n", ship);
	printBoard(board);
	
	printf("please enter top / left coordinate: x y\n");
	scanf(" %d %d", &x , &y);
	printf("please enter direction -1 for vertical, 1 for horizantal:\n");
	scanf(" %d", &dir);

	if(dir == 1 && x > SIZE - ship)
	{
		system("cls");
		printf("error please try again (horizantal error)\n");
		error = 1;
	}

	if(dir == -1 && y > SIZE - ship)
	{
		system("cls");
		printf("error please try again (vertical error)\n");
		error = 1;
	}

	if(checkIfPlaceable(board, dir, ship, x, y) != 0)
	{
		system("cls");
		printf("placeable error\n");
		error = 1;
	}

	}
	
	while(error);

	while (count < ship)
	{
		if( dir == 1)
		{
			board[y][x + temp] = 's';
			temp++;
		}
		else
		{
			board[y + temp] [x] = 's';
			temp++;
		}

		count++;


	}
	printf("sucsess!");
	system("pause");
	system("cls");
	return;
}

void placeDestroyer(char board [SIZE] [SIZE])//gets input and places ship
{
	int ship = 2;
	int x = 0, y = 0, dir = 0, error = 0, count = 0, temp = 0;;
	
	do
	{
	printf("Player please place the Destroyer on the board\nNote Destroyer = %d units\n", ship);
	printBoard(board);
	
	printf("please enter top / left coordinate: x y\n");
	scanf(" %d %d", &x , &y);
	printf("please enter direction -1 for vertical, 1 for horizantal:\n");
	scanf(" %d", &dir);

	if(dir == 1 && x > SIZE - ship)
	{
		system("cls");
		printf("error please try again (horizantal error)\n");
		error = 1;
	}

	if(dir == -1 && y > SIZE - ship)
	{
		system("cls");
		printf("error please try again (vertical error)\n");
		error = 1;
	}

	if(checkIfPlaceable(board, dir, ship, x, y) != 0)
	{
		system("cls");
		printf("placeable error\n");
		error = 1;
	}

	}
	
	while(error);

	while (count < ship)
	{
		if( dir == 1)
		{
			board[y][x + temp] = 'd';
			temp++;
		}
		else
		{
			board[y + temp] [x] = 'd';
			temp++;
		}

		count++;


	}
	printf("sucsess!");
	system("pause");
	system("cls");
	return;
}


int checkIfPlaceable (char board[SIZE] [SIZE], int dir, int size, int x, int y)//checks if the given coords are available to place a ship...also checks if it is in bounds
{
	int placeable = 0;

	if(dir == 1)
	{
		while (x + size < 10)
		{
			if(board [y][x] != '~')
			{
				placeable += 1;
			}

			x++;
		}
	}
	else
	{
		while (y + size< 10)
		{
			if(board [y][x] != '~')
			{
				placeable += 1;
			}
			y++;
		}
	}

	return placeable;
}


void playGame(char p1Boats[SIZE] [SIZE], char p1Shots [SIZE][SIZE], char p2Boats[SIZE] [SIZE], char p2Shots[SIZE] [SIZE], int player)// this is where the game is played after the ships have been placed
{
	int winner = 0, p1Winner = 0, p2Winner = 0, x = 0, y = 0;

	if(player == 1)
	{//player 1 goes first
	
		printf("Player 1....ur up!\n");
		system("pause");

		while(!winner)
		{
			player1(p1Shots, p2Boats);
			p1Winner = checkWinner(p2Boats);
			
			if(p1Winner == 1)
			{
				winner = 1;
				continue;
			}

			printf("Player 2....ur up!\n");
		system("pause");

			player2(p2Shots, p1Boats);
			p2Winner = checkWinner(p1Boats);

			if(p2Winner == 1)
			{
				winner = 1;
				continue;
			}

		}
	}
	else
	{//player 2 goes first
		
	
		printf("Player 2....ur up!\n");
		system("pause");

		while(!winner)
		{
			player1(p2Shots, p1Boats);
			p2Winner = checkWinner(p1Boats);
			
			if(p2Winner == 1)
			{
				winner = 1;
				continue;
			}

			printf("Player 1....ur up!\n");
			system("pause");

			player1(p2Shots, p1Boats);
			p1Winner = checkWinner(p2Boats);

			if(p1Winner == 1)
			{
				winner = 1;
				continue;
			}

		}
	}
	
		
	
	
	
	
	if(p1Winner == 1)
		{
			gameWinner (1);
			taunght (2);

		}
		else
		{
			gameWinner (2);
			taunght (1);
		}

		system("pause");

	


	return;
}

void player1 (char p1Shots [SIZE][SIZE], char p2Boats[SIZE] [SIZE])// gets coords to shoot
{
	int x = 0, y = 0;
	
	printf("Player 1....ur up!\n");
		system("pause");
		getCoord(p1Shots, p2Boats);

	return;
}

void player2 (char p2Shots [SIZE][SIZE], char p1Boats[SIZE] [SIZE]) // same as player 1.. gets coords to shoot
{
	int x = 0, y = 0;
	
	printf("Player 2....ur up!\n");
		system("pause");
		getCoord(p2Shots, p1Boats);

		return;
}

int checkWinner(char boats [SIZE] [SIZE]) // checks if all the ships have been sunk
{
	int i = 0, j=0;
	int hits = 0, winner = 0;;

	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j< SIZE; j++)
		{
			if(boats [i] [j] == 'X')
			{
				hits++;
			}
		}

	}

	if (hits >= 17)
	{
		winner = 1;
	}
	
	return winner;
}

void gameWinner (int player)
{
	printf("CONGRADULATIONS Player %d, You WON!!!!\n", player);

	return;
}

void taunght (int loser)
{
	printf("Player %d, ALL YOUR BASE ARE BELONG TO US\n RESISTANCE IS FUTILE\n");

	return;
}