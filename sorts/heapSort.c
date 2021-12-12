#include "../header.h"

// O(nlogn) Sorting: Heap Sort
int left(int i) {
	return 2 * i + 1;
}

int right(int i) {
	return 2 * i + 2;
}

void maxHeapify(int* vetor, int i, int size, unsigned long long* numberComparisons) {
	int r = right(i);
	int l = left(i);
	int max = i;

	(*numberComparisons) += 2;
	if(l < size && vetor[max] < vetor[l]) {	
	 	max = l;
 	}

	(*numberComparisons) += 2;
	if(r < size && vetor[max] < vetor[r]) {
    	max = r;
 	}

	(*numberComparisons)++;
	if(max != i) {
		int aux = vetor[i];
		vetor[i] = vetor[max];
		vetor[max] = aux;
		maxHeapify(vetor, max, size, numberComparisons);
	}
}

void max(int* vetor, int size, unsigned long long* numberComparisons) {
	int i = size / 2;
	do
  	{
		maxHeapify(vetor, i, size, numberComparisons);
    
		(*numberComparisons)++;
	} while(--i >= 0); //first i = i - 1 is done and then i >= 0 afterwards.
}

long heapSort(int* vetor, int size, unsigned long long* numberComparisons) {

	struct timeval start;
    gettimeofday(&start, NULL);
    printf("Ordenando...\n\n");

	max(vetor, size, numberComparisons);
	int i = size - 1;
	do {
		int aux = vetor[0];
		vetor[0] = vetor[i];
		vetor[i] = aux;

		maxHeapify(vetor, 0, --size, numberComparisons);
		(*numberComparisons)++;
	} while(--i >= 0);

	struct timeval end;
    gettimeofday(&end, NULL);

    long time_spent = ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec));
    return time_spent;
}