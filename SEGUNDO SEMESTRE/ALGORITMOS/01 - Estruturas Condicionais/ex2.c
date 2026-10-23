#include <stdio.h>

int main(){

    int numero;
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    if (numero % 3 == 0 && numero % 5 == 0) {
        printf("%d e divisivel por 3 e por 5 ao mesmo tempo.\n", numero);
    }
    else if (numero % 3 == 0) {
        printf("%d e divisivel apenas por 3.\n", numero);
    }
    else if (numero % 5 == 0) {
        printf("%d e divisivel apenas por 5.\n", numero);
    }
    else {
        printf("%d nao e divisivel nem por 3 nem por 5.\n", numero);
    }

    return 0;
}
