#ifndef HEADER_H
#define HEADER_H

#define true 1;
#define false 0;

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/time.h>
#include <string.h>
#include <conio.h>
#include <math.h>

#include "sorts/selectionSort.c"
#include "sorts/insertionSort.c"
#include "sorts/quickSort.c"
#include "sorts/mergeSort.c"
#include "sorts/heapSort.c"

typedef enum {

    NA = 0,
    BEST_CASE,
    WORST_CASE,
    RANDOM_CASE

}FlagCase;

//Sorts
long selectionSort(int* vetor, int size, unsigned long long* numberComparisons);

long insertionSort(int* vetor, int size, unsigned long long* numberComparisons);

long quickSort(int* vetor, int low, int high, unsigned long long* numberComparisons);
void swap(int* a, int* b);
int partition(int* vetor, int low, int high, unsigned long long* numberComparisons);
void quickSortRaw(int* vetor, int low, int high, unsigned long long* numberComparisons);

long mergeSort(int* vetor, int size, unsigned long long* numberComparisons);
void mergeSortRaw(int* vetor, int p, int r, unsigned long long* numberComparisons);
void merge(int* vetor, int p, int q, int r, unsigned long long* numberComparisons);

long heapSort(int* vetor, int size, unsigned long long* numberComparisons);
void max(int* vetor, int size, unsigned long long* numberComparisons);
void maxHeapify(int* vetor, int i, int size, unsigned long long* numberComparisons);
int left(int i);
int right(int i);

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
