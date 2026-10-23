#include <stdio.h>

int MaiorFatorPrimo(int n){
    int fator = 2, maior = 1;

    while(n > 1){
        if(n % fator == 0){
            maior = fator;
            n = n / fator;
        }else{
            fator++;
        }
    }
    return maior;
}

int main(){
    int n;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    printf("Maior fator primo: %d\n", MaiorFatorPrimo(n));

    return 0;
}
