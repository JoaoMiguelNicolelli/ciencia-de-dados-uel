#include <stdio.h>

int main(){

    int v[50];
    int freq[10] = {0};

    printf("--ELEMENTOS HA DE ESTAREM NO INTERVALO [0,9]--\n");

    for(int i = 0; i < 50; i++){
        int aux;
        printf("Elemento %d: ", i+1);
        scanf("%d", &aux);

        if(0 <= aux && aux <= 9){
            v[i] = aux;
        }else{
            printf("Elemento %d descartado por nao estar no intervalo [0,9]", i+1);
            i--;
        }
    }

    for(int i = 0; i < 50; i++){
        freq[v[i]] ++;
    }

    printf("\n-Frequencias-\n");

    for(int i = 0; i < 10; i++){
        printf("Elemento: %d\tFrequencia: %d\n", i, freq[i]);
    }

    int maior = freq[0];
    int numero = 0;

    for(int i = 1; i < 10; i++){
        if(freq[i] > maior){
            maior = freq[i];
            numero = i;
        }
    }

    printf("\nElemento que mais aparece: %d\tTal elemento apareceu %d vezes.\n", numero, maior);
    return 0;
}