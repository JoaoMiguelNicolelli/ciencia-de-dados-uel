#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha* primeira = criarPilha();
    Pilha* segunda = criarPilha();

    if (primeira == NULL || segunda == NULL) {
        printf("Erro ao criar pilha.\n");
        return 1;
    }

    empilhar(primeira, 10);
    empilhar(primeira, 20);
    empilhar(primeira, 30);

    empilhar(segunda, 1);
    empilhar(segunda, 2);
    empilhar(segunda, 3);

    printf("Primeira pilha: ");
    exibirPilha(primeira);
    printf("Segunda pilha: ");
    exibirPilha(segunda);

    concatenarPilhas(primeira, segunda);

    printf("\nApos concatenar:\n");
    printf("Primeira pilha: ");
    exibirPilha(primeira);
    printf("Segunda pilha: ");
    exibirPilha(segunda);

    destruirPilha(primeira);
    destruirPilha(segunda);

    return 0;
}
