#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

#define MAX 100

typedef struct Pilha Pilha;

Pilha* criarPilha();
void destruirPilha(Pilha* pilha);

bool pilhaCheia(const Pilha* pilha);
bool pilhaVazia(const Pilha* pilha);

bool empilhar(Pilha* pilha, int elemento);
bool desempilhar(Pilha* pilha, int* elemento);
bool consultarTopo(const Pilha* pilha, int* elemento);

#endif