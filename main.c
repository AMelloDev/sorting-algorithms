
#include <stdio.h>

  void bubbleSort(int vetor[], int tamanho){
        for (int i = 0; i < tamanho -1; i++) {
            for (int j = 0; j < tamanho -1 -i; j++) {
                if(vetor[j]> vetor[j+1]){
                    int aux = vetor[j];
                    vetor[j] = vetor[j+1];
                    vetor[j+1] = aux;
                }
            }
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
    int tamanho = 10;
    int vetor[10];
    
    for (int i = 0; i < tamanho; i++) {
        printf("digite o %dº valor:", i+1);
        scanf("%d", &vetor[i]);
        printf("\n");
    }
    
    printf("Antes da ordenação: ");
    imprimeVetor(vetor, tamanho);
    
    bubbleSort(vetor, tamanho);
     
    printf("Depois da ordenação: ");
    imprimeVetor(vetor, tamanho);

    return 0;
}