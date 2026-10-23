#include <stdio.h>

int main() {
    int idade, terca;
    float valor;

    printf("Idade: ");
    scanf("%d", &idade);
    printf("Visita na terca-feira? (1 - sim / 0 - nao): ");
    scanf("%d", &terca);

    if (idade < 6) {
        valor = 0;
    } else if (idade <= 17 || idade > 60) {
        valor = 15.00;
    } else {
        valor = 30.00;
    }

    if (terca == 1 && valor > 0) {
        valor = valor * 0.60;
    }

    printf("Valor final do ingresso: R$ %.2f\n", valor);

    return 0;
}
