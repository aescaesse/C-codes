### Who first hit 100 wins

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <conio.h> 
#include <string.h>

void cls()
{
	system("@cls||clear");
}

void Draw(int a[], int s, int n, int CurrSum)
{

	printf("\n+---------------- BOARD ---------------------+\n");
	printf(" \tPC \t Player \t \n");
	for (int i = 0, j = 0; i <= n; i += 2, j++)
		printf("%i. \t%i \t %i \t \t \n", j + 1, a[i], a[i + 1]);
	printf("+------------ Current Sum: %i ---------------+\n", CurrSum);
}

int PCTurnF(int n)
{
	if (n == 0)
		return 1;
	return 11 - n;
}

int ComputerStep(int PlayerTurn)
{
	int PCTurn = 0;
	printf("PC: Ok, my move. I`ll pick %d", PCTurn = PCTurnF(PlayerTurn));
	return PCTurn;
}
int PlayerStep()
{
	int PlayerTurn = 0;
	printf("\nPlayer: > ");
	scanf("%i", &PlayerTurn);
	while (PlayerTurn < 1 || PlayerTurn>10)
	{
		printf("Only 1-10 numbers: > ");
		scanf("%i", &PlayerTurn);
	}
	return PlayerTurn;
}

void Core()
{
	int PCTurn = 0, PlayerTurn = 0, Sum = 0, i = 2, Turns[100], CurrentPlayer = 1, CountSteps = 1;
	memset(Turns, 0, sizeof(Turns));
	printf("+------------ First to 100 wins -------------+\n");
	printf("PC will start\n");
	PCTurn = ComputerStep(PlayerTurn);
	Sum += PCTurn; 
	Turns[0] = PCTurn; 
	Draw(Turns, Sum, CountSteps, Sum);
	PlayerTurn = PlayerStep(); 
	Sum += PlayerTurn; 
	Turns[1] = PlayerTurn; 
	while (Sum < 100)
	{
		CountSteps++; 
		if (CurrentPlayer == 1)
		{
			cls();
			PCTurn = ComputerStep(PlayerTurn); 
			Sum += PCTurn; 
			Turns[i] = PCTurn;
			Draw(Turns, Sum, CountSteps, Sum);
			CurrentPlayer = 0;
			
		}
		else if(CurrentPlayer == 0)
		{
			PlayerTurn = PlayerStep();
			Sum += PlayerTurn; 
			Turns[i] = PlayerTurn;
			CurrentPlayer = 1; 
		}	
		i++;
	}
	if (CurrentPlayer) 
		printf("Player wins"); 
	else
		printf("Computer wins");
}

int main()
{
	Core();
	return 0;
}
```