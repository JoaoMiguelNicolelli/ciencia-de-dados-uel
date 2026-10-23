#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QTD_SORTEIO 20

void ler_aposta(int *aposta, int n) {
    int i;
    for (i = 0; i < n; i++) {
        do {
            printf("Numero %d (0 a 100): ", i + 1);
            scanf("%d", &aposta[i]);
            if (aposta[i] < 0 || aposta[i] > 100) {
                printf("Numero invalido.\n");
            }
        } while (aposta[i] < 0 || aposta[i] > 100);
    }
}

void sorteia_valores(int *sorteio, int n) {
    int i;
    for (i = 0; i < n; i++) {
        sorteio[i] = rand() % 101;
    }
}

int estaNoVetor(int *vetor, int n, int valor) {
    int i;
    for (i = 0; i < n; i++) {
        if (vetor[i] == valor) {
            return 1;
        }
    }
    return 0;
}

int* compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns) {
    int i, k;
    int *acertos;

    *qtdacertos = 0;
    for (i = 0; i < na; i++) {
        if (estaNoVetor(sorteio, ns, aposta[i]) == 1) {
            (*qtdacertos)++;
        }
    }

    if (*qtdacertos == 0) {
        return NULL;
    }

    acertos = (int *) malloc(*qtdacertos * sizeof(int));
    if (acertos == NULL) {
        return NULL;
    }

    k = 0;
    for (i = 0; i < na; i++) {
        if (estaNoVetor(sorteio, ns, aposta[i]) == 1) {
            acertos[k] = aposta[i];
            k++;
        }
    }

    return acertos;
}

int main() {
    int na, qtdacertos, i;
    int *aposta, *sorteio, *acertos;

    srand(time(NULL));

    do {
        printf("Quantos numeros deseja apostar (1 a 20)? ");
        scanf("%d", &na);
    } while (na < 1 || na > 20);

    aposta = (int *) malloc(na * sizeof(int));
    if (aposta == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    sorteio = (int *) malloc(QTD_SORTEIO * sizeof(int));
    if (sorteio == NULL) {
        printf("Erro ao alocar memoria.\n");
        free(aposta);
        return 1;
    }

    ler_aposta(aposta, na);
    sorteia_valores(sorteio, QTD_SORTEIO);

    printf("\nNumeros sorteados: ");
    for (i = 0; i < QTD_SORTEIO; i++) {
        printf("%d ", sorteio[i]);
    }
    printf("\n");

    acertos = compara_aposta(aposta, sorteio, &qtdacertos, na, QTD_SORTEIO);
    if (qtdacertos > 0 && acertos == NULL) {
        printf("Erro ao alocar memoria.\n");
        free(aposta);
        free(sorteio);
        return 1;
    }

    printf("Quantidade de acertos: %d\n", qtdacertos);
    if (qtdacertos > 0) {
        printf("Numeros acertados: ");
        for (i = 0; i < qtdacertos; i++) {
            printf("%d ", acertos[i]);
        }
        printf("\n");
    }

    free(aposta);
    free(sorteio);
    free(acertos);

    return 0;
}
