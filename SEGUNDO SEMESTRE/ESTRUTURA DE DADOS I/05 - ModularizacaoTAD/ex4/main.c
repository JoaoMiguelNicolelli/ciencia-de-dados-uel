#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha* pilha = criarPilha();
    int elemento;

    if (pilha == NULL) {
        printf("Erro ao criar pilha.\n");
        return 1;
    }

    if (pilhaVazia(pilha)) {
        printf("A pilha esta vazia.\n");
    }

    if (empilhar(pilha, 10)) {
        printf("10 empilhado.\n");
    }

    if (empilhar(pilha, 20)) {
        printf("20 empilhado.\n");
    }

    if (empilhar(pilha, 30)) {
        printf("30 empilhado.\n");
    }

    if (consultarTopo(pilha, &elemento)) {
        printf("Topo: %d\n", elemento);
    } else {
        printf("A pilha esta vazia.\n");
    }

    if (desempilhar(pilha, &elemento)) {
        printf("Desempilhado: %d\n", elemento);
    } else {
        printf("A pilha esta vazia.\n");
    }

    if (consultarTopo(pilha, &elemento)) {
        printf("Novo topo: %d\n", elemento);
    } else {
        printf("A pilha esta vazia.\n");
    }

    if (pilhaCheia(pilha)) {
        printf("A pilha esta cheia.\n");
    } else {
        printf("A pilha nao esta cheia.\n");
    }

    destruirPilha(pilha);

    return 0;
}