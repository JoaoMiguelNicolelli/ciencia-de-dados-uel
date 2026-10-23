#include <stdio.h>

int main(){

    float preco;
    printf("Digite o preco do produto: R$ ");
    scanf("%f", &preco);

    int codigo;
    printf("--CONDICOES DE PAGAMENTO--\n1- A vista em dinheiro ou cheque (10%% de desconto)\n2- A vista no cartao de credito (15%% de desconto)\n3- Em duas vezes sem juros\n4- Em duas vezes com juros de 10%%\n");
    scanf("%d", &codigo);

    float valor_final;
    if (codigo == 1) {
        valor_final = preco * 0.90f;
        printf("Valor a pagar: R$ %.2f\n", valor_final);
    }
    else if (codigo == 2) {
        valor_final = preco * 0.85f;
        printf("Valor a pagar: R$ %.2f\n", valor_final);
    }
    else if (codigo == 3) {
        valor_final = preco;
        printf("Valor a pagar: R$ %.2f (2x de R$ %.2f)\n", valor_final, valor_final / 2);
    }
    else if (codigo == 4) {
        valor_final = preco * 1.10f;
        printf("Valor a pagar: R$ %.2f (2x de R$ %.2f)\n", valor_final, valor_final / 2);
    }
    else {
        printf("Codigo de pagamento invalido!\n");
        return 1;
    }

    return 0;
}
