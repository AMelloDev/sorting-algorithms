#include <stdio.h>

void insertSort(int vetor[], int tamanho){
    for (int i = 0; i < tamanho; i++) {
       int eleito= vetor[i];
       int j= i -1;
       while(j>= 0 && eleito < vetor[j]){
           vetor[j+1]= vetor[j]; // empurra o inicial para uma posição Depois
           j--; // volta o j para a primeira posição para ver onde o eleito deve estar
       }
        vetor[j+1]= eleito;
    }
}

void imprimeVetor(int vetor[], int tamanho){
    for (int i = 0; i < tamanho; i++) {
        printf("%d", vetor[i]);
        printf("\n");
    }
}

int main()
{
    int tamanho = 5;
    int vetor[5];
    
    for (int i = 0; i < tamanho; i++) {
        printf("digite o %dº valor:", i+1);
        scanf("%d", &vetor[i]);
        printf("\n");
    }
    
    printf("Antes da ordenação: ");
    imprimeVetor(vetor, tamanho);
    
    insertSort(vetor, tamanho);
     
    printf("Depois da ordenação: ");
    imprimeVetor(vetor, tamanho);

    return 0;
}