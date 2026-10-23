#include <stdio.h>

int main(){

    int n;

    printf("Digite um numero: ");
    scanf("%d", &n);

    int qtd_divisores = 0;

    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            qtd_divisores += 1;
        }
    }

    if(qtd_divisores == 2){
        printf("%d eh primo!\n", n);
    }else{
        printf("%d nao eh primo.\n", n);
    }

    return 0;
}
