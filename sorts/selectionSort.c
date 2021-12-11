#include "../header.h" 

// O(n^2) Sorting: Selection sort
long selectionSort(int* vetor, int size, long long* numberComparisons){
    
    // COMECO DE CADA SORT
    struct timeval start;
    gettimeofday(&start, NULL);
    printf("Ordenando...\n\n");
    // ==========================

    for (int i = 0; i < size; i++)
    {
        int indexLower = i;
        for (int j = i+1; j < size; j++)
        {
            (*numberComparisons)++; // ATENCAO ATENCAO CADA COMPARACAO METE O CONTADOR
            if(vetor[j] < vetor[indexLower]){
                indexLower = j;
            }
        }
        int aux = vetor[i];
        vetor[i] = vetor[indexLower];
        vetor[indexLower] = aux;
    }

    // FINAL DE CADA SORT 
    struct timeval end;
    gettimeofday(&end, NULL);

    long time_spent = ((end.tv_sec * 1000000 + end.tv_usec) -(start.tv_sec * 1000000 + start.tv_usec));
    return time_spent; // sim, todo sort ao final precisa retornar um long com o tempo de execucao
    // ==========================================

}
