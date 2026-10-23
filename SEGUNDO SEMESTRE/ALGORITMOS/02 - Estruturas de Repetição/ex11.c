#include <stdio.h>
#include <math.h>

int main(){

    float valores[10];
    int qtd = 0;
    float valor;

    printf("Digite ate 10 numeros reais positivos (zero ou negativo para parar):\n");

    while(qtd < 10){
        printf("Numero %d: ", qtd+1);
        scanf("%f", &valor);

        if(valor <= 0){
            break;
        }

        valores[qtd] = valor;
        qtd += 1;
    }

    if(qtd == 0){
        printf("Nenhum numero foi digitado.\n");
        return 0;
    }

    float soma = 0;

    for(int i = 0; i < qtd; i++){
        soma += valores[i];
    }

    float media = soma / qtd;
    printf("Media: %.2f\n", media);

    if(qtd < 2){
        printf("Desvio padrao amostral precisa de pelo menos 2 valores.\n");
    }else{
        float soma_quadrados = 0;

        for(int i = 0; i < qtd; i++){
            soma_quadrados += (valores[i] - media) * (valores[i] - media);
        }

        float desvio = sqrt(soma_quadrados / (qtd - 1));
        printf("Desvio padrao amostral: %.2f\n", desvio);
    }

    return 0;
}
