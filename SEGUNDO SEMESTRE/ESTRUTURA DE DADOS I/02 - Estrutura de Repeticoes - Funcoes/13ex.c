#include <stdio.h>

void sequenciaFibonacci(int n);

int main(){
    int n;

    printf("Digite um inteiro positivo: ");
    scanf("%d", &n);

    sequenciaFibonacci(n);
    return 0;
}

void sequenciaFibonacci(int n){
    if(n <= 0){
        printf("Numero invalido.");
        return;
    }

    int f1 = 0, f2 = 1, fn;
    printf("Os primeiros %d termos da sequencia de Fibonacci sao:\n", n);

    for(int i = 1; i <= n; i++){
        printf("%d\t", f1);
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }
    printf("\n");
}