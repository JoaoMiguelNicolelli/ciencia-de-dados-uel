#include <stdio.h>

void somaVetores(int v1[], int v2[], int v3[], int tamanho){

    for(int i = 0; i < tamanho; i++){
        v3[i] = v1[i] + v2[i];
    }
}

int main (){

    int tam;
    printf("Tamanho dos vetores: ");
    scanf("%d", &tam);

    printf("\n");

    int vetor1[tam], vetor2[tam], vetor3[tam];

    for(int i = 0; i < tam; i++){
        printf("Elemento %d do vetor 1: ", i+1);
        scanf("%d", &vetor1[i]);
    }

    printf("\n");

    for(int i = 0; i < tam; i++){
        printf("Elemento %d do vetor 2: ", i+1);
        scanf("%d", &vetor2[i]);
    }

    somaVetores(vetor1, vetor2, vetor3, tam);

    printf("\nSoma dos Vetores: ");
    for(int i = 0; i < tam; i++){
        printf("%d ", vetor3[i]);
    }

    return 0;
}