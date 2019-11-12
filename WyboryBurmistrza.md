### Wybory burmistrza
W wyborach burmistrza Wielkiego Guslaru wystartowało M kandydatów ponumerowanych liczbami od 1 do M. Każdy z N głosujących oddał ważny głos na jednego z nich. Napisz program, który wczyta opis głosów, a następnie poda wyniki głosowania i numer kandydata wybranego na burmistrza. Zgodnie z prawem wyborczym Wielkiego Guslaru, jeśli dwóch lub więcej kandydatów uzyskało tę samą, najwyższą liczbę głosów, to wybory wygrywa ten z nich, który ma niższy numer. Wejście W pierwszej linii wejścia znajdują się dwie liczby całkowite M i N (1<=M<=10, 1<=N<=1000), określające odpowiednio liczbę kandydatów i liczbę oddanych głosów. W drugiej linii znajduje się N liczb całkowitych z zakresu od 1 do M. Są to numery kandydatów, na których oddane zostały poszczególne głosy. Wyjście W pierwszych M liniach wyjścia należy podać kolejno liczby głosów zdobytych przez kandydatów z numerami od 1 do M, w formacie "X: Y", gdzie X oznacza numer kandydata, a Y - liczbę oddanych na niego głosów. Następnie w osobnej linii należy wypisać numer kandydata, który wygrał wybory. Przykład
```
Wejście: 
3 
10 
1 3 2 1 2 3 3 3 2 2 
```
```
Wyjście: 
1: 2 
2: 4 
3: 4 
2
```

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
int main()
{
	int M = 0, N = 0, ile[1000], zwyciezca = 0;
	int* Glosy;
	scanf("%i", &M);
	scanf("%i", &N);
	Glosy = (int*)malloc(N * sizeof(int));
	while ((M > 10 || M < 1) || (N < 1 || N>1000))
	{
		printf("Podaj prawidlowe dane.\n");
		scanf("%i", &M);
		scanf("%i", &N);
	}
	for (int i = 0; i < N; i++)
	{
		Glosy[i] = 0;
		ile[i] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%i", &Glosy[i]);
	}
	for (int i = 0; i < N; i++)
	{
		++ile[Glosy[i]];
	}
	int i = 0;
	while (i != M)
	{
		printf("%i: %i\n", i + 1, ile[i + 1]);
		i++;
	}
	zwyciezca = Glosy[0];
	for (int i = 1; i < N; i++)
	{
		if (zwyciezca > Glosy[i])
			zwyciezca = Glosy[i];
	}
	printf("%d", zwyciezca);
	free(Glosy);
	return 0;
}
```
