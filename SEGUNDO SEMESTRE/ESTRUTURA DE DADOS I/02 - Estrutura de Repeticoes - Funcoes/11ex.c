#include <stdio.h>

int fatorial(int n){

    int resultado = 1;
    for(int i = n; i > 1; i-=2){
        resultado *= i * (i - 1);
    }
    return resultado;
}

int combinacao(int m, int n){
    return (fatorial(m)) / (fatorial(m - n) * fatorial(n));
}

int main(){

    int num;
    printf("Digite um inteiro positivo: ");
    scanf("%d", &num);

    if(num > 0){
        printf("O fatorial de %d eh %d.\n\n", num, fatorial(num));

        int a, b;
        printf("Digite m (espaco) n para verificar o numero de combinacoes existentes: ");
        scanf("%d %d", &a, &b);

        if(b <= a){
            printf("Ha %d combinacoes.", combinacao(a, b));
        }else{
            printf("Invalido.");
        }

    }else{
        printf("Numero digitado invalido!");
    }

    return 0;
}