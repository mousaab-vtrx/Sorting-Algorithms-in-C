// Lors du développement de l'algorithme de tri rapide et après l'avoir testé
// j'ai constaté que cette approche entraînait un dépassement de capacité de la pile en raison d'une récursion profonde
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

void permutation(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int partition(int T[], int right) {
    int pivotIndex = rand() % (right + 1);
    int pivot = T[pivotIndex];

    permutation(&T[pivotIndex], &T[right]);

    int j = -1;
    for (int i = 0; i < right; i++) {
        if (T[i] < pivot) {
            j++;
            permutation(&T[j], &T[i]);
        }
    }
    permutation(&T[j+1], &T[right]);
    return j + 1;
}

void quickSort(int T[], int n) {
    if (n <= 1) return;

    int part = partition(T, n - 1);

    quickSort(T, part);
    quickSort(T + part + 1, n - part - 1);
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
        array[i] = rand() % 1001;

    displayTableau(array, MAX_SIZE);
    quickSort(array, MAX_SIZE);
    displayTableau(array, MAX_SIZE);

    return 0;
}
