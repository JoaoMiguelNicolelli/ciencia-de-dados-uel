#include <stdio.h>

int main(){

    int n;

    printf("Digite um numero inteiro maior ou igual a zero: ");
    scanf("%d", &n);

    if(n < 0){
        printf("O numero precisa ser maior ou igual a zero!\n");
        return 0;
    }

    long long anterior = 0;
    long long atual = 1;

    for(int i = 0; i < n; i++){
        long long proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
    }

    printf("Termo %d da sequencia de Fibonacci: %lld\n", n, anterior);

    return 0;
}
