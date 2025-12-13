#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

void permutation(int*,int*);
void transformHeap(int[],int,int);
void heapSort(int[],int);
void displayTableau(int[],int);

void permutation(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void transformHeap(int T[], int d, int i) {
    int pgv = i,g = 2 * i + 1, dt = 2 * i + 2;  

    if (g < d && T[g] > T[pgv])
        pgv = g;

    if (dt < d && T[dt] > T[pgv])
        pgv = dt;

    if (pgv != i) {
        permutation(T+i,T+pgv);
        transformHeap(T, d, pgv);
    }
}

void heapSort(int T[], int d) {

    for (int i = d/2 - 1; i >= 0; i--) transformHeap(T, d, i);
    for (int i = d - 1; i > 0; i--) {
        permutation(T,T + i);  
        transformHeap(T, i, 0);      
    }
}

void displayTableau(int T[], int d) {
    for (size_t i = 0; i < d; i++)
        printf("%d ", T[i]);
    printf("\n\n");
}

int main() {
    int array[MAX_SIZE];
    srand(time(NULL));

    for (int i = 0; i < MAX_SIZE; i++)
        array[i] = rand() % (MAX_SIZE + 1);

    displayTableau(array, MAX_SIZE);
    heapSort(array, MAX_SIZE);
    displayTableau(array, MAX_SIZE);

    return 0;
}
