#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

#define MAX 100

typedef char Item;

typedef struct Pilha Pilha;

Pilha* criarPilha();
void destruirPilha(Pilha* pilha);

bool pilhaCheia(const Pilha* pilha);
bool pilhaVazia(const Pilha* pilha);

bool empilhar(Pilha* pilha, Item elemento);
bool desempilhar(Pilha* pilha, Item* elemento);
bool consultarTopo(const Pilha* pilha, Item* elemento);

void exibirPilha(const Pilha* pilha);

#endif