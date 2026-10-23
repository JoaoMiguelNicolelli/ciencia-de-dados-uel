#include <stdio.h>

int main(){

    int valores[10];

    for(int i = 0; i < 10; i++){
        printf("Numero %d: ", i+1);
        scanf("%d", &valores[i]);
    }

    int soma_pares = 0;
    int qtd_pares = 0;
    int soma_impares = 0;
    int qtd_impares = 0;

    for(int i = 0; i < 10; i++){
        if(valores[i] % 2 == 0){
            soma_pares += valores[i];
            qtd_pares += 1;
        }else{
            soma_impares += valores[i];
            qtd_impares += 1;
        }
    }

    if(qtd_pares != 0){
        float media_pares = soma_pares / qtd_pares;
        printf("Media dos elementos pares digitados: %.2f", media_pares);
    }else{
        printf("Divisao dos pares eh inexistente! 0 numeros pares digitados.");
    }

    if(qtd_impares != 0){
        float media_impares = soma_impares / qtd_impares;
        printf("Media dos elementos impares digitados: %.2f\n", media_impares);
    }else{
        printf("Divisao dos impares eh inexistente! 0 numeros pares digitados.");
    }
    
    return 0;
}