```C
#include <stdio.h>
#include <cstdlib>
#include <ctime>

void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void shakersort(int a[], int n) {
    int p, i;
    for (p = 1; p <= n / 2; p++) {
        for (i = p - 1; i < n - p; i++)
            if (a[i] > a[i+1])
                swap(&a[i], &a[i + 1]);
        for (i = n - p - 1; i >= p; i--)
            if (a[i] < a[i-1])
                swap(&a[i], &a[i - 1]);
    }
}


int main() {
    srand(time(NULL));

    int arr[10];
    for (int i = 0; i < 10; i++) 
        arr[i] = rand()%1000;

    for (int i = 0 ; i < 10; i++)
        printf("%d ", arr[i]);

    shakersort(arr, 10); 
    printf("\n");
    
    for (int i = 0 ; i < 10; i++)
        printf("%d ", arr[i]);
    
    system("pause");
    return 0;
}
```