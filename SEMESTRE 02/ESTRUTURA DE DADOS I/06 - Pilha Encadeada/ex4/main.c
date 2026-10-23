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

    printf("Pilha (topo -> base): ");
    exibirPilha(pilha);

    esvaziarPilha(pilha);

    printf("Apos esvaziar: ");
    exibirPilha(pilha);

    empilhar(pilha, 5);
    empilhar(pilha, 15);

    printf("Reutilizando a pilha: ");
    exibirPilha(pilha);

    destruirPilha(pilha);

    return 0;
}
