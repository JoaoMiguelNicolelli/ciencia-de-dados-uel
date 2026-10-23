#include <stdio.h>
#include <stdlib.h>

int *aumentaVetor(int *vetor, int qtd, int novoTamanho) {
    int i;
    int *novo;

    novo = (int *) malloc(novoTamanho * sizeof(int));
    if (novo == NULL) {
        return NULL;
    }

    for (i = 0; i < qtd; i++) {
        novo[i] = vetor[i];
    }
    free(vetor);

    return novo;
}

int main() {
    int tamanho = 10, qtd = 0, numero, i;
    int *vetor, *novo;

    vetor = (int *) malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    printf("Digite os numeros (0 para encerrar):\n");
    scanf("%d", &numero);

    while (numero != 0) {
        if (qtd == tamanho) {
            novo = aumentaVetor(vetor, qtd, tamanho + 10);
            if (novo == NULL) {
                printf("Erro ao alocar memoria.\n");
                free(vetor);
                return 1;
            }
            vetor = novo;
            tamanho = tamanho + 10;
            printf("Vetor aumentado para %d posicoes.\n", tamanho);
        }
        vetor[qtd] = numero;
        qtd++;
        scanf("%d", &numero);
    }

    printf("\nForam digitados %d numeros (tamanho do vetor: %d):\n", qtd, tamanho);
    for (i = 0; i < qtd; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);

    return 0;
}
