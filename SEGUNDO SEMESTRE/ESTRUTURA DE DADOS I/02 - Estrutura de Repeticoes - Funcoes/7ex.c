#include <stdio.h>

int main(){

    int qtd;
    printf("Quantidade de produtos no estoque: ");
    scanf("%d", &qtd);

    int produtos[qtd][2]; //duas colunas (preco e desconto) 
    int precos[qtd];

    for(int i = 0; i < qtd; i++){

        printf("Valor do produto %d: R$ ", i+1);
        scanf("%d", &produtos[i][0]);

        printf("Percentual de aumento do produto %d: ", i+1);
        scanf("%d", &produtos[i][1]);

    }

    for(int i = 0; i < qtd; i++){
        precos[i] = produtos [i][0] + (produtos[i][0] * produtos[i][1] / 100);
    }

    int contador = 1, maior = precos[0];
    for(int i = 0; i < qtd; i++){
        if(precos[i] > maior){
            maior = precos[i];
            contador = i + 1;
        }
        
    }

    printf("\n"); //so estetica de output
    for(int i = 0; i < qtd; i++){
        printf("Valor final do produto %d: R$ %d\n", i+1, precos[i]);
    }

    printf("-O produto %d eh o mais caro, com valor igual a R$ %d", contador, maior);

    return 0;
}