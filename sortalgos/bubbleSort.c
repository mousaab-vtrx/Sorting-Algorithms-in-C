

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_SIZE 1000000
void permutation(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void bubbleSort(int arr[], int n) {
    int i, j, swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                permutation(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
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
    bubbleSort(array, MAX_SIZE);
    displayTableau(array, MAX_SIZE);

    return 0;
}

