#include <stdlib.h>
#include "pilha_dupla.h"

struct PilhaDupla {
    Item elementos[MAX];
    int topo1;
    int topo2;
};

PilhaDupla* criarPilhaDupla() {
    PilhaDupla* pilha = malloc(sizeof(PilhaDupla));

    if (pilha == NULL) {
        return NULL;
    }

    pilha->topo1 = -1;
    pilha->topo2 = MAX;

    return pilha;
}

void destruirPilhaDupla(PilhaDupla* pilha) {
    free(pilha);
}

bool pilhaVazia(const PilhaDupla* pilha, int numeroPilha) {
    if (numeroPilha == 1) {
        return pilha->topo1 == -1;
    }

    if (numeroPilha == 2) {
        return pilha->topo2 == MAX;
    }

    return false;
}

bool empilhar(PilhaDupla* pilha, Item elemento, int numeroPilha) {
    if (pilha->topo1 + 1 == pilha->topo2) {
        return false;
    }

    if (numeroPilha == 1) {
        pilha->topo1++;
        pilha->elementos[pilha->topo1] = elemento;

        return true;
    }

    if (numeroPilha == 2) {
        pilha->topo2--;
        pilha->elementos[pilha->topo2] = elemento;

        return true;
    }

    return false;
}

bool desempilhar(PilhaDupla* pilha, Item* elemento, int numeroPilha) {
    if (numeroPilha == 1) {
        if (pilhaVazia(pilha, 1)) {
            return false;
        }

        *elemento = pilha->elementos[pilha->topo1];
        pilha->topo1--;

        return true;
    }

    if (numeroPilha == 2) {
        if (pilhaVazia(pilha, 2)) {
            return false;
        }

        *elemento = pilha->elementos[pilha->topo2];
        pilha->topo2++;

        return true;
    }

    return false;
}