#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "pilha.h"

int avaliarPreFixa(const char* expressao) {
    Pilha* pilha = criarPilha();
    int a, b, valor = 0;

    if (pilha == NULL) {
        return 0;
    }

    for (int i = strlen(expressao) - 1; i >= 0; i--) {
        char c = expressao[i];

        if (isdigit(c)) {
            empilhar(pilha, c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            desempilhar(pilha, &a);
            desempilhar(pilha, &b);

            switch (c) {
                case '+': valor = a + b; break;
                case '-': valor = a - b; break;
                case '*': valor = a * b; break;
                case '/': valor = a / b; break;
            }

            empilhar(pilha, valor);
        }
    }

    desempilhar(pilha, &valor);
    destruirPilha(pilha);

    return valor;
}

int main() {
    const char* expressoes[] = {
        "- + 5 * 3 2 4",
        "/ - 9 3 2"
    };

    for (int i = 0; i < 2; i++) {
        printf("%-15s -> resultado %d\n", expressoes[i], avaliarPreFixa(expressoes[i]));
    }

    return 0;
}
