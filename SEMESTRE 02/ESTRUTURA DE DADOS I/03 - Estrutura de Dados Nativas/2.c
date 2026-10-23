#include <stdio.h>

int main (){

    int v[20];
    for(int i = 0; i < 20; i++){
        printf("Elemento %d: ", i+1);
        scanf("%d", &v[i]);
    }

    int maior = v[0], menor = v[0];
    for(int i = 1; i < 20; i++){

        if(v[i] > maior){
            maior = v[i];
        }

        if(v[i] < menor){
            menor = v[i];
        }
    }

    int posMaior, posMenor;
    for(int i = 0; i < 20; i++){

        if(v[i] == maior){
            posMaior = i + 1;
            break;
        }
    }

    for(int i = 0; i < 20; i++){
        if(v[i] == menor){
            posMenor = i + 1;
            break;
        }
    }

    printf("Maior termo: %d\tPosicao: %d\n", maior, posMaior);
    printf("Menor termo: %d\tPosicao: %d\n", menor, posMenor);

    return 0;
}

//Outra opção é usar um FOR com o if sendo (v[i] == maior/menor && posMaior/posMenor == 0)