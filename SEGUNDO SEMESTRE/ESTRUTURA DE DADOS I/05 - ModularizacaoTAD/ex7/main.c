#include <stdio.h>
#include <string.h>
#include "pilha.h"

bool palindromo(const char* cadeia) {
    Pilha* pilha = criarPilha();
    char caractere;
    int tamanho = strlen(cadeia);

    if (pilha == NULL) {
        return false;
    }

    for (int i = 0; i < tamanho; i++) {
        empilhar(pilha, cadeia[i]);
    }

    for (int i = 0; i < tamanho; i++) {
        desempilhar(pilha, &caractere);

        if (caractere != cadeia[i]) {
            destruirPilha(pilha);
            return false;
        }
    }

    destruirPilha(pilha);

    return true;
}

int main() {
    char cadeia[MAX];

    printf("Digite uma cadeia: ");
    scanf("%s", cadeia);

    if (palindromo(cadeia)) {
        printf("E palindromo.\n");
    } else {
        printf("Nao e palindromo.\n");
    }

    return 0;
}