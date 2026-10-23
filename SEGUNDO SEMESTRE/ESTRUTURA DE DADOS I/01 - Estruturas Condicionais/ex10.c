#include <stdio.h>

int main() {
    float peso, taxa, franquia, excedente, valor;
    int modalidade, assinatura;

    printf("Peso da encomenda (kg): ");
    scanf("%f", &peso);

    if (peso <= 0) {
        printf("Peso invalido\n");
        return 1;
    }

    printf("Modalidade (1 - padrao / 2 - expressa / 3 - premium): ");
    scanf("%d", &modalidade);
    printf("Possui plano de assinatura? (1 - sim / 0 - nao): ");
    scanf("%d", &assinatura);

    if (modalidade == 1) {
        taxa = 18.00;
        franquia = 5;
        excedente = 6.50;
    } else if (modalidade == 2) {
        taxa = 35.00;
        franquia = 10;
        excedente = 4.00;
    } else if (modalidade == 3) {
        taxa = 60.00;
        franquia = 20;
        excedente = 2.50;
    } else {
        printf("Modalidade invalida\n");
        return 1;
    }

    if (assinatura == 1) {
        franquia = franquia + 5;
    }

    valor = taxa;

    if (peso > franquia) {
        valor = valor + (peso - franquia) * excedente;
    }

    printf("Valor a pagar pelo envio: R$ %.2f\n", valor);

    return 0;
}
