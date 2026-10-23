#include <stdio.h>

int main() {
    float pedido;

    printf("Valor total do pedido: R$ ");
    scanf("%f", &pedido);

    printf("%s\n", pedido >= 200 ? "Frete gratis" : "Frete cobrado");
    printf("Valor do frete: R$ %.2f\n", pedido >= 200 ? 0.00 : 25.00);

    return 0;
}
