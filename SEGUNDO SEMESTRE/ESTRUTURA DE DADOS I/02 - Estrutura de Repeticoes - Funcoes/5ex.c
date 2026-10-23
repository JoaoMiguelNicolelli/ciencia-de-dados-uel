#include <stdio.h>

int main() {
    int n;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("O numero deve ser positivo.\n");
        return 1;
    }

    printf("\n    ");
    for (int j = 1; j <= n; j++) {
        printf("%4d", j);
    }

    printf("\n");

    printf("----");
    for (int j = 1; j <= n; j++) {
        printf("----");
    }

    printf("\n");

    for (int i = 1; i <= n; i++) {
        printf("%3d|", i);

        for (int j = 1; j <= n; j++) {
            printf("%4d", i * j);
        }

        printf("\n");
    }

    return 0;
}
