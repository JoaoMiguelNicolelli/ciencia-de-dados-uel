#include <stdio.h>
#include <ctype.h>
#include "pilha.h"

bool ehOperador(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool avaliarPosFixa(const char* expressao, int* resultado) {
    Pilha* pilha = criarPilha();
    int a, b, valor;

    if (pilha == NULL) {
        return false;
    }

    for (int i = 0; expressao[i] != '\0'; i++) {
        char c = expressao[i];

        if (isdigit(c)) {
            valor = 0;

            while (isdigit(expressao[i])) {
                valor = valor * 10 + (expressao[i] - '0');
                i++;
            }

            i--;
            empilhar(pilha, valor);
        } else if (ehOperador(c)) {
            if (!desempilhar(pilha, &b) || !desempilhar(pilha, &a)) {
                destruirPilha(pilha);
                return false;
            }

            switch (c) {
                case '+': valor = a + b; break;
                case '-': valor = a - b; break;
                case '*': valor = a * b; break;
                case '/':
                    if (b == 0) {
                        destruirPilha(pilha);
                        return false;
                    }
                    valor = a / b;
                    break;
            }

            empilhar(pilha, valor);
        } else if (c != ' ') {
            destruirPilha(pilha);
            return false;
        }
    }

    if (!desempilhar(pilha, &valor) || !pilhaVazia(pilha)) {
        destruirPilha(pilha);
        return false;
    }

    *resultado = valor;
    destruirPilha(pilha);

    return true;
}

int main() {
    const char* expressoes[] = {
        "12 3 4 * +",
        "100 7 5 - /",
        "3 +",
        "2 3 4 +",
        "5 0 /"
    };
    int resultado;

    for (int i = 0; i < 5; i++) {
        if (avaliarPosFixa(expressoes[i], &resultado)) {
            printf("%-15s -> resultado %d\n", expressoes[i], resultado);
        } else {
            printf("%-15s -> mal formada\n", expressoes[i]);
        }
    }

    return 0;
}
