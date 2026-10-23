#include <stdio.h>

void encontrarMaiorMenor(const int v[], int *min, int *max, int tam){

    if (tam <= 0) return;

    *min = v[0];
    *max = v[0];

    for(int i = 1; i < tam; i++){

        if(v[i] > *max){
            *max = v[i];
        }

         if(*min > v[i]){
            *min = v[i];
        }
    }
}

int main(){

    int tamanho;
    printf("Tamanho da lista: ");
    scanf("%d", &tamanho);

    int vetor[tamanho], menor, maior;

    for(int i = 0; i < tamanho; i++){
        printf("Elemento %d: ", i+1);
        scanf("%d", &vetor[i]);
    }
    
    encontrarMaiorMenor(vetor, &menor, &maior, tamanho);

    printf("Maior: %d\tMenor: %d\n", maior,  menor);

    return 0;
}