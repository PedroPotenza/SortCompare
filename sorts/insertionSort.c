// O(n^2) Sorting: Insertion Sort RAW
void insertionSort(int* vetor, int size) {
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
