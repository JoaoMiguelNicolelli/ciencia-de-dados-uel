#include <stdio.h>

int soma_dobro(int *A, int *B){
    *A *= 2;
    *B *= 2;
    return *A + *B;
}

int main(){

    int a, b;

    printf("Valor de a: ");
    scanf("%d", &a);

    printf("Valor de b: ");
    scanf("%d", &b);

    int resultado = soma_dobro(&a, &b);

    printf("A soma dos dobros eh: %d", resultado);
    return 0;
}