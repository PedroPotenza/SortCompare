// O(nlogn) Sorting: Merge Sort RAW
void mergeSort(int* vetor, int p, int r) {
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
