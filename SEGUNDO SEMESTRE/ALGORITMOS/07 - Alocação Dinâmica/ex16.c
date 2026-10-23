#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct cidade {
    char nome[50];
    float x;
    float y;
};

void lerCidades(struct cidade *cidades, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\nCidade %d\n", i + 1);
        printf("Nome: ");
        scanf(" %49[^\n]", cidades[i].nome);
        printf("Coordenada X: ");
        scanf("%f", &cidades[i].x);
        printf("Coordenada Y: ");
        scanf("%f", &cidades[i].y);
    }
}

void liberaMatriz(float **matriz, int linhas) {
    int i;
    for (i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

float **alocaMatriz(int n) {
    int i;
    float **matriz;

    matriz = (float **) malloc(n * sizeof(float *));
    if (matriz == NULL) {
        return NULL;
    }

    for (i = 0; i < n; i++) {
        matriz[i] = (float *) malloc(n * sizeof(float));
        if (matriz[i] == NULL) {
            liberaMatriz(matriz, i);
            return NULL;
        }
    }

    return matriz;
}

void calculaDistancias(struct cidade *cidades, float **dist, int n) {
    int i, j;
    float dx, dy;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            dx = cidades[i].x - cidades[j].x;
            dy = cidades[i].y - cidades[j].y;
            dist[i][j] = sqrt(dx * dx + dy * dy);
        }
    }
}

void mostraDistancias(struct cidade *cidades, float **dist, int n) {
    int i, j;

    printf("%12s", "");
    for (j = 0; j < n; j++) {
        printf("%12.11s", cidades[j].nome);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("%12.11s", cidades[i].nome);
        for (j = 0; j < n; j++) {
            printf("%12.2f", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    struct cidade *cidades;
    float **dist;

    printf("Digite a quantidade de cidades: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    cidades = (struct cidade *) malloc(n * sizeof(struct cidade));
    if (cidades == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    dist = alocaMatriz(n);
    if (dist == NULL) {
        printf("Erro ao alocar memoria.\n");
        free(cidades);
        return 1;
    }

    lerCidades(cidades, n);
    calculaDistancias(cidades, dist, n);

    printf("\nMatriz de distancias:\n");
    mostraDistancias(cidades, dist, n);

    liberaMatriz(dist, n);
    free(cidades);

    return 0;
}
