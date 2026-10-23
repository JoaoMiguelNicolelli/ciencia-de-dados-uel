#include <stdio.h>

void inverteVetor(int v[], int tam){

    int aux;

    for(int i = 0; i < tam / 2; i++){

        aux = v[i];
        v[i] = v[tam - 1 - i];
        v[tam - 1 - i] = aux;
    }
}

int main(){

    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    inverteVetor(vetor, tamanho);

    printf("Vetor invertido: ");

    for(int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}