#include <stdio.h>
#include "fracao.h"

int main() {
    Fracao* f1 = criarFracao(2, 4);
    Fracao* f2 = criarFracao(3, 6);

    Fracao* soma = somarFracoes(f1, f2);
    Fracao* produto = multiplicarFracoes(f1, f2);

    printf("F1: ");
    exibirFracao(f1);

    printf("F2: ");
    exibirFracao(f2);

    printf("Soma: ");
    exibirFracao(soma);

    printf("Produto: ");
    exibirFracao(produto);

    destruirFracao(f1);
    destruirFracao(f2);
    destruirFracao(soma);
    destruirFracao(produto);

    return 0;
}