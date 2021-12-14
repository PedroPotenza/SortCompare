#include "header.h"
#include "util.c"

FlagCase flag = NA;

void SortRepeatMenu(int* vetor, int size, int countSort, int SortChosen){

    clearScreen();
    printf("\nRepita %d vezes com qual caso inicial?\n", countSort);
    printf("(1) - Crescente (melhor caso)\n");
    printf("(2) - Decrescente (pior caso)\n");
    printf("(3) - Aleatorio\n");

    int option;
    scanf("%d", &option);

    char name[15];
    long time_spent = 0, time_spend_interation;
    unsigned long long numberComparisons = 0;

    long* vetorDesvioPadrao = NULL;
    vetorDesvioPadrao = malloc(size*sizeof(int));

    for (int i = 0; i < countSort; i++)
    {
        if(option == 1){
            bestCase(vetor, size);
            flag = BEST_CASE;
        }

        if(option == 2){
            worstCase(vetor, size);
            flag = WORST_CASE;
        }

        if(option == 3){
            randomCase(vetor, size);
            flag = RANDOM_CASE;
        }

        switch(SortChosen){

            case 5:
                time_spend_interation = selectionSort(vetor, size, &numberComparisons);
                strcpy(name,"SELECTION");
                break;

            case 6:
                time_spend_interation = insertionSort(vetor, size, &numberComparisons);
                strcpy(name,"INSERTION");
                break;

            case 7:
                time_spend_interation = mergeSort(vetor, size, &numberComparisons);
                strcpy(name,"MERGE");
                break;
            case 8:
                time_spend_interation = quickSort(vetor, 0, size-1, &numberComparisons);
                strcpy(name,"QUICK");
                break;
            case 9:
                time_spend_interation = heapSort(vetor, size, &numberComparisons);
                strcpy(name,"HEAP");
                break;

        }

        printf("[ %d ] Tempo gasto:  %lf\n", i, time_spend_interation/1000000.0);

        vetorDesvioPadrao[i] = time_spend_interation;

        time_spent += time_spend_interation;
    }

    double avarage_time = (time_spent/(countSort*1.0));
    double desvioPadrao = 0.0;

    for (int i = 0; i < countSort; i++) {
        desvioPadrao = desvioPadrao + pow(vetorDesvioPadrao[i] - avarage_time, 2);
    }

    printf("======= %s SORT ======= \n", name);
    printf("Quantas vezes o sort foi feito? %d\n", countSort);
    printf("Tamanho do vetor: %d\n", size);
    printf("Como ele estava sendo preenchido? ");
    FlagPrinter(flag);
    printf("\nMedia do Tempo gasto:  %lf\n", avarage_time/1000000.0);
    printf("Desvio padrao do tempo gasto:  %lf\n", sqrt(desvioPadrao/countSort) / 1000000.0);
    printf("Media do Numero de comparacoes: %lld\n", numberComparisons/countSort);

    flag = BEST_CASE;   

}

int main(void){

    int size; 
    int countSorts = 3;
    int* vetor = NULL;
    srand(time(NULL)); //every execute has a diferent seed, so rand is truly random ;) 

    printf("\nTamanho do vetor: ");
    scanf("%d", &size);

    vetor = malloc(size*sizeof(int));

    int sair = false;
    while(!sair){ 

        showMenu(countSorts);
        
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

        case 5: case 6: case 7: case 8: case 9:
            SortRepeatMenu(vetor, size, countSorts, option);
            pressAnything();
            clearScreen();
            break;
        
        default:
            printf("\nInvalid option\n");
            break;
        }
 
    }

}