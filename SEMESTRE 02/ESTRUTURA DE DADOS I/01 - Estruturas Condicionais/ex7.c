#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, delta, x1, x2;

    printf("Digite os coeficientes a, b e c: ");
    scanf("%f %f %f", &a, &b, &c);

    if (a == 0) {
        if (b == 0) {
            printf("Nao e uma equacao valida\n");
        } else {
            x1 = -c / b;
            printf("Nao e uma equacao de segundo grau. Raiz da equacao de primeiro grau: %.2f\n", x1);
        }
    } else {
        delta = b * b - 4 * a * c;

        if (delta < 0) {
            printf("Delta negativo: a equacao nao possui raizes reais\n");
        } else if (delta == 0) {
            x1 = -b / (2 * a);
            printf("Delta igual a zero: raiz unica x = %.2f\n", x1);
        } else {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            printf("Delta positivo: x1 = %.2f e x2 = %.2f\n", x1, x2);
        }
    }

    return 0;
}
