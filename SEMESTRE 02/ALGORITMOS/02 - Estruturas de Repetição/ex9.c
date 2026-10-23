#include <stdio.h>

int main(){

    int valores[30];

    for(int i = 0; i < 30; i++){
        printf("Numero %d: ", i+1);
        scanf("%d", &valores[i]);
    }

    int maior = valores[0];
    int menor = valores[0];

    for(int i = 1; i < 30; i++){
        if(valores[i] > maior){
            maior = valores[i];
        }
        if(valores[i] < menor){
            menor = valores[i];
        }
    }

    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

    return 0;
}
