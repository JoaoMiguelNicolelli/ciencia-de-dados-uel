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

void inverte_vetor(int *vet, int tam){
    int *ini = vet;
    int *fim = vet + tam - 1;

    while (ini < fim) {
        int aux = *ini;
        *ini = *fim;
        *fim = aux;
        ini++;
        fim--;
    }
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

    printf("\nVetor antes: ");
    imprime_vetor(vetor, tamanho);

    inverte_vetor(vetor, tamanho);

    printf("Vetor depois: ");
    imprime_vetor(vetor, tamanho);

    return 0;
}
