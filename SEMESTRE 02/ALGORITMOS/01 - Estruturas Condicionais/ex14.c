#include <stdio.h>

#define ANO_ATUAL 2008

int main(){

    int dia, mes, ano;
    printf("Dia de nascimento: ");
    scanf("%d", &dia);
    printf("Mes de nascimento: ");
    scanf("%d", &mes);
    printf("Ano de nascimento: ");
    scanf("%d", &ano);

    int bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);

    int dias_no_mes;
    if (mes == 2) {
        if (bissexto) {
            dias_no_mes = 29;
        }
        else {
            dias_no_mes = 28;
        }
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        dias_no_mes = 30;
    }
    else {
        dias_no_mes = 31;
    }

    if (mes > 0 && mes < 13 && dia > 0 && dia <= dias_no_mes && ano <= ANO_ATUAL) {
        printf("data valida\n");
    }
    else {
        printf("data invalida\n");
    }

    return 0;
}
