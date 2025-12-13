#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10000

void fusion(int[], int, int, int);
void mergeSort(int[], int, int);
void displayTableau(int[], int);

void fusion(int T[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = T[l + i];
    for (j = 0; j < n2; j++)
        R[j] = T[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            T[k] = L[i];
            i++;
        }
        else {
            T[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        T[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        T[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int T[], int l, int r){
    
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(T, l, m);
        mergeSort(T, m + 1, r);
        fusion(T, l, m, r);
    }
}

void displayTableau(int T[], int d) {
    for (int i = 0; i < d; i++) printf("%d ", T[i]);
    printf("\n\n");
}

int main() {
    int array[MAX_SIZE];
    srand(time(NULL));

    for (int i = 0; i < MAX_SIZE; i++){
        array[i] = rand() % (MAX_SIZE + 1);
    }
    displayTableau(array, MAX_SIZE);
    mergeSort(array,0,MAX_SIZE-1);
    displayTableau(array, MAX_SIZE);

    return 0;
}
