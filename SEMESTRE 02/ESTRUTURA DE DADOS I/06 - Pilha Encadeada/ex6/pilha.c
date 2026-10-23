#include <stdlib.h>
#include "pilha.h"

typedef struct No {
    int elemento;
    struct No* proximo;
} No;

struct Pilha {
    No* topo;
};

Pilha* criarPilha() {
    Pilha* pilha = malloc(sizeof(Pilha));

    if (pilha == NULL) {
        return NULL;
    }

    pilha->topo = NULL;

    return pilha;
}

void destruirPilha(Pilha* pilha) {
    No* atual = pilha->topo;

    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    free(pilha);
}

bool pilhaVazia(const Pilha* pilha) {
    return pilha->topo == NULL;
}

bool empilhar(Pilha* pilha, int elemento) {
    No* novo = malloc(sizeof(No));

    if (novo == NULL) {
        return false;
    }

    novo->elemento = elemento;
    novo->proximo = pilha->topo;
    pilha->topo = novo;

    return true;
}

bool desempilhar(Pilha* pilha, int* elemento) {
    if (pilhaVazia(pilha)) {
        return false;
    }

    No* removido = pilha->topo;
    *elemento = removido->elemento;
    pilha->topo = removido->proximo;
    free(removido);

    return true;
}

bool consultarTopo(const Pilha* pilha, int* elemento) {
    if (pilhaVazia(pilha)) {
        return false;
    }

    *elemento = pilha->topo->elemento;

    return true;
}
