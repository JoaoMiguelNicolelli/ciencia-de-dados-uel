#include <stdlib.h>
#include "conjunto_inteiros.h"

struct ConjuntoInteiros {
    int elementos[MAX];
    int quantidade;
};

ConjuntoInteiros* criarConjunto() {
    ConjuntoInteiros* conjunto = malloc(sizeof(ConjuntoInteiros));

    if (conjunto == NULL)
        return NULL;

    conjunto->quantidade = 0;

    return conjunto;
}

void destruirConjunto(ConjuntoInteiros* conjunto) {
    free(conjunto);
}

bool pertence(const ConjuntoInteiros* conjunto, int elemento) {
    for (int i = 0; i < conjunto->quantidade; i++) {
        if (conjunto->elementos[i] == elemento)
            return true;
    }

    return false;
}

bool inserir(ConjuntoInteiros* conjunto, int elemento) {
    if (conjunto->quantidade == MAX)
        return false;

    if (pertence(conjunto, elemento))
        return false;

    conjunto->elementos[conjunto->quantidade] = elemento;
    conjunto->quantidade++;

    return true;
}

bool remover(ConjuntoInteiros* conjunto, int elemento) {
    for (int i = 0; i < conjunto->quantidade; i++) {
        if (conjunto->elementos[i] == elemento) {
            conjunto->elementos[i] =
                conjunto->elementos[conjunto->quantidade - 1];

            conjunto->quantidade--;

            return true;
        }
    }

    return false;
}

int cardinalidade(const ConjuntoInteiros* conjunto) {
    return conjunto->quantidade;
}