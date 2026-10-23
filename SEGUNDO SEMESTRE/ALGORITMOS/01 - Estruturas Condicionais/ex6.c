#include <stdio.h>

int main(){

    float salario_bruto, prestacao;
    printf("Digite o salario bruto: ");
    scanf("%f", &salario_bruto);
    printf("Digite o valor da prestacao: ");
    scanf("%f", &prestacao);

    float limite = salario_bruto * 0.3f;

    if (prestacao <= limite) {
        printf("Emprestimo concedido!\n");
    }
    else {
        printf("Emprestimo negado! A prestacao ultrapassa 30%% do salario (limite: R$ %.2f).\n", limite);
    }

    return 0;
}
