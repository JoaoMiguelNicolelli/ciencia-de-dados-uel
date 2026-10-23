#include <stdio.h>

int main() {
    int a, b, c, menor;

    printf("Digite tres numeros inteiros: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a <= b && a <= c) {
        menor = a;
    } else if (b <= c) {
        menor = b;
    } else {
        menor = c;
    }

    printf("Menor: %d\n", menor);

    return 0;
}
