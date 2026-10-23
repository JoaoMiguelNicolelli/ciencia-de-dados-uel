#include <stdio.h>

int main(){

    int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;
    printf("Digite os 11 digitos do CPF (ex: 52998224725 ou 5 2 9 9 8 2 2 4 7 2 5): ");

    scanf("%1d", &d1);
    scanf("%1d", &d2);
    scanf("%1d", &d3);
    scanf("%1d", &d4);
    scanf("%1d", &d5);
    scanf("%1d", &d6);
    scanf("%1d", &d7);
    scanf("%1d", &d8);
    scanf("%1d", &d9);
    scanf("%1d", &d10);
    scanf("%1d", &d11);

    int soma1 = d1 * 10 + d2 * 9 + d3 * 8 + d4 * 7 + d5 * 6 + d6 * 5 + d7 * 4 + d8 * 3 + d9 * 2;
    int resto1 = soma1 % 11;

    int dv1;
    if (resto1 < 2) {
        dv1 = 0;
    }
    else {
        dv1 = 11 - resto1;
    }

    int soma2 = d1 * 11 + d2 * 10 + d3 * 9 + d4 * 8 + d5 * 7 + d6 * 6 + d7 * 5 + d8 * 4 + d9 * 3 + dv1 * 2;
    int resto2 = soma2 % 11;

    int dv2;
    if (resto2 < 2) {
        dv2 = 0;
    }
    else {
        dv2 = 11 - resto2;
    }

    if (dv1 == d10 && dv2 == d11) {
        printf("CPF valido!\n");
    }
    else if (dv1 != d10 && dv2 != d11) {
        printf("CPF invalido! Os dois digitos verificadores nao conferem (esperado %d%d).\n", dv1, dv2);
    }
    else if (dv1 != d10) {
        printf("CPF invalido! O primeiro digito verificador nao confere (esperado %d).\n", dv1);
    }
    else {
        printf("CPF invalido! O segundo digito verificador nao confere (esperado %d).\n", dv2);
    }

    return 0;
}
