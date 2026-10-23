#include <stdio.h>

int main(){

    int n;

    printf("Digite um numero inteiro positivo N: ");
    scanf("%d", &n);

    if(n <= 0){
        printf("N precisa ser positivo!\n");
        return 0;
    }

    int numero = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            printf("%d\t", numero);
            numero++;
        }
        printf("\n");
    }

    return 0;
}
