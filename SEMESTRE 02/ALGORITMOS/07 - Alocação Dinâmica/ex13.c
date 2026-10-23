#include <stdio.h>
#include <stdlib.h>

void liberaMatriz(int **matriz, int linhas) {
    int i;
    for (i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int **alocaMatriz(int linhas, int colunas) {
    int i;
    int **matriz;

    matriz = (int **) malloc(linhas * sizeof(int *));
    if (matriz == NULL) {
        return NULL;
    }

    for (i = 0; i < linhas; i++) {
        matriz[i] = (int *) malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            liberaMatriz(matriz, i);
            return NULL;
        }
    }

    return matriz;
}

void mostraMatriz(int **matriz, int linhas, int colunas) {
    int i, j;
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%5d", matriz[i][j]);
        }
        printf("\n");
    }
}

void tresMaiores(int **matriz, int linhas, int colunas) {
    int maior[3], lin[3], col[3];
    int qtd = 0, i, j, k, pos;

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            pos = 0;
            while (pos < qtd && maior[pos] >= matriz[i][j]) {
                pos++;
            }
            if (pos < 3) {
                if (qtd < 3) {
                    k = qtd;
                    qtd++;
                } else {
                    k = 2;
                }
                for (; k > pos; k--) {
                    maior[k] = maior[k - 1];
                    lin[k] = lin[k - 1];
                    col[k] = col[k - 1];
                }
                maior[pos] = matriz[i][j];
                lin[pos] = i;
                col[pos] = j;
            }
        }
    }

    for (k = 0; k < qtd; k++) {
        printf("%do maior: %d (linha %d, coluna %d)\n", k + 1, maior[k], lin[k], col[k]);
    }
}

int main() {
    int n, m, i, j;
    int **matriz, **transposta;

    printf("Digite o numero de linhas (N): ");
    scanf("%d", &n);
    printf("Digite o numero de colunas (M): ");
    scanf("%d", &m);

    matriz = alocaMatriz(n, m);
    if (matriz == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    transposta = alocaMatriz(m, n);
    if (transposta == NULL) {
        printf("Erro ao alocar memoria.\n");
        liberaMatriz(matriz, n);
        return 1;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("matriz[%d][%d] = ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }

    printf("\nMatriz %d x %d:\n", n, m);
    mostraMatriz(matriz, n, m);

    printf("\nTransposta %d x %d:\n", m, n);
    mostraMatriz(transposta, m, n);

    printf("\nTres maiores numeros da primeira matriz:\n");
    tresMaiores(matriz, n, m);

    liberaMatriz(matriz, n);
    liberaMatriz(transposta, m);

    return 0;
}
