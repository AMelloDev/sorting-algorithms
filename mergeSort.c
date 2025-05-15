#include <stdio.h>



void intercala(int vetor[], int aux[], int inicial, int meio, int final){
    int esquerda = inicial; //marca o início da metade esquerda;
    int direita = meio + 1;
    int posicao_final = inicial;//aponta para o local onde o próximo número menor será colocado em Aux.
    
    while ((esquerda<= meio)&&(direita <= final)){//enquanto os dois arrays não chegarem em seus finais
       if(vetor[esquerda]<= vetor[direita]){/*compara um número do vetor esquerdo com um da direita*/
           aux[posicao_final] = vetor[esquerda];
           /*se o da esquerda for menor ele coloca no vetor auxiliar*/
           esquerda++;
           // move o ponteiro da esquerda para o próximo elemento
       } else {
           aux[posicao_final] = vetor[direita];
           direita++;
        }
       posicao_final++;//move o ponteiro da matriz ordenada
    }
    while(esquerda<= meio){//se ainda sobrou algo no lado esquerdo, esses elementos também sejam copiados para Aux
        aux[posicao_final] = vetor[esquerda];
        posicao_final++;
        esquerda++;
    }
    while(direita <=final){
        aux[posicao_final] = vetor[direita];
        posicao_final++;
        direita++;
    }
    while(inicial<= final){
        vetor[inicial]= aux[inicial];
        inicial++;
    }
}

void mergeSort(int vetor[], int aux[], int inicial, int final){
    if (inicial< final){//se ver que tem mais de um elemento nos sub-arrays
        int meio = (inicial + final)/2; //Divide o vetor ao meio
        mergeSort(vetor, aux, inicial, meio); // chama para continuar a dividir a metade da esquerda
        mergeSort(vetor, aux, meio+1, final); //chama para dividir a metade da esquerda
        intercala(vetor, aux,inicial, meio, final);//chama para ordenar os sub-arrays
    }
}
int main(){
   int tamanho;
   
   printf("Digite o tamanho do vetor: ");
   scanf("%d", &tamanho);
   
   int vetor[tamanho];
   int aux[tamanho];
   
   for (int i = 0; i < tamanho; i++) {
       printf("Digite o %dº elemento: ", i+1);
       scanf("%d", &vetor[i]);
   }
   
   mergeSort(vetor, aux, 0, tamanho-1);
   
   printf("Vetor ordenado:\n");
   for (int i = 0; i < tamanho; i++) {
       printf("%d", vetor[i]);
   }
   printf("\n");

    return 0;
}