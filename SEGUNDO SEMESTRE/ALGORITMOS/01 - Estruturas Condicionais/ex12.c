#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    char operacao[50];
    printf("--OPERACOES DISPONIVEIS--\n1- Soma\n2- Subtracao\n3- Multiplicacao\n4- Divisao\n");

    fgets(operacao, sizeof(operacao), stdin);
    for(int i = 0; operacao[i] != '\0'; i++){
        if(operacao[i] == '\n'){
            operacao[i] = '\0';
        }
        operacao[i] = tolower(operacao[i]);
    }

    if (strcmp(operacao, "soma") != 0 && strcmp(operacao, "subtracao") != 0 && strcmp(operacao, "multiplicacao") != 0 && strcmp(operacao, "divisao") != 0) {
        printf("Operacao nao encontrada!\n");
        return 1;
    }

    float valor1, valor2;
    printf("Digite o primeiro valor: ");
    scanf("%f", &valor1);
    printf("Digite o segundo valor: ");
    scanf("%f", &valor2);

    float resultado;
    if (strcmp(operacao, "soma") == 0) {
        resultado = valor1 + valor2;
    }
    else if (strcmp(operacao, "subtracao") == 0) {
        resultado = valor1 - valor2;
    }
    else if (strcmp(operacao, "multiplicacao") == 0) {
        resultado = valor1 * valor2;
    }
    else {
        if (valor2 == 0) {
            printf("Erro: divisao por zero!\n");
            return 1;
        }
        resultado = valor1 / valor2;
    }

    printf("Resultado: %.2f\n", resultado);

    return 0;
}
