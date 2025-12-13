#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include "sorting_algorithms.h"

#define NUM_SIZES 10

// High-resolution timer for Windows
static double now_ms() {
    static LARGE_INTEGER frequency = {0};
    LARGE_INTEGER counter;

    if (frequency.QuadPart == 0) {
        QueryPerformanceFrequency(&frequency);
    }

    QueryPerformanceCounter(&counter);
    return (double)counter.QuadPart * 1000.0 / (double)frequency.QuadPart;
}

typedef struct {
    const char *name;
    void (*function)(int[], int);
} SortingAlgorithm;

void generate_random_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (size * 10);
    }
}

int verify_sorted(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1])
            return 0;
    }
    return 1;
}

int main() {
    srand(time(NULL));

    SortingAlgorithm algorithms[] = {
        {"Bubble Sort",      bubbleSort},
        {"Selection Sort",   selectionSort},
        {"Insertion Sort",   insertionSort},
        {"Shell Sort",       shellSort},
        {"Merge Sort",       mergeSort},
        {"Heap Sort",        heapSort},
        {"Quick Sort V1",    quickSort_v1},
        {"Quick Sort V2",    quickSort_v2},
        {"Tim Sort",         timSort}
    };
    int num_algorithms = sizeof(algorithms) / sizeof(algorithms[0]);

    int sizes[NUM_SIZES] = {
        100, 500, 1000, 2000, 5000,
        10000, 20000, 50000, 100000, 200000
    };

    FILE *output = fopen("benchmark_results.csv", "w");
    if (!output) {
        perror("Failed to open output file");
        return 1;
    }

    /* -------------------------
       Write CSV header
       ------------------------- */
    fprintf(output, "Size");
    for (int i = 0; i < num_algorithms; i++) {
        fprintf(output, ",%s", algorithms[i].name);
    }
    fprintf(output, "\n");

    /* -------------------------
       Benchmark loop
       ------------------------- */
    for (int s = 0; s < NUM_SIZES; s++) {
        int size = sizes[s];
        int *original = malloc(size * sizeof(int));
        int *arr = malloc(size * sizeof(int));

        if (!original || !arr) {
            fprintf(stderr, "Memory allocation failed for size %d\n", size);
            return 1;
        }

        generate_random_array(original, size);
        fprintf(output, "%d", size);

        for (int a = 0; a < num_algorithms; a++) {
            memcpy(arr, original, size * sizeof(int));

            double t0 = now_ms();
            algorithms[a].function(arr, size);
            double t1 = now_ms();

            if (!verify_sorted(arr, size)) {
                fprintf(stderr, "Error: %s failed to sort size %d\n",
                        algorithms[a].name, size);
                fprintf(output, ",ERROR");
            } else {
                fprintf(output, ",%.3f", t1 - t0);
            }
        }

        fprintf(output, "\n");
        free(original);
        free(arr);
    }

    fclose(output);
    return 0;
}
