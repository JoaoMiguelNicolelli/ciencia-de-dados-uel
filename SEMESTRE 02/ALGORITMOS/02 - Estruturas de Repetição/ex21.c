#include <stdio.h>

int main(){

    int numero, base;

    printf("Numero decimal: ");
    scanf("%d", &numero);
    printf("Base de destino (2 a 16): ");
    scanf("%d", &base);

    if(base < 2 || base > 16){
        printf("Base invalida!\n");
        return 0;
    }

    char digitos[] = "0123456789ABCDEF";
    char resultado[40];
    int qtd = 0;

    long long valor = numero;
    int negativo = 0;

    if(valor < 0){
        negativo = 1;
        valor = -valor;
    }

    do{
        resultado[qtd] = digitos[valor % base];
        qtd += 1;
        valor = valor / base;
    }while(valor > 0);

    printf("%d na base %d: ", numero, base);

    if(negativo){
        printf("-");
    }

    for(int i = qtd - 1; i >= 0; i--){
        printf("%c", resultado[i]);
    }
    printf("\n");

    return 0;
}
