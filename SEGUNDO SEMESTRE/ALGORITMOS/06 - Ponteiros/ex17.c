#include <stdio.h>

int *maior_elemento(int *vet, int tam){
    int *p = vet;
    int *fim = vet + tam;
    int *maior = vet;

    while (p < fim) {
        if (*p > *maior) {
            maior = p;
        }
        p++;
    }

    return maior;
}

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
    int vetor[8];

    for (int i = 0; i < 8; i++) {
        printf("Elemento %d: ", i);
        scanf("%d", &vetor[i]);
    }

    int *p_maior = maior_elemento(vetor, 8);

    printf("\nMaior valor: %d\n", *p_maior);
    printf("Posicao: %d\n", (int)(p_maior - vetor));

    *p_maior = 0;

    printf("\nVetor atualizado: ");
    imprime_vetor(vetor, 8);

    return 0;
}
