// O(nlogn) Sorting: Heap Sort
void heapSort(int* vetor, int size) {
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
