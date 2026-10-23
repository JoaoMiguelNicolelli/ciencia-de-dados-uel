#include <stdio.h>
#include "pilha.h"

void decimalParaBinario(int numero) {
    Pilha* pilha = criarPilha();
    int resto;

    if (numero == 0) {
        printf("0\n");
        destruirPilha(pilha);
        return;
    }

    while (numero > 0) {
        resto = numero % 2;
        empilhar(pilha, resto);
        numero = numero / 2;
    }

    while (!pilhaVazia(pilha)) {
        desempilhar(pilha, &resto);
        printf("%d", resto);
    }

    printf("\n");

    destruirPilha(pilha);
}

int main() {
    int numero;

    printf("Digite um numero decimal: ");
    scanf("%d", &numero);

    decimalParaBinario(numero);

    return 0;
}