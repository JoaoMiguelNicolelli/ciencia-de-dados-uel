#include <stdio.h>

void somaVetor(const int v[], int tam, int *sum){

    int aux = 0;
    const int *ptr = v;

    for(int i = 0; i < tam; i++){
        aux += *ptr;
        ptr++;
    }

    *sum = aux;

}

int main(){

    int tamanho;
    printf("Tamanho da lista: ");
    scanf("%d", &tamanho);

    int vetor[tamanho], soma;

    for(int i = 0; i < tamanho; i++){
        printf("Elemento %d: ", i+1);
        scanf("%d", &vetor[i]);
    }

    somaVetor(vetor, tamanho, &soma);
    printf("Soma: %d", soma);

    return 0;
}