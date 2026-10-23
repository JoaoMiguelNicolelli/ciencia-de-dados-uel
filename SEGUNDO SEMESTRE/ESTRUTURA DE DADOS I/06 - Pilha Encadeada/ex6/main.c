#include <stdio.h>
#include "pilha.h"

bool ehAbertura(char c) {
    return c == '(' || c == '[' || c == '{';
}

bool ehFechamento(char c) {
    return c == ')' || c == ']' || c == '}';
}

bool combinam(char abertura, char fechamento) {
    return (abertura == '(' && fechamento == ')') ||
           (abertura == '[' && fechamento == ']') ||
           (abertura == '{' && fechamento == '}');
}

int posicaoErro(const char* expressao) {
    Pilha* pilha = criarPilha();
    int posicao;

    if (pilha == NULL) {
        return -2;
    }

    for (int i = 0; expressao[i] != '\0'; i++) {
        char c = expressao[i];

        if (ehAbertura(c)) {
            empilhar(pilha, i);
        } else if (ehFechamento(c)) {
            if (!desempilhar(pilha, &posicao) || !combinam(expressao[posicao], c)) {
                destruirPilha(pilha);
                return i;
            }
        }
    }

    if (consultarTopo(pilha, &posicao)) {
        destruirPilha(pilha);
        return posicao;
    }

    destruirPilha(pilha);

    return -1;
}

int main() {
    const char* expressoes[] = {
        "(a + [b)]",
        "a + b)",
        "((a + b)",
        "[a * (b + c)]"
    };

    for (int i = 0; i < 4; i++) {
        printf("%-15s -> %d\n", expressoes[i], posicaoErro(expressoes[i]));
    }

    return 0;
}
