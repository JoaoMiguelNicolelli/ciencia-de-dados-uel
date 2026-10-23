#include <stdio.h>

int main() {
    float consumo, tarifa, total;

    printf("Consumo mensal de energia (kWh): ");
    scanf("%f", &consumo);

    if (consumo <= 50) {
        tarifa = 0.45;
    } else if (consumo <= 100) {
        tarifa = 0.68;
    } else if (consumo <= 200) {
        tarifa = 0.82;
    } else if (consumo <= 400) {
        tarifa = 0.95;
    } else {
        tarifa = 1.12;
    }

    total = consumo * tarifa + 12.50;

    printf("Consumo: %.2f kWh\n", consumo);
    printf("Valor total da conta: R$ %.2f\n", total);

    return 0;
}
