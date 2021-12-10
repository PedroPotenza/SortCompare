#define swap(t, x, y) { t z = x; x = y; y = z; }

// O(nlogn) Sorting: Quick Sort RAW
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

void quickSort(int* vetor, int p, int r) { // called initially with quickSort(vetor, 0, tam_v - 1);
	if(p < r)
  {
		int t = (rand() % ( r - p + 1) + p);
		swap(int, vetor[t], vetor[r]);
		//Used to avoid O(n^2) worst case

		int q = partition(vetor, p, r);
		quickSort(vetor, p, q - 1);
		quickSort(vetor, q + 1, r);
	}
}
