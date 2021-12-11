#include "header.h"
#include "util.c"

FlagCase flag = NA;

void SortRepeatMenu(int* vetor, int size, int countSort, int SortChosen){

    //clearScreen();
    printf("\nRepita %d vezes com qual caso inicial?\n", countSort);
    printf("(1) - Crescente (melhor caso)\n");
    printf("(2) - Decrescente (pior caso)\n");
    printf("(3) - Aleatorio\n");

    int option;
    scanf("%d", &option);

    char name[15];
    long time_spent = 0, time_spend_interation;
    long long numberComparisons = 0;

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
                // time_spend_interation = mergeSort(vetor, size, &numberComparisons);
                strcpy(name,"MERGE");
                break;

            case 8: 
                // time_spend_interation = quickSort(vetor, size, &numberComparisons);
                strcpy(name,"QUICK");
                break;

            case 9: 
                // time_spend_interation = heapSort(vetor, size, &numberComparisons);
                strcpy(name,"HEAP");
                break;

        }
 
        time_spent += time_spend_interation;

    }
    
    //Nao faco ideia de como calcular o desvio padrao desse role... provavelmente vamo ter q colocar um vetor do tipo long e salvar o tempo de cada iteracao nele, pra assim conseguir fazer o calculo (o calculo do desvio padrao exige a média do tempo por isso to falando q vamos precisar salvar a informacao de cada interacao... normalmente ela ta sendo descartada apos a soma no tempo total)

    // formula do desvio padrao https://www.todamateria.com.br/desvio-padrao/#:~:text=O%20desvio%20padrão%20é%20uma,mais%20homogêneo%20são%20os%20dados.

    printf("======= %s SORT ======= \n", name);
    printf("Quantas vezes o sort foi feito? %d\n", countSort);
    printf("Tamanho do vetor: %d\n", size);
    printf("Como ele estava sendo preenchido? ");
    FlagPrinter(flag);
    printf("\nTempo gasto na ultima iteracao:  %lf\n", time_spend_interation/1000000.0);
    printf("Media do Tempo gasto:  %lf\n", (time_spent/countSort)/1000000.0);
    printf("Media do Numero de comparacoes: %lld\n", numberComparisons/countSort);

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
           // clearScreen();
            printf("Quantas vezes cada algoritmo deve ser feito?\n");
            scanf("%d", &countSorts);
            //clearScreen();
            break;

        case 1:
            bestCase(vetor, size);
                printf("Concluido - Preenchimento Crescente\n");
                flag = BEST_CASE;
           // pressAnything();
            //clearScreen();
            break;

        case 2:
            worstCase(vetor, size);
                printf("Concluido - Preenchimento Decrescente\n");
                flag = WORST_CASE;
           // pressAnything();
            //clearScreen();
            break;

        case 3:
            randomCase(vetor, size);
                printf("Concluido - Preenchimento Random\n");
                flag = RANDOM_CASE;
            //pressAnything();
            //clearScreen();

            break;

        case 4:
            showVetor(vetor, size);
            //pressAnything();
            //clearScreen();
            break;

        case 5: case 6: case 7: case 8: case 9:
            SortRepeatMenu(vetor, size, countSorts, option);
            //pressAnything();
            //clearScreen();
            break;
        
        default:
            printf("\nInvalid option\n");
            break;
        }
 
    }

}