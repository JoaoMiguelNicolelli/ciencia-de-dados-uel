#include <stdio.h>

void imprime_vetor(int *vet, int tam){
    int *p = vet;
    int *fim = vet + tam;

    printf("[ ");
    while (p < fim) {
        printf("%d ", *p);
        p++;
    }
    printf("]\n");
}

int main(){
    int tamanho;

    printf("Quantos elementos? ");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i);
        scanf("%d", &vetor[i]);
    }

    printf("\nVetor digitado: ");
    imprime_vetor(vetor, tamanho);

    return 0;
}