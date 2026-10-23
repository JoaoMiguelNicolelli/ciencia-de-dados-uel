#include <stdio.h>

int main(){

    int valor;
    printf("Digite um valor em reais: R$ ");
    scanf("%d", &valor);

    if (valor < 0) {
        printf("Valor invalido!\n");
        return 1;
    }

    int resto = valor;
    int notas_100 = resto / 100;
    resto = resto % 100;
    int notas_50 = resto / 50;
    resto = resto % 50;
    int notas_10 = resto / 10;
    resto = resto % 10;
    int notas_5 = resto / 5;
    resto = resto % 5;
    int notas_1 = resto;

    printf("Valor lido: R$ %d\n", valor);

    if (notas_100 > 0) {
        printf("%d nota(s) de R$ 100\n", notas_100);
    }
    if (notas_50 > 0) {
        printf("%d nota(s) de R$ 50\n", notas_50);
    }
    if (notas_10 > 0) {
        printf("%d nota(s) de R$ 10\n", notas_10);
    }
    if (notas_5 > 0) {
        printf("%d nota(s) de R$ 5\n", notas_5);
    }
    if (notas_1 > 0) {
        printf("%d nota(s) de R$ 1\n", notas_1);
    }

    return 0;
}
