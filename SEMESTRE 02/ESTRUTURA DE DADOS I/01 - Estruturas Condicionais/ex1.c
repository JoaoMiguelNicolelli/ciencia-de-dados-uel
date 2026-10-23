#include <stdio.h>

int main() {
    float consumo;

    printf("Consumo mensal de agua (m3): ");
    scanf("%f", &consumo);

    if (consumo > 15) {
        float taxa = (consumo - 15) * 9.80;
        printf("Taxa de excedente: R$ %.2f\n", taxa);
    } else {
        printf("Consumo dentro da franquia\n");
    }

    return 0;
}
