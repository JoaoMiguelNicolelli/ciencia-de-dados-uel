#include <stdio.h>

int main(){
    
    int n;
    printf("Digite um inteiro maior que 1: ");
    scanf("%d", &n);

    int divisor = 2;

    if(n <= 1){
        printf("Por favor, digite um numero inteiro maior 1.\n");
        return 0;
    }

    printf("Divisores primos de %d: ", n);

    while(n > 1){
        if(n % divisor == 0){
            printf("%d ", divisor);
            n /= divisor;
        }else{
            divisor ++;
        }
    }

    printf("\n");
    return 0;
}