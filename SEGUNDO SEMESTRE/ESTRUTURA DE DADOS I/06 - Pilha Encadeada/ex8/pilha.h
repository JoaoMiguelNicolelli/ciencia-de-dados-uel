#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

typedef struct Pilha Pilha;

Pilha* criarPilha();
void destruirPilha(Pilha* pilha);

bool pilhaVazia(const Pilha* pilha);

bool empilhar(Pilha* pilha, int elemento);
bool desempilhar(Pilha* pilha, int* elemento);
bool consultarTopo(const Pilha* pilha, int* elemento);

#endif
