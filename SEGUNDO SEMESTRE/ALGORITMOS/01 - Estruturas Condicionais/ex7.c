#include <stdio.h>

int main(){

    int valor_compra, valor_pagamento;
    printf("Valor da compra: R$ ");
    scanf("%d", &valor_compra);
    printf("Valor do pagamento: R$ ");
    scanf("%d", &valor_pagamento);

    if (valor_pagamento < valor_compra) {
        printf("Pagamento Negado\n");
        return 1;
    }

    int troco = valor_pagamento - valor_compra;
    int notas_100 = troco / 100;
    int notas_10 = (troco % 100) / 10;
    int notas_1 = troco % 10;

    printf("Troco: R$ %d\n", troco);
    printf("%d notas de R$ 100\n", notas_100);
    printf("%d notas de R$ 10\n", notas_10);
    printf("%d notas de R$ 1\n", notas_1);

    return 0;
}
