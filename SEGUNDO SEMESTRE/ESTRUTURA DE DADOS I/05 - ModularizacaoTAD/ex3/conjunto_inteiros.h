#ifndef CONJUNTO_INTEIROS_H
#define CONJUNTO_INTEIROS_H

#include <stdbool.h>

#define MAX 100

typedef struct ConjuntoInteiros ConjuntoInteiros;

ConjuntoInteiros* criarConjunto();
void destruirConjunto(ConjuntoInteiros* conjunto);

bool inserir(ConjuntoInteiros* conjunto, int elemento);
bool remover(ConjuntoInteiros* conjunto, int elemento);

bool pertence(const ConjuntoInteiros* conjunto, int elemento);
int cardinalidade(const ConjuntoInteiros* conjunto);

#endif