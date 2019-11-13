#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

const int width = 20;
const int height = 20;
int ItemX, ItemY, CountEaten, SnakeX, SnakeY;
int IsGameOver;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum Direction direction;
short int SnakeTailX[100], SnakeTailY[100];
int SnakeTailLong;

void cls()
{
	system("@cls||clear");
}

void WriteBoard()
{	
	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++) {
			if (i == 1 || i == width) {
				printf("#");
			}
			else if (j == 1 || j == height) {
				printf("#");
			}
			else if (i == SnakeY && j == SnakeX)
				printf("S");
			else if (i == ItemY && j == ItemX)
				printf("*");
			else
			{
				bool print = false;
				for (int k = 0; k < SnakeTailLong; k++)
				{
					if (SnakeTailX[k] == j && SnakeTailY[k] == i)
					{
						printf("o");
						print = true;
					}
				}
				if (!print)
					printf(" ");

			}
			
		}
		printf("\n");		
	}
}

void PlayerInput()
{
	while (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
			direction = UP;
				break;		
		case 's':
			direction = DOWN;
				break;	
		case 'a':
			direction = LEFT;
				break;
		case 'd':
			direction = RIGHT;
				break;
		case 'x':
			IsGameOver = 1;
			break;
		}
	}
}

void Basics()
{
	int PreviousX = SnakeTailX[0];
	int PreviousY = SnakeTailY[0];
	int PreviousSecX, PreviousSecY;
	SnakeTailX[0] = SnakeX;
	SnakeTailY[0] = SnakeY;
	for (int i = 1; i < SnakeTailLong; i++)
	{
		PreviousSecX = SnakeTailX[i];
		PreviousSecY = SnakeTailY[i];
		SnakeTailX[i] = PreviousX;
		SnakeTailY[i] = PreviousY;
		PreviousX = PreviousSecX;
		PreviousY = PreviousSecY;
	}
	srand(time(NULL));
	switch (direction)
	{
	case LEFT:
		SnakeX--;
		break;
	case RIGHT:
		SnakeX++;
		break;
	case UP:
		SnakeY--;
		break;
	case DOWN:
		SnakeY++;
		break;
	default:
			break;

	}
	if (SnakeX >= width || SnakeX <= 1 || SnakeY >= height || SnakeY <= 1)
		IsGameOver = 1;
	for (int i = 0; i < SnakeTailLong; i++)
		if (SnakeTailX[i] == SnakeX && SnakeTailY[i] == SnakeY)
			IsGameOver = 1;
	if (SnakeX == ItemX && SnakeY == ItemY)
	{
		CountEaten += 20;
		ItemX = (rand() % (width - 2 + 1)) + 2;
		ItemY = (rand() % (height - 2 + 1)) + 2;
		SnakeTailLong++;
	}
}

void ItemPos()
{
	srand(time(NULL));
	ItemX = (rand() % (width - 2 + 1)) + 2;
	ItemY = (rand() % (height - 2 + 1)) + 2;
	SnakeX = width / 2;
	SnakeY = height / 2;
}

void Settings()
{
	direction = STOP;
	IsGameOver = 0;
	CountEaten = 0;
}


void Game()
{
	Settings();
	ItemPos();
	printf("Press any key to start, control: wsad");

	while (!IsGameOver)
	{
		cls();
		WriteBoard();
		PlayerInput();
		Basics();
		printf("Your score:%d", CountEaten);
		Sleep(300);
	
	}	
}

int main() {

	Game();
	return 0;
}
