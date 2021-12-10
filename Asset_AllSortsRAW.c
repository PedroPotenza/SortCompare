/* Asset File
  Asset file that contains the following sort algs(RAW):
    Insertion Sort
    Merge Sort
    Quick Sort
    Heap Sort

  Source rep: https://github.com/DaniloNovakovic/sorting-algorithms-in-c
*/
#include <stdio.h>
#include <stdlib.h>

int main() {

  int size = 10;
  //int* vetor = NULL;

  int* vetor = NULL;

  vetor = malloc(size*sizeof(int));

  worstCase(vetor, size);

  showVetor(vetor, size);

  insertionSortRaw(vetor, size);

  showVetor(vetor, size);

  return 0;
}

void worstCase(int* vetor, int size){

    for (int i = 0; i < size; i++)
    {
        vetor[i] = size - i;
    }
}

void showVetor(int* vetor, int size) {
    for (int i = 0; i < size; i++){
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }
}

// O(n^2) Sorting: Insertion Sort e Selection Sort
// Insertion Sort RAW
void insertionSortRaw(int* vetor, int size) {
	int i, j;
	int aux;

	for(i = 1; i < size; i++)
  {
		aux = vetor[i];
		j = i;
		while ((j > 0) && (vetor[j-1] > aux))
    {
			vetor[j] = vetor[j-1];
			j--;
		}
		vetor[j] = aux;
	}
}

// O(nlogn) Sorting: Merge Sort, Quick Sort e Heap Sort
// Merge Sort RAW
void mergeSortRaw(int* vetor, int p, int r) {
	if(p < r) {
		int q = (p + r) / 2;
		mergeSortRaw(vetor, p, q);
		mergeSortRaw(vetor, q + 1, r);
		merge(vetor, p, q, r);
	}
}

void merge(int* vetor, int p, int q, int r) {
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

	while (i < nL && j < nR)
		if (L[i] <= R[j])  vetor[k++] = L[i++];
		else  vetor[k++] = R[j++];

	while (i < nL)	vetor[k++] = L[i++];
	while (j < nR)	vetor[k++] = R[j++];

	free(L);
	free(R);
}

// Heap Sort RAW
void heapSortRaw(int* vetor, int size) {
	max(vetor, size);
	int i = size - 1;
	do {
		int aux = vetor[0];
		vetor[0] = vetor[i];
		vetor[i] = aux;

		maxHeapify(vetor, 0, --size);
	} while(--i >= 0);
}

void max(int* vetor, int size) {
	int i = size/2;
	do
  {
		maxHeapify(vetor, i, size);
	} while(--i  >= 0); //first i = i - 1 is doen and then i >= 0 afterwards.
}

void maxHeapify(int* vetor, int i, int size) {
	int r = right(i);
	int l = left(i);
	int max = i;
	if(l < size && vetor[max] < vetor[l]) max = l;
	if(r < size && vetor[max] < vetor[r]) max = r;
	if(max != i) {
		int aux = vetor[i];
		vetor[i] = vetor[max];
		vetor[max] = aux;
		maxHeapify(vetor, max, size);
	}
}

int left(int i) {
	return 2 * i + 1;
}

int right(int i) {
	return 2 * i + 2;
}

#define swap(t, x, y) { t z = x; x = y; y = z; }

// Quick Sort RAW
int partition(int* vetor, int p, int r) {
	int x = vetor[r]; //pivot
	int i = p - 1, j;
	for (j = p; j < r ; j++) {
		if(vetor[j] <= x) {
			i = i + 1;
			swap(int, vetor[i], vetor[j]);
		}
	}
	i = i + 1;
	swap(int, vetor[i], vetor[r]);
	return i;
}

void quickSortRaw(int* vetor, int p, int r) { // called initially with quickSort(vetor, 0, tam_v - 1);
	if(p < r)
  {
		int t = (rand() % ( r - p + 1) + p);
		swap(int, vetor[t], vetor[r]);
		//Used to avoid O(n^2) worst case

		int q = partition(vetor, p, r);
		quickSortRaw(vetor, p, q - 1);
		quickSortRaw(vetor, q + 1, r);
	}
}
