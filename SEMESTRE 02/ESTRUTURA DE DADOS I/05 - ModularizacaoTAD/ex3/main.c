#include <stdio.h>
#include "conjunto_inteiros.h"

int main() {
    ConjuntoInteiros* conjunto = criarConjunto();

    if (conjunto == NULL) {
        printf("Erro ao criar conjunto.\n");
        return 1;
    }

    if (inserir(conjunto, 10)) {
        printf("10 inserido.\n");
    } else {
        printf("10 nao foi inserido.\n");
    }

    if (inserir(conjunto, 20)) {
        printf("20 inserido.\n");
    } else {
        printf("20 nao foi inserido.\n");
    }

    if (inserir(conjunto, 30)) {
        printf("30 inserido.\n");
    } else {
        printf("30 nao foi inserido.\n");
    }

    if (inserir(conjunto, 20)) {
        printf("20 inserido novamente.\n");
    } else {
        printf("20 ja pertence ao conjunto.\n");
    }

    printf("Cardinalidade: %d\n", cardinalidade(conjunto));

    if (pertence(conjunto, 10)) {
        printf("10 pertence ao conjunto.\n");
    } else {
        printf("10 nao pertence ao conjunto.\n");
    }

    if (pertence(conjunto, 50)) {
        printf("50 pertence ao conjunto.\n");
    } else {
        printf("50 nao pertence ao conjunto.\n");
    }

    if (remover(conjunto, 20)) {
        printf("20 removido.\n");
    } else {
        printf("20 nao pertence ao conjunto.\n");
    }

    if (remover(conjunto, 50)) {
        printf("50 removido.\n");
    } else {
        printf("50 nao pertence ao conjunto.\n");
    }

    printf("Cardinalidade apos remocao: %d\n",
           cardinalidade(conjunto));

    destruirConjunto(conjunto);

    return 0;
}