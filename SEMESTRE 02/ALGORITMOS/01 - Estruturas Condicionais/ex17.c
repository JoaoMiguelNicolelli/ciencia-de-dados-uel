#include <stdio.h>

int main(){

    float salario;
    int tempo_servico;
    printf("Salario atual: R$ ");
    scanf("%f", &salario);
    printf("Tempo de servico (anos): ");
    scanf("%d", &tempo_servico);

    float reajuste;
    if (salario <= 500) {
        reajuste = 0.25f;
    }
    else if (salario <= 1000) {
        reajuste = 0.20f;
    }
    else if (salario <= 1500) {
        reajuste = 0.15f;
    }
    else if (salario <= 2000) {
        reajuste = 0.10f;
    }
    else {
        reajuste = 0;
    }

    float bonus;
    if (tempo_servico < 1) {
        bonus = 0;
    }
    else if (tempo_servico <= 3) {
        bonus = 100;
    }
    else if (tempo_servico <= 6) {
        bonus = 200;
    }
    else if (tempo_servico <= 10) {
        bonus = 300;
    }
    else {
        bonus = 500;
    }

    if (reajuste == 0 && bonus == 0) {
        printf("O funcionario nao tem direito a nenhum aumento.\n");
    }
    else {
        float salario_final = salario + salario * reajuste + bonus;
        printf("Salario final reajustado: R$ %.2f\n", salario_final);
    }

    return 0;
}
