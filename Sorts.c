#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/time.h>
#include <conio.h>

#define true 1;
#define false 0;

typedef enum {

    NA = 0,
    BEST_CASE,
    WORST_CASE,
    RANDOM_CASE
}FlagCase;

FlagCase flag = NA;

void clearScreen(){

    system("@cls||clear");
}

void pressAnything(){

    printf("\nPressione qualquer coisa...");
    getch();
}

void FlagPrinter(){

    switch (flag)
    {
    case NA:
        printf("NULL");
        break;
    
    case BEST_CASE:
        printf("Best Case");
        break;
    
    case WORST_CASE:
        printf("Worst Case");
        break;
    
    case RANDOM_CASE:
        printf("Random Case");
        break;
    
    }    

}

void bestCase(int* vetor, int size){

    for(int i = 0; i < size; i++)
    {
        vetor[i] = i+1;
    }

    printf("Concluido - Preenchimento Crescente\n");
    flag = BEST_CASE;

}

void worstCase(int* vetor, int size){

    for (int i = 0; i < size; i++)
    {
        vetor[i] = size - i;
    }

    printf("Concluido - Preenchimento Decrescente\n");
    flag = WORST_CASE;

}

void randomCase(int* vetor, int size){

  
    for(int i = 0; i < size; i++)
    {
        vetor[i] = 1 + (rand() % size);
    }

    printf("Concluido - Preenchimento Random\n");
    flag = RANDOM_CASE;
    
}

void showVetor(int* vetor, int size){
    for (int i = 0; i < size; i++){
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }
}

void selectionSort(int* vetor, int size){

    struct timeval start;
    gettimeofday(&start, NULL);
    printf("Ordenando...\n");

    long int numberComparisons = 0;

    for (int i = 0; i < size; i++)
    {
        int indexLower = i;
        for (int j = i+1; j < size; j++)
        {
            numberComparisons++; 
            if(vetor[j] < vetor[indexLower]){ 
                indexLower = j;
            }
        }
        int aux = vetor[i];
        vetor[i] = vetor[indexLower];
        vetor[indexLower] = aux;
    }
    
    struct timeval end;
    gettimeofday(&end, NULL);

    long seconds, nseconds;
    float time_spent;

    seconds  = end.tv_sec  - start.tv_sec;
    nseconds = end.tv_usec - start.tv_usec;

    time_spent = (seconds + nseconds)/1000000.0;

    printf("======= SELECTION SORT ======= \n");
    printf("Tamanho do vetor: %d\n", size);
    printf("Como ele estava preenchido? ");
    FlagPrinter();
    printf("\nTempo gasto: %f\n", time_spent);
    printf("Numero de comparacoes: %ld\n", numberComparisons);

    flag = BEST_CASE;

}

int main(void){

    int size; 
    int* vetor = NULL;
    srand(time(NULL)); //every execute has a diferent seed, so rand is truly random ;) 

    printf("\nTamanho do vetor: ");
    scanf("%d", &size);

    vetor = malloc(size*sizeof(int));
    
    int sair = false;
    while(!sair){

        printf("\nComo preencher o vetor?\n");
        printf("(1) - Crescente (melhor caso)\n");
        printf("(2) - Decrescente (pior caso)\n");
        printf("(3) - Aleatorio\n");

        printf("\nFuncoes Uteis:\n");
        printf("(4) - Imprimir vetor\n");

        printf("\nSorts:\n");
        printf("(5) - Select Sort\n");
        printf("(0) - Sair\n");

        int option;
        printf("\nOpcao: ");
        scanf("%d", &option);
        printf("\n");

        switch (option)
        {
        case 0:
            sair = true;
            break;

        case 1:
            bestCase(vetor, size);
            pressAnything();
            clearScreen();
            break;

        case 2:
            worstCase(vetor, size);
            pressAnything();
            clearScreen();
            break;

        case 3:
            randomCase(vetor, size);
            pressAnything();
            clearScreen();

            break;

        case 4:
            showVetor(vetor, size);
            pressAnything();
            clearScreen();
            break;

        case 5:
            selectionSort(vetor, size);
            pressAnything();
            clearScreen();
            break;
        
        default:
            printf("\nInvalid option\n");
            break;
        }
 
    }

}