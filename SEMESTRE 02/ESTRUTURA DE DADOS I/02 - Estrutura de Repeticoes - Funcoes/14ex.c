#include <stdio.h>

void menu(void);

int soma(int x, int y){
    return x + y;
}

int subtracao(int x, int y){
    return x - y;
}

int multiplicacao(int x, int y){
    return x * y;
}

int divisao(int x, int y){
    if(y == 0){
        printf("Erro: impossivel dividir por 0!\n");
        return 0;
    }
    return x / y;
}

int potenciacao(int x, int y){
    if(y == 0){
        return 1;
    }

    int resultado = 1;
    for(int i = 0; i < y; i++){
        resultado *= x;
    }
    return resultado;
}

int main(){

    menu();
    return 0;

}

void menu(void){
    int opcao;
    int num1, num2, result;

    do{

        printf("\n\n=== MENU DE OPERACOES ===\n\n");
        printf("1 - Soma\n");
        printf("2 - Subtracao\n");
        printf("3 - Multiplicacao\n");
        printf("4 - Divisao\n");
        printf("5 - Potenciacao\n");
        printf("0 - Sair\n");
        printf("\nOperacao desejada: ");
        scanf("%d", &opcao);

        if(opcao >= 1 && opcao <= 5){
            printf("\nDigite o primeiro numero: ");
            scanf("%d", &num1);
            printf("Digite o segundo numero: ");
            scanf("%d", &num2);
        }

        switch (opcao){
            case 1:
                result = soma(num1, num2);
                printf("Resultado: %d\n", result);
                break;

            case 2:
                result = subtracao(num1, num2);
                printf("Resultado: %d\n", result);
                break;

            case 3:
                result = multiplicacao(num1, num2);
                printf("Resultado: %d\n", result);
                break;

            case 4:
                result = divisao(num1, num2);
                printf("Resultado: %d\n", result);
                break;

            case 5:
                result = potenciacao(num1, num2);
                printf("Resultado: %d\n", result);
                break;

            case 0:
                printf("\nPrograma encerrado.\n");
                break;

            default:
                printf("Numero inserido invalido para este menu. Tente novamente!");
        }  
    }while(opcao != 0);
}
