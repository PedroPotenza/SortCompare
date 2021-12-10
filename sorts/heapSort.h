#ifndef HEAPSORT_H
#define HEAPSORT_H

void heapSort(int* vetor, int size);
void max(int* vetor, int size);
void maxHeapify(int* vetor, int i, int size);
int left(int i);
int right(int i);

#endif
