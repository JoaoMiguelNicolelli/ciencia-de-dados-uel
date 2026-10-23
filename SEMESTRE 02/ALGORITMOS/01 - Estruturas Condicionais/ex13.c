#include <stdio.h>

int main(){

    float lado1, lado2, lado3;
    printf("Digite o primeiro lado: ");
    scanf("%f", &lado1);
    printf("Digite o segundo lado: ");
    scanf("%f", &lado2);
    printf("Digite o terceiro lado: ");
    scanf("%f", &lado3);

    if (lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1) {
        if (lado1 == lado2 && lado2 == lado3) {
            printf("Os lados formam um triangulo Equilatero.\n");
        }
        else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
            printf("Os lados formam um triangulo Isosceles.\n");
        }
        else {
            printf("Os lados formam um triangulo Escaleno.\n");
        }
    }
    else {
        printf("Os valores informados nao formam um triangulo.\n");
    }

    return 0;
}
