#include "../header.h" 

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

// O(nlogn) Sorting: Quick Sort RAW
int partition (int arr[], int low, int high, unsigned long long* numberComparisons) 
{ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        {
			(*numberComparisons) ++; 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quickSortRaw(int arr[], int low, int high, unsigned long long* numberComparisons) 
{ 
    if (low < high) 
    { 
		(*numberComparisons) ++; 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(arr, low, high, numberComparisons); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSortRaw(arr, low, pi - 1, numberComparisons); 
        quickSortRaw(arr, pi + 1, high, numberComparisons); 
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