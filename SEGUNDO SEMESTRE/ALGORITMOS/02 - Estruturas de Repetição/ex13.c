#include <stdio.h>

int main(){

    printf("Numeros perfeitos de 1 a 10000: ");

    for(int i = 1; i <= 10000; i++){
        int soma_divisores = 0;

        for(int j = 1; j <= i / 2; j++){
            if(i % j == 0){
                soma_divisores += j;
            }
        }

        if(soma_divisores == i){
            printf("%d ", i);
        }
    }

    printf("\n\n");

    int a, b;

    printf("Primeiro numero: ");
    scanf("%d", &a);
    printf("Segundo numero: ");
    scanf("%d", &b);

    int soma_a = 0;
    int soma_b = 0;

    for(int j = 1; j <= a / 2; j++){
        if(a % j == 0){
            soma_a += j;
        }
    }

    for(int j = 1; j <= b / 2; j++){
        if(b % j == 0){
            soma_b += j;
        }
    }

    if(a != b && soma_a == b && soma_b == a){
        printf("%d e %d sao numeros amigos!\n", a, b);
    }else{
        printf("%d e %d nao sao numeros amigos.\n", a, b);
    }

    return 0;
}
