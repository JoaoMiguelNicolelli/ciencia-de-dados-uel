#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ler_texto(void);
char** separar_palavras(const char *texto, int *qtd);
void ordenar_palavras(char **palavras, int qtd);
void liberar_palavras(char **palavras, int qtd);

char* ler_texto(void) {
    int capacidade = 16, tam = 0, c;
    char *texto, *aux;

    texto = (char *) malloc(capacidade * sizeof(char));
    if (texto == NULL) {
        return NULL;
    }

    c = getchar();
    while (c != '\n' && c != EOF) {
        if (tam == capacidade) {
            capacidade = capacidade * 2;
            aux = (char *) realloc(texto, capacidade * sizeof(char));
            if (aux == NULL) {
                free(texto);
                return NULL;
            }
            texto = aux;
        }
        texto[tam] = c;
        tam++;
        c = getchar();
    }

    aux = (char *) realloc(texto, (tam + 1) * sizeof(char));
    if (aux == NULL) {
        free(texto);
        return NULL;
    }
    texto = aux;
    texto[tam] = '\0';

    return texto;
}

int ehSeparador(char c) {
    return c == ' ' || c == ',' || c == '.';
}

char** separar_palavras(const char *texto, int *qtd) {
    int i, j, k, inicio, tam;
    char **palavras;

    *qtd = 0;
    i = 0;
    while (texto[i] != '\0') {
        while (texto[i] != '\0' && ehSeparador(texto[i])) {
            i++;
        }
        if (texto[i] != '\0') {
            (*qtd)++;
            while (texto[i] != '\0' && !ehSeparador(texto[i])) {
                i++;
            }
        }
    }

    if (*qtd == 0) {
        return NULL;
    }

    palavras = (char **) malloc(*qtd * sizeof(char *));
    if (palavras == NULL) {
        *qtd = 0;
        return NULL;
    }

    k = 0;
    i = 0;
    while (texto[i] != '\0') {
        while (texto[i] != '\0' && ehSeparador(texto[i])) {
            i++;
        }
        if (texto[i] != '\0') {
            inicio = i;
            while (texto[i] != '\0' && !ehSeparador(texto[i])) {
                i++;
            }
            tam = i - inicio;

            palavras[k] = (char *) malloc((tam + 1) * sizeof(char));
            if (palavras[k] == NULL) {
                liberar_palavras(palavras, k);
                *qtd = 0;
                return NULL;
            }
            for (j = 0; j < tam; j++) {
                palavras[k][j] = texto[inicio + j];
            }
            palavras[k][tam] = '\0';
            k++;
        }
    }

    return palavras;
}

void ordenar_palavras(char **palavras, int qtd) {
    int i, j;
    char *aux;
    for (i = 0; i < qtd - 1; i++) {
        for (j = 0; j < qtd - 1 - i; j++) {
            if (strcmp(palavras[j], palavras[j + 1]) > 0) {
                aux = palavras[j];
                palavras[j] = palavras[j + 1];
                palavras[j + 1] = aux;
            }
        }
    }
}

void liberar_palavras(char **palavras, int qtd) {
    int i;
    for (i = 0; i < qtd; i++) {
        free(palavras[i]);
    }
    free(palavras);
}

int main() {
    int qtd, i;
    char *texto;
    char **palavras;

    printf("Digite um texto: ");
    texto = ler_texto();
    if (texto == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    palavras = separar_palavras(texto, &qtd);
    if (palavras == NULL) {
        printf("Nenhuma palavra encontrada.\n");
        free(texto);
        return 0;
    }

    printf("Quantidade de palavras: %d\n", qtd);

    ordenar_palavras(palavras, qtd);

    printf("Palavras em ordem alfabetica: ");
    for (i = 0; i < qtd; i++) {
        printf("%s", palavras[i]);
        if (i < qtd - 1) {
            printf(", ");
        }
    }
    printf("\n");

    liberar_palavras(palavras, qtd);
    free(texto);

    return 0;
}
