#include <stdio.h>

int main(){

    int n, f1 = 1, f2 = 1, fn = 1;
    printf("Digite um inteiro positivo n: ");
    scanf("%d", &n);

    if(n > 0){
        if(n == 1 || n == 2){
            printf("O termo %d da sequencia de Fibonacci eh 1.");
        }else{
            for(int i = 3; i <= n; i++){
                fn = f1 + f2;
                f1 = f2;
                f2 = fn;
            }
            printf("O termo %d da sequencia de Fibonacci eh %d.\n", n, fn);
        }
    }else{
         printf("Digite um numero maior que zero.\n");
    }

    return 0;
}