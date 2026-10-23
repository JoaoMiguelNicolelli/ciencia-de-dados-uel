#ifndef PILHA_DUPLA_H
#define PILHA_DUPLA_H

#include <stdbool.h>

#define MAX 100

typedef char Item;

typedef struct PilhaDupla PilhaDupla;

PilhaDupla* criarPilhaDupla();
void destruirPilhaDupla(PilhaDupla* pilha);

bool empilhar(PilhaDupla* pilha, Item elemento, int numeroPilha);
bool desempilhar(PilhaDupla* pilha, Item* elemento, int numeroPilha);
bool pilhaVazia(const PilhaDupla* pilha, int numeroPilha);

#endif