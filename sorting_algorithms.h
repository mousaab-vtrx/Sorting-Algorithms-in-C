#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void permutation(int *x, int *y);
void bubbleSort(int arr[], int n);
void selectionSort(int T[], int d);
void insertionSort(int T[], int d);
void fusion(int T[], int l, int m, int r);
void mergeSort_recursive(int T[], int l, int r);
void mergeSort(int T[], int n);
void transformHeap(int T[], int d, int i);
void heapSort(int T[], int d);
int partition_v1(int T[], int right);
void quickSort_v1(int T[], int n);
int partition_v2(int T[], int right);
void quickSort_v2(int *T, int n);
void shellSort(int T[], int d);
int computeMin(int n);
void timsort_insertionSort(int T[], int n);
void timsort_fusion(int T[], int l, int m, int r);
void revRange(int T[], int i, int f);
int findRun(int T[], int i, int d);
void timSort(int T[], int d);

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

void selectionSort(int T[], int d) {
    for (size_t i = 0; i < d - 1; i++) {
        int minidx = i;
        for (size_t j = i + 1; j < d; j++) {
            if (T[j] < T[minidx]) minidx = j;
        }
        if (i != minidx) {
            permutation(&T[i], &T[minidx]);
        }
    }
}

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

void fusion(int T[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));
    
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
        } else {
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
    
    free(L);
    free(R);
}

void mergeSort_recursive(int T[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort_recursive(T, l, m);
        mergeSort_recursive(T, m + 1, r);
        fusion(T, l, m, r);
    }
}

void mergeSort(int T[], int n) {
    mergeSort_recursive(T, 0, n - 1);
}

void transformHeap(int T[], int d, int i) {
    int pgv = i, g = 2 * i + 1, dt = 2 * i + 2;
    
    if (g < d && T[g] > T[pgv])
        pgv = g;
    
    if (dt < d && T[dt] > T[pgv])
        pgv = dt;
    
    if (pgv != i) {
        permutation(T + i, T + pgv);
        transformHeap(T, d, pgv);
    }
}

void heapSort(int T[], int d) {
    for (int i = d / 2 - 1; i >= 0; i--)
        transformHeap(T, d, i);
    
    for (int i = d - 1; i > 0; i--) {
        permutation(T, T + i);
        transformHeap(T, i, 0);
    }
}

int partition_v1(int T[], int right) {
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
    permutation(&T[j + 1], &T[right]);
    return j + 1;
}

void quickSort_v1(int T[], int n) {
    if (n <= 1) return;
    
    int part = partition_v1(T, n - 1);
    quickSort_v1(T, part);
    quickSort_v1(T + part + 1, n - part - 1);
}

int partition_v2(int T[], int right) {
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
    permutation(&T[j + 1], &T[right]);
    return j + 1;
}

void quickSort_v2(int *T, int n) {
    while (n > 1) {
        int part = partition_v2(T, n - 1);
        
        int left = part;
        int right = n - part - 1;
        
        if (left < right) {
            quickSort_v2(T, left);
            T += part + 1;
            n -= part + 1;
        } else {
            quickSort_v2(T + part + 1, right);
            n = part;
        }
    }
}

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

#define MIN_RUN 32

typedef struct {
    int l, r;
} Run;

int computeMin(int n) {
    int r = 0;
    while (n >= MIN_RUN) {
        r |= (n & 1);
        n >>= 1;
    }
    return n + r;
}

void timsort_insertionSort(int T[], int n) {
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

void timsort_fusion(int T[], int l, int m, int r) {
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
    free(g);
    free(dt);
}

void revRange(int T[], int i, int f) {
    f--;
    while (i < f) {
        permutation(T + i, T + f);
        i++;
        f--;
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

void timSort(int T[], int d) {
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
            int *tmp = malloc(tmpSize * sizeof(int));
            memcpy(tmp, T + i, tmpSize * sizeof(int));
            timsort_insertionSort(tmp, tmpSize);
            memcpy(T + i, tmp, tmpSize * sizeof(int));
            free(tmp);
            runfin = f;
        }
        
        runs[nbrRuns].l = i;
        runs[nbrRuns].r = runfin;
        nbrRuns++;
        i = runfin;
    }
    
    int currentSize = min;
    while (currentSize < d) {
        i = 0;
        while (i + 1 < nbrRuns) {
            int runSize1 = runs[i].r - runs[i].l;
            int runSize2 = runs[i + 1].r - runs[i + 1].l;
            
            if (runSize1 + runSize2 <= currentSize * 2) {
                int l = runs[i].l;
                int m = runs[i].r - 1;
                int r = runs[i + 1].r - 1;
                
                timsort_fusion(T, l, m, r);
                
                runs[i].r = runs[i + 1].r;
                for (int j = i + 1; j < nbrRuns - 1; j++) {
                    runs[j] = runs[j + 1];
                }
                nbrRuns--;
            } else {
                i++;
            }
        }
        currentSize *= 2;
    }
    
    free(runs);
}

#endif

