#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 100000
void shellSort(int T[],int d) {
    int gap,i,j,tmp;
    for (gap = d/2; gap > 0; gap /= 2) {
        for (i = gap; i < d; i++) {
            tmp = T[i];j = i;
            while (j >= gap && T[j - gap] > tmp) {
                T[j] = T[j - gap];
                j -= gap;
            }
            T[j] = tmp;
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
    for (int i = 0; i < MAX_SIZE; i++) array[i] = rand() % (MAX_SIZE + 1);
    displayTableau(array, MAX_SIZE);
    shellSort(array, MAX_SIZE);
    displayTableau(array, MAX_SIZE);

    return 0;
}
