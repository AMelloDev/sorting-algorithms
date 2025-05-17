
#include <stdio.h>


int particiona(int vetor[], int inicial, int final){
    int i = inicial + 1; // marca o início do vetor depois do pivo
    int j = final;
    int pivo = vetor[inicial]; 
    while(i<=j){//eles vão sendo movimentados em direção um ao outro, enquanto isso ocorrer...
        while(vetor[i]<= pivo){//enquanto o elemento atual for menor que o pivo...
            i++;
        }
        while(vetor[j]>pivo){
            j--;
        }
         if (i < j) {
            int aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    }
    vetor[inicial] = vetor[j];
    vetor[j]= pivo;
    
    
    return j;
}
void quickSort(int vetor[], int inicial, int final){
    if(inicial < final){
        int p = particiona(vetor, inicial, final);
        quickSort(vetor, inicial, p-1);// ordena a porção esquerda
        quickSort(vetor, p+1, final);
    }
    
}


int main()
{
    int vetor[7] = {8, 4, 7, 3, 10, 2, 6};
    int tamanho = 7;

    printf("antes da ordenação\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", vetor[i]);
    }

    quickSort(vetor, 0, tamanho-1);
    
    printf("\ndepois da ordenação\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d\n", vetor[i]);
    }
    return 0;
}
