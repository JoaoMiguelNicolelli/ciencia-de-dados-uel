#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha* pilha = criarPilha();

    if (pilha == NULL) {
        printf("Erro ao criar pilha.\n");
        return 1;
    }

    empilhar(pilha, 10);
    empilhar(pilha, 20);
    empilhar(pilha, 30);
    empilhar(pilha, 40);

    printf("Pilha:\n");
    exibirPilha(pilha);

    destruirPilha(pilha);

    return 0;
}