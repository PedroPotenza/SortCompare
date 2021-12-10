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

int trueRand(){

    int value;
    value = (rand() % 32000);
    if(value % 2 != 0)
    {
        int value2 = (rand() % 32000);
        if(value % 2 != 0){
            int value3 = (rand() % 32000);
            return value2*value3;
        } else {
            value2;
        }
    } else {
        return value;
    }
}

void bestCase(int* vetor, int size){

    for(int i = 0; i < size; i++)
    {
        vetor[i] = i+1;
    }

}

void worstCase(int* vetor, int size){

    for (int i = 0; i < size; i++)
    {
        vetor[i] = size - i;
    }

}

void randomCase(int* vetor, int size){

    for(int i = 0; i < size; i++)
    {
        vetor[i] = trueRand();
    }
    
}

void showVetor(int* vetor, int size){
    for (int i = 0; i < size; i++){
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }
}

long selectionSort(int* vetor, int size, long* numberComparisons){

    struct timeval start;
    gettimeofday(&start, NULL);
    printf("Ordenando...\n\n");

    for (int i = 0; i < size; i++)
    {
        int indexLower = i;
        for (int j = i+1; j < size; j++)
        {
            (*numberComparisons)++; 
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

    long time_spent = ((end.tv_sec * 1000000 + end.tv_usec) -(start.tv_sec * 1000000 + start.tv_usec));
    return time_spent;

    flag = BEST_CASE;

}

void selectionSortRepeatMenu(int* vetor, int size, int countSort){

    clearScreen();
    printf("\nRepita %d vezes com qual caso inicial?\n", countSort);
    printf("(1) - Crescente (melhor caso)\n");
    printf("(2) - Decrescente (pior caso)\n");
    printf("(3) - Aleatorio\n");

    int option;
    scanf("%d", &option);

    long time_spent = 0, time_spend_interation;
    long numberComparisons = 0;

    for (int i = 0; i < countSort; i++)
    {
        if(option == 1){
            bestCase(vetor, size);
            time_spend_interation = selectionSort(vetor, size, &numberComparisons);
            flag = BEST_CASE;
        }

        if(option == 2){
            worstCase(vetor, size);
            time_spend_interation = selectionSort(vetor, size, &numberComparisons);
            flag = WORST_CASE;
        }

        if(option == 3){
            randomCase(vetor, size);
            time_spend_interation = selectionSort(vetor, size, &numberComparisons);
            flag = RANDOM_CASE;
        }

        time_spent += time_spend_interation;
    }
    
    printf("======= SELECTION SORT ======= \n");
    printf("Quantas vezes o sort foi feito? %d\n", countSort);
    printf("Tamanho do vetor: %d\n", size);
    printf("Como ele estava sendo preenchido? ");
    FlagPrinter();
    printf("\nTempo gasto:  %lf\n", (time_spent/countSort)/1000000.0);
    printf("Numero de comparacoes: %ld\n", numberComparisons/countSort);

    flag = BEST_CASE;   

}

int main(void){

    int size; 
    int countSorts = 10;
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

        printf("\nLoop Sorts:\n");
        printf("Atualmente cada Sort eh feito %d vezes.\n", countSorts);
        printf("(5) - Select Sort\n");

        printf("(-1) - Mudar a quantidade de vezes\n");
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

        case -1:
            clearScreen();
            printf("Quantas vezes cada algoritmo deve ser feito?\n");
            scanf("%d", &countSorts);
            clearScreen();
            break;

        case 1:
            bestCase(vetor, size);
                printf("Concluido - Preenchimento Crescente\n");
                flag = BEST_CASE;
            pressAnything();
            clearScreen();
            break;

        case 2:
            worstCase(vetor, size);
                printf("Concluido - Preenchimento Decrescente\n");
                flag = WORST_CASE;
            pressAnything();
            clearScreen();
            break;

        case 3:
            randomCase(vetor, size);
                printf("Concluido - Preenchimento Random\n");
                flag = RANDOM_CASE;
            pressAnything();
            clearScreen();

            break;

        case 4:
            showVetor(vetor, size);
            pressAnything();
            clearScreen();
            break;

        case 5:
            selectionSortRepeatMenu(vetor, size, countSorts);
            pressAnything();
            clearScreen();
            break;
        
        default:
            printf("\nInvalid option\n");
            break;
        }
 
    }

}