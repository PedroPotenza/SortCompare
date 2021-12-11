#include "../header.h" 

#define swap(t, x, y) { t z = x; x = y; y = z; }

// O(nlogn) Sorting: Quick Sort RAW
int partition(int* vetor, int low, int high, long long* numberComparisons) {
	int x = vetor[high]; //pivot
	int i = low - 1, j;
	
	for (j = low; j < high ; j++) {
		if(vetor[j] <= x) {
			i = i + 1;
			swap(int, vetor[i], vetor[j]);
		}
	}
	i = i + 1;

	swap(int, vetor[i], vetor[high]);
	
	return i;
}

void quickSortRaw(int* vetor, int low, int high, long long* numberComparisons) { // called initially with quickSort(vetor, 0, tam_v - 1);
	if(low < high) {
		(*numberComparisons) ++;

		int t = (rand() % ( high - low + 1) + low);
		swap(int, vetor[t], vetor[high]);

		int q = partition(vetor, low, high, &numberComparisons);
		quickSort(vetor, low, q - 1, &numberComparisons);
		quickSort(vetor, low + 1, high, &numberComparisons);
	}
}

long quickSort(int* vetor, int low, int high, long long* numberComparisons) {
	struct timeval start;
    gettimeofday(&start, NULL);
    printf("Ordenando...\n\n");

	quickSortRaw(vetor, low, high, &numberComparisons);

	struct timeval end;
    gettimeofday(&end, NULL);

	long time_spent = ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec));
    return time_spent;
}