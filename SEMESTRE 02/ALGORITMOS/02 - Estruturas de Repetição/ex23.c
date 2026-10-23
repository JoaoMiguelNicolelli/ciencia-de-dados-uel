#include <stdio.h>

int main(){

    int numero;

    printf("Digite um numero inteiro de ate 5 digitos: ");
    scanf("%d", &numero);

    if(numero < 0 || numero > 99999){
        printf("Numero invalido! Digite de 0 a 99999.\n");
        return 0;
    }

    int qtd_digitos = 0;
    int aux = numero;

    do{
        qtd_digitos += 1;
        aux = aux / 10;
    }while(aux > 0);

    int soma = 0;
    aux = numero;

    do{
        int digito = aux % 10;
        int potencia = 1;

        for(int i = 0; i < qtd_digitos; i++){
            potencia *= digito;
        }

        soma += potencia;
        aux = aux / 10;
    }while(aux > 0);

    if(soma == numero){
        printf("%d eh narcisista!\n", numero);
    }else{
        printf("%d nao eh narcisista (soma = %d).\n", numero, soma);
    }

    return 0;
}
