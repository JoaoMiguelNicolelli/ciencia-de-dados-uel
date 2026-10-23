#include <stdlib.h>
#include "pilha.h"

struct Pilha {
    int elementos[MAX];
    int topo;
};

Pilha* criarPilha() {
    Pilha* pilha = malloc(sizeof(Pilha));

    if (pilha == NULL) {
        return NULL;
    }

    pilha->topo = -1;

    return pilha;
}

void destruirPilha(Pilha* pilha) {
    free(pilha);
}

bool pilhaCheia(const Pilha* pilha) {
    return pilha->topo == MAX - 1;
}

bool pilhaVazia(const Pilha* pilha) {
    return pilha->topo == -1;
}

bool empilhar(Pilha* pilha, int elemento) {
    if (pilhaCheia(pilha)) {
        return false;
    }

    pilha->topo++;
    pilha->elementos[pilha->topo] = elemento;

    return true;
}

bool desempilhar(Pilha* pilha, int* elemento) {
    if (pilhaVazia(pilha)) {
        return false;
    }

    *elemento = pilha->elementos[pilha->topo];
    pilha->topo--;

    return true;
}

bool consultarTopo(const Pilha* pilha, int* elemento) {
    if (pilhaVazia(pilha)) {
        return false;
    }

    *elemento = pilha->elementos[pilha->topo];

    return true;
}