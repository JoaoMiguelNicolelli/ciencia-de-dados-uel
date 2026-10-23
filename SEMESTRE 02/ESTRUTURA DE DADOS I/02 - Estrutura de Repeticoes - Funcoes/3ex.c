#include <stdio.h>

int main(){

    int peso = 0;
    int aux = 0;
    int i = 1;
    int contador = 0;

    while(1){ //while (1) roda continuamente ate encontrar um break

        printf("Digite o peso, em kg, do lote %d: ", i);
        scanf("%d", &aux);

        if(aux < 1){
            break;
        }

        peso += aux;
        contador++;
        i++;
    }

    float media_pesos = 0;
    if(contador >= 1){
        media_pesos = (float) peso/contador;
    }

    printf("Peso total: %d kg.\n", peso);
    printf("Quantidade de lotes: %d\n", contador);
    printf("Peso medio dos lotes: %.2f", media_pesos);

    return 0;

}