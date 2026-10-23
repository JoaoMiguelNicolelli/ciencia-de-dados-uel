#include <stdio.h>

int main(){

    float raio;
    printf("Digite o raio do circulo: ");
    scanf("%f", &raio);

    if (raio < 0) {
        printf("Raio invalido! O raio nao pode ser negativo.\n");
        return 1;
    }

    float area = 3.14159f * raio * raio;
    printf("Area do circulo: %.2f\n", area);

    return 0;
}
