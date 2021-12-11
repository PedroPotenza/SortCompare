#ifndef HEADER_H
#define HEADER_H

#define true 1;
#define false 0;

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/time.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#include "sorts/selectionSort.c"
// #include "sorts/insertionSort.c"
// #include "sorts/heapSort.c"
// #include "sorts/mergeSort.c"
// #include "sorts/quickSort.c"

typedef enum {

    NA = 0,
    BEST_CASE,
    WORST_CASE,
    RANDOM_CASE

}FlagCase;

//Sorts
long selectionSort(int* vetor, int size, long long* numberComparisons);

// void insertionSort(int* vetor, int size);

// void quickSort(int* vetor, int size);

// void mergeSort(int* vetor, int size);
// void merge(int* vetor, int p, int q, int r);

// void heapSort(int* vetor, int size);
// void max(int* vetor, int size);
// void maxHeapify(int* vetor, int i, int size);
// int left(int i);
// int right(int i);

//Utils
void showMenu(int countSorts);
void pressAnything();
void clearScreen();
void bestCase(int* vetor, int size);
void worstCase(int* vetor, int size);
void randomCase(int* vetor, int size);
void showVetor(int* vetor, int size);
void FlagPrinter();

#endif 