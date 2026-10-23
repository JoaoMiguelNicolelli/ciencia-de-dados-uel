#include <stdio.h>

int main() {
    float compra, frete = 0, total;
    char tipo;

    printf("Valor da compra: R$ ");
    scanf("%f", &compra);
    printf("Tipo de cliente (A - assinante / V - visitante): ");
    scanf(" %c", &tipo);

    if (tipo != 'A' && tipo != 'V') {
        printf("Tipo de cliente invalido\n");
        return 1;
    }

    if (compra >= 150) {
        if (tipo == 'A') {
            compra = compra * 0.90;
        }
    } else {
        frete = 19.90;
        if (tipo == 'A') {
            frete = frete / 2;
        }
    }

    total = compra + frete;

    printf("Valor total a pagar: R$ %.2f\n", total);

    return 0;
}
