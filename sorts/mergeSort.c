#include "../header.h"

// O(nlogn) Sorting: Merge Sort
void merge(int* vetor, int p, int q, int r, unsigned long long* numberComparisons) {
	int i, j, k;
	int nL = q - p + 1;
	int nR = r - q;

	int *L = malloc(sizeof(int)*nL);
	int *R = malloc(sizeof(int)*nR);

	for (i = 0; i < nL; i++)
		L[i] = vetor[p + i];

	for (j = 0; j < nR; j++)
		R[j] = vetor[q + 1 + j];

	i = j = 0;
	k = p;

	while (i < nL && j < nR) {
    (*numberComparisons) += 2; //Duas comparacoes por rodada
    (*numberComparisons)++;
    if (L[i] <= R[j])  vetor[k++] = L[i++];
		else  vetor[k++] = R[j++];
	}

	while (i < nL) {
    (*numberComparisons)++;
    vetor[k++] = L[i++];
  }

	while (j < nR) {
	  (*numberComparisons)++;
    vetor[k++] = R[j++];
  }

	free(L);
	free(R);
}

void mergeSortRaw(int* vetor, int p, int r, unsigned long long* numberComparisons) {
	if(p < r) {
    (*numberComparisons)++;
		int q = (p + r) / 2;
		mergeSortRaw(vetor, p, q, numberComparisons);
		mergeSortRaw(vetor, q + 1, r, numberComparisons);
		merge(vetor, p, q, r, numberComparisons);
	}
}

long mergeSort(int* vetor, int size, unsigned long long* numberComparisons){
  // COMECO DE CADA SORT
  struct timeval start;
  gettimeofday(&start, NULL);
  printf("Ordenando...\n\n");
  // ==========================

  mergeSortRaw(vetor, 0, size-1, numberComparisons);

  // FINAL DE CADA SORT
  struct timeval end;
  gettimeofday(&end, NULL);

  long time_spent = ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec));
  return time_spent; // sim, todo sort ao final precisa retornar um long com o tempo de execucao
  // ==========================================
}