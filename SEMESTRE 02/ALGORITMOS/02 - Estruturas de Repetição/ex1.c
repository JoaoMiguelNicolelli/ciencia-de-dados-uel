#include <stdio.h>

int main(){

    int valores[10];
    int soma = 0;

    for(int i = 0; i < 10; i++){
        printf("Numero %d: ", i+1);
        scanf("%d", &valores[i]);
    }

    for(int i = 0; i < 10; i++){
        soma += valores[i];
    }

    float media = (float) soma / 10;
    printf("Media dos valores digitados: %.2f\n", media);

    return 0;
}
