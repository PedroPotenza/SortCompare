#include "../header.h"

// O(nlogn) Sorting: Heap Sort
long heapSort(int* vetor, int size, long long* numberComparisons) {
	max(vetor, size, numberComparisons);
	int i = size - 1;
	do {
		int aux = vetor[0];
		vetor[0] = vetor[i];
		vetor[i] = aux;

		maxHeapify(vetor, 0, --size, numberComparisons);
		(*numberComparisons)++;
	} while(--i >= 0);
}

void max(int* vetor, int size, long long* numberComparisons) {
	int i = size / 2;
	do
  	{
		maxHeapify(vetor, i, size, numberComparisons);
    (*numberComparisons)++;
	} while(--i >= 0); //first i = i - 1 is done and then i >= 0 afterwards.
}

void maxHeapify(int* vetor, int i, int size, long long* numberComparisons) {
	int r = right(i);
	int l = left(i);
	int max = i;

	if(l < size && vetor[max] < vetor[l]) {
    (*numberComparisons) += 2;
	  max = l;
  }
	if(r < size && vetor[max] < vetor[r]) {
	  (*numberComparisons) += 2;
    max = r;
  }

	if(max != i) {
    (*numberComparisons)++;
		int aux = vetor[i];
		vetor[i] = vetor[max];
		vetor[max] = aux;
		maxHeapify(vetor, max, size, numberComparisons);
	}
}

int left(int i) {
	return 2 * i + 1;
}

int right(int i) {
	return 2 * i + 2;
}
