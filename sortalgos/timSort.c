#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_RUN 16
#define MAX_SIZE 200

typedef struct {
    int l, r;
} Run;

void permutation(int*, int*);
int computeMin(int);
void insertionSort(int[], int);
void fusion(int[], int, int, int);
void revRange(int[], int, int);
int findRun(int[], int, int);
void timsort(int[], int);
void displayTableau(int[], int);

void permutation(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int computeMin(int n) {
    int r = 0;
    while (n >= MIN_RUN) {
        r |= (n & 1);
        n >>= 1;
    }
    return n + r;
}

void insertionSort(int T[], int n) {
    for (int i = 1; i < n; i++) {
        int x = T[i];
        int j = i - 1;
        while (j >= 0 && T[j] > x) {
            T[j + 1] = T[j];
            j--;
        }
        T[j + 1] = x;
    }
}

void fusion(int T[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int *g = malloc(n1 * sizeof(int));
    int *dt = malloc(n2 * sizeof(int));
    memcpy(g, T + l, n1 * sizeof(int));
    memcpy(dt, T + m + 1, n2 * sizeof(int));
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (g[i] <= dt[j])
            T[k++] = g[i++];
        else
            T[k++] = dt[j++];
    }
    while (i < n1) T[k++] = g[i++];
    while (j < n2) T[k++] = dt[j++];
    free(g); free(dt);
}

void revRange(int T[], int i, int f) {
    f--;
    while (i < f) {
        permutation(T + i, T + f);
        i++; f--;
    }
}

int findRun(int T[], int i, int d) {
    int f = i + 1;
    if (f == d) return f;
    if (T[f] < T[i]) {
        while (f < d && T[f] < T[f - 1]) f++;
        revRange(T, i, f);
    } else {
        while (f < d && T[f] >= T[f - 1]) f++;
    }
    return f;
}

void timsort(int T[], int d) {
    int min = computeMin(d);

    Run *runs = malloc(d * sizeof(Run));
    int nbrRuns = 0;

    int i = 0;
    while (i < d) {
        int runfin = findRun(T, i, d);
        int runLen = runfin - i;

        if (runLen < min) {
            int f = i + min;
            if (f > d) f = d;
            int tmpSize = f - i;
            int *tmp = malloc(tmpSize*sizeof(int));
            memcpy(tmp, T + i, tmpSize*sizeof(int));
            insertionSort(tmp, tmpSize);
            memcpy(T + i, tmp, tmpSize*sizeof(int));
            free(tmp);
            runfin = f;
        }

        runs[nbrRuns++] = (Run){i, runfin};
        i = runfin;

        while (nbrRuns > 1) {
            int l1 = runs[nbrRuns - 2].l;
            int r1 = runs[nbrRuns - 2].r;
            int l2 = runs[nbrRuns - 1].l;
            int r2 = runs[nbrRuns - 1].r;
            int len1 = r1 - l1;
            int len2 = r2 - l2;
            if (len1 <= len2 || 
                (nbrRuns >= 3 &&
                 (runs[nbrRuns-3].r - runs[nbrRuns-3].l) <= len1 + len2)) {

                fusion(T, l1, r1 - 1, r2 - 1);
                runs[nbrRuns - 2].r = r2;
                nbrRuns--;
            }
            else break;
        }
    }

    while (nbrRuns > 1) {
        int l1 = runs[nbrRuns - 2].l;
        int r1 = runs[nbrRuns - 2].r;
        int l2 = runs[nbrRuns - 1].l;
        int r2 = runs[nbrRuns - 1].r;

        fusion(T, l1, r1 - 1, r2 - 1);
        runs[nbrRuns - 2].r = r2;
        nbrRuns--;
    }
    free(runs);
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
    timsort(array, MAX_SIZE);
    displayTableau(array, MAX_SIZE);

    return 0;
}
