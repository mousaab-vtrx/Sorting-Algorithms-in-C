#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 1000000

void insertionSort(int T[], int d) {
    int i, j, key;
    for (i = 1; i < d; i++) {
        key = T[i];
        j = i - 1;

        while (j >= 0 && T[j] > key) {
            T[j + 1] = T[j];
            j--;
        }
        T[j + 1] = key;
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

    for (int i = 0; i < MAX_SIZE; i++) array[i] = rand() % (MAX_SIZE + 1);

    displayTableau(array, MAX_SIZE);
      insertionSort(array,MAX_SIZE);
    displayTableau(array, MAX_SIZE);

    return 0;
}
