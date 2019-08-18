#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

char board[3][3];
char players[2] = { 'X','O' };
int AvaibleSpots[3][3];
int check = 0;

void CreateBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			board[i][j] = '-';
	}
}
void WriteBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)

			printf("%c\t", board[i][j]);

		printf("\n");
	}
}
void SwapPlayers(char players[])
{
	char tmp = players[0];
	players[0] = players[1];
	players[1] = tmp;

}


bool CheckEquals(char a, char b, char c) {
	return (a == b && b == c && a != '-');
}
int CheckWinner() {
	int winner=NULL;
	
	for (int i = 0; i < 3; i++) {
		if (CheckEquals(board[i][0], board[i][1], board[i][2])) {
			winner = board[i][0];
		}
	}

	for (int i = 0; i < 3; i++) {
		if (CheckEquals(board[0][i], board[1][i], board[2][i])) {
			winner = board[0][i];
		}
	}

	if (CheckEquals(board[0][0], board[1][1], board[2][2])) {
		winner = board[0][0];
	}
	if (CheckEquals(board[2][0], board[1][1], board[0][2])) {
		winner = board[2][0];
	}
	

	if (winner == NULL) {
		return NULL;
	}
	else {
		return winner;
	}
}

void Turn()
{
	srand(time(NULL));
	char NowPlaying = players[0];
	int i = 0, j = 0;
	i = rand() % 3;
	j = rand() % 3;
	while (AvaibleSpots[i][j] != 0)
	{
		i = rand() % 3;
		j = rand() % 3;
	}
	board[i][j] = NowPlaying;
	AvaibleSpots[i][j] = 1;
	SwapPlayers(players);
}

void Engine()
{
		CreateBoard();
		WriteBoard();
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				AvaibleSpots[i][j] = 0;
			}
		}		
		while (!CheckWinner() && check < 9)
		{
			check++;
			Turn();
			CheckWinner();	
			system("cls");
			WriteBoard();
			printf("\n");
		}
		
		int FinalWinner = CheckWinner();
		if (FinalWinner != NULL)
			printf("Winner is : %c\n", FinalWinner);
		else printf("Draw \n");
	

}

int main() {
	 
	Engine();
	system("pause");
	return 0;
}