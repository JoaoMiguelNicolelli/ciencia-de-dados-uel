#include <stdio.h>

int main() {
    int mes;

    printf("Numero do mes (1 a 12): ");
    scanf("%d", &mes);

    switch (mes) {
        case 1: printf("Janeiro\n"); break;
        case 2: printf("Fevereiro\n"); break;
        case 3: printf("Marco\n"); break;
        case 4: printf("Abril\n"); break;
        case 5: printf("Maio\n"); break;
        case 6: printf("Junho\n"); break;
        case 7: printf("Julho\n"); break;
        case 8: printf("Agosto\n"); break;
        case 9: printf("Setembro\n"); break;
        case 10: printf("Outubro\n"); break;
        case 11: printf("Novembro\n"); break;
        case 12: printf("Dezembro\n"); break;
        default:
            printf("Mes invalido\n");
            return 1;
    }

    switch (mes) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("31 dias\n");
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            printf("30 dias\n");
            break;
        case 2:
            printf("28 ou 29 dias\n");
            break;
    }

    return 0;
}
