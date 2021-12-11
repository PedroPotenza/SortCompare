#include "../header.h" 

void swap(int* a, int* b) { 
    int t = *a; 
    *a = *b; 
    *b = t; 
}

// O(nlogn) Sorting: Quick Sort RAW
int partition(int* vetor, int low, int high, unsigned long long* numberComparisons) {
	int pivot = vetor[high]; //pivot
	int i = low - 1, j;
	
	for (j = low; j < high ; j++) {
		if(vetor[j] < pivot) {
			(*numberComparisons) ++;
			i++;
			swap(&vetor[i], &vetor[j]);
		}
	}
	swap(&vetor[i + 1], &vetor[high]);
	
	return (i + 1);
}

void quickSortRaw(int* vetor, int low, int high, unsigned long long* numberComparisons) { // called initially with quickSort(vetor, 0, tam_v - 1);
	if(low < high) {
		(*numberComparisons) ++;

		int pi = partition(vetor, low, high, numberComparisons);

		int q = partition(vetor, low, high, numberComparisons);
		quickSortRaw(vetor, low, pi - 1, numberComparisons); 
        quickSortRaw(vetor, pi + 1, high, numberComparisons);
	}
}

long quickSort(int* vetor, int low, int high, unsigned long long* numberComparisons) {
	struct timeval start;
    gettimeofday(&start, NULL);
    printf("Ordenando...\n\n");

	quickSortRaw(vetor, low, high, numberComparisons);

	struct timeval end;
    gettimeofday(&end, NULL);

	long time_spent = ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec));
    return time_spent;
}