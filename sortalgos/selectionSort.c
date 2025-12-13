#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10000

void permutation(int*, int*);
void selectionSort(int[], int);
void displayTableau(int[], int);
void permutation(int*x,int*y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
void selectionSort(int T[],int d) {
    for (size_t i = 0; i < d - 1; i++)
    {
        int minidx = i;
        for (size_t j = i + 1; j < d; j++)
        {
            if(T[j] < T[minidx]) minidx = j;
            
        }
        if(i != minidx) {
            permutation(&T[i],&T[minidx]);
        }
        
    }
    
}
void displayTableau(int T[], int n) {
    for (size_t i = 0; i < n; i++)
        printf("%d ", T[i]);
    printf("\n\n");
}

int main() {
    int array[MAX_SIZE];
    srand(time(NULL));

    for (int i = 0; i < MAX_SIZE; i++)
        array[i] = rand() % (MAX_SIZE + 1);

    displayTableau(array, MAX_SIZE);
    selectionSort(array, MAX_SIZE);
    displayTableau(array, MAX_SIZE);

    return 0;
}
