#include "header.h"

void showMenu(int countSorts){

    printf("\nComo preencher o vetor?\n");
    printf("(1) - Crescente (melhor caso)\n");
    printf("(2) - Decrescente (pior caso)\n");
    printf("(3) - Aleatorio\n");

    printf("\nFuncoes Uteis:\n");
    printf("(4) - Imprimir vetor\n");

    printf("\nLoop Sorts:\n");
    printf("Atualmente cada Sort eh feito %d vezes.\n", countSorts);
    printf("(-1) - Mudar a quantidade de vezes\n\n");

    printf("(5) - Select Sort\n");
    printf("(6) - Insertion Sort\n");
    printf("(7) - Merge Sort\n");
    printf("(8) - Quick Sort\n");
    printf("(9) - Heap Sort\n");

    
    printf("\n(0) - Sair\n");

}

void pressAnything(){

    printf("\nPressione qualquer coisa...");
    // getch();
}

void clearScreen(){
    // system("@cls||clear");
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
        vetor[i] = (rand() % RAND_MAX);
    }
    
}

void showVetor(int* vetor, int size){
    for (int i = 0; i < size; i++){
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }
}

void FlagPrinter(FlagCase flag){

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