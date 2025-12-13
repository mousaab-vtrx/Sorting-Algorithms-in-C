/*Cette approche élimine la récursion profonde dans quick_sort_v1 en récursant toujours sur le sous-tableau
plus petit et en itérant sur le plus grand garantissant une profondeur de récursion de
O(log n) au lieu de O(n)*/
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
    int pivotIdx = rand() % (right + 1);
    int pivot = T[pivotIdx];

    permutation(&T[pivotIdx], &T[right]);

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

void quickSort(int *T, int n) {
    while (n > 1) {
        int part = partition(T, n - 1);

        int g = part;
        int d = n - part - 1;

        if (g < d) { 
            quickSort(T, g);
            T += part + 1;
            n -= part + 1;
        } else {
            quickSort(T + part + 1, d);
            n = part;
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
        array[i] = rand() % 40000;

    displayTableau(array, MAX_SIZE);
    quickSort(array, MAX_SIZE);
    displayTableau(array, MAX_SIZE);

    return 0;
}
