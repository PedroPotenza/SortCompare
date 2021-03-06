#include "../header.h" 

// O(n^2) Sorting: Insertion Sort RAW
long insertionSort(int* vetor, int size, unsigned long long* numberComparisons) {
	
	struct timeval start;
    gettimeofday(&start, NULL);
    printf("Ordenando...\n\n");
	
	int i, j;
	int aux;

	for(i = 1; i < size; i++) {
		aux = vetor[i];
		j = i - 1;

		(*numberComparisons) += 1; //Duas comparacoes por rodada

		while ((j >= 0) && (vetor[j] > aux)) {
			
			vetor[j + 1] = vetor[j];
			j--;
			(*numberComparisons) += 1;
		}	
		vetor[j + 1] = aux;
	}

	struct timeval end;
    gettimeofday(&end, NULL);

	long time_spent = ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec));
    return time_spent;
}
