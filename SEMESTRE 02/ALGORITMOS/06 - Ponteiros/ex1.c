#include <stdio.h>

int main (){

    int num = 10;
    double real = 5.5;
    char letra = 'J';

    int *p_num;
    double *p_real;
    char *p_letra;

    p_num = &num;
    p_real = &real;
    p_letra = &letra;

    printf("ANTES DA MODIFICACAO\n");
    printf("numero = %d\n", num);
    printf("real   = %.2f\n", real);
    printf("letra  = %c\n", letra);

    *p_num = 20;
    *p_real = 9.75;
    *p_letra = 'C';

    printf("\nDEPOIS DA MODIFICACAO\n");
    printf("numero = %d\n", num);
    printf("real   = %.2f\n", real);
    printf("letra  = %c\n", letra);

    return 0;
}