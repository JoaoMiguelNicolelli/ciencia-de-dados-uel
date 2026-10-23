#include <stdio.h>
#include "pilha_dupla.h"

int main() {
    PilhaDupla* pilha = criarPilhaDupla();
    char elemento;

    if (pilha == NULL) {
        printf("Erro ao criar pilha dupla.\n");
        return 1;
    }

    if (empilhar(pilha, 'A', 1)) {
        printf("A empilhado na pilha 1.\n");
    }

    if (empilhar(pilha, 'B', 1)) {
        printf("B empilhado na pilha 1.\n");
    }

    if (empilhar(pilha, 'X', 2)) {
        printf("X empilhado na pilha 2.\n");
    }

    if (empilhar(pilha, 'Y', 2)) {
        printf("Y empilhado na pilha 2.\n");
    }

    if (desempilhar(pilha, &elemento, 1)) {
        printf("Desempilhado da pilha 1: %c\n", elemento);
    }

    if (desempilhar(pilha, &elemento, 2)) {
        printf("Desempilhado da pilha 2: %c\n", elemento);
    }

    if (pilhaVazia(pilha, 1)) {
        printf("Pilha 1 esta vazia.\n");
    } else {
        printf("Pilha 1 nao esta vazia.\n");
    }

    if (pilhaVazia(pilha, 2)) {
        printf("Pilha 2 esta vazia.\n");
    } else {
        printf("Pilha 2 nao esta vazia.\n");
    }

    destruirPilhaDupla(pilha);

    return 0;
}