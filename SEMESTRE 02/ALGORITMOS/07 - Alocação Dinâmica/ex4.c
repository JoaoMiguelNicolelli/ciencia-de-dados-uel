#include <stdio.h>
#include <stdlib.h>

int buscaValor(int **matriz, int linhas, int colunas, int valor) {
    int i, j;
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            if (matriz[i][j] == valor) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int linhas, colunas, valor, i, j;
    int **matriz;

    printf("Digite o numero de linhas: ");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas: ");
    scanf("%d", &colunas);

    matriz = (int **) malloc(linhas * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (i = 0; i < linhas; i++) {
        matriz[i] = (int *) malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memoria.\n");
            return 1;
        }
    }

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("matriz[%d][%d] = ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Digite o valor a ser buscado: ");
    scanf("%d", &valor);

    if (buscaValor(matriz, linhas, colunas, valor) == 1) {
        printf("O valor %d ESTA na matriz.\n", valor);
    } else {
        printf("O valor %d NAO esta na matriz.\n", valor);
    }

    for (i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}