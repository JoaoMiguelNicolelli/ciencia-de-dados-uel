#include <stdio.h>
#include <stdlib.h>

int** gerar_pascal(int n);
int** expandir_pascal(int **t, int n_atual, int n_novo);
void imprimir_pascal(int **t, int n);
void liberar_pascal(int **t, int n);

void calculaLinha(int **t, int i) {
    int j;
    t[i][0] = 1;
    t[i][i] = 1;
    for (j = 1; j < i; j++) {
        t[i][j] = t[i - 1][j - 1] + t[i - 1][j];
    }
}

int** gerar_pascal(int n) {
    int i;
    int **t;

    t = (int **) malloc(n * sizeof(int *));
    if (t == NULL) {
        return NULL;
    }

    for (i = 0; i < n; i++) {
        t[i] = (int *) malloc((i + 1) * sizeof(int));
        if (t[i] == NULL) {
            liberar_pascal(t, i);
            return NULL;
        }
        calculaLinha(t, i);
    }

    return t;
}

int** expandir_pascal(int **t, int n_atual, int n_novo) {
    int i;
    int **novo;

    if (n_novo <= n_atual) {
        return t;
    }

    novo = (int **) realloc(t, n_novo * sizeof(int *));
    if (novo == NULL) {
        return NULL;
    }

    for (i = n_atual; i < n_novo; i++) {
        novo[i] = (int *) malloc((i + 1) * sizeof(int));
        if (novo[i] == NULL) {
            printf("Erro ao alocar memoria.\n");
            liberar_pascal(novo, i);
            exit(1);
        }
        calculaLinha(novo, i);
    }

    return novo;
}

void imprimir_pascal(int **t, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            printf("  ");
        }
        for (j = 0; j <= i; j++) {
            printf("%4d", t[i][j]);
        }
        printf("\n");
    }
}

void liberar_pascal(int **t, int n) {
    int i;
    for (i = 0; i < n; i++) {
        free(t[i]);
    }
    free(t);
}

int contaInteiros(int n) {
    int i, total = 0;
    for (i = 0; i < n; i++) {
        total = total + (i + 1);
    }
    return total;
}

int main() {
    int n = 5, total;
    int **t, **aux;

    t = gerar_pascal(n);
    if (t == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    printf("Triangulo com %d linhas:\n", n);
    imprimir_pascal(t, n);

    aux = expandir_pascal(t, n, 10);
    if (aux == NULL) {
        printf("Erro no realloc. O triangulo original foi mantido.\n");
    } else {
        t = aux;
        n = 10;
    }

    printf("\nTriangulo com %d linhas:\n", n);
    imprimir_pascal(t, n);

    total = contaInteiros(n);
    printf("\nInteiros alocados no triangulo: %d\n", total);
    printf("Inteiros usados por uma matriz 10 x 10: %d\n", 10 * 10);
    printf("Economia: %d inteiros\n", 10 * 10 - total);

    liberar_pascal(t, n);

    return 0;
}
