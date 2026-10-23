#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));

    int pontos = 0;
    int soma_anterior = 0;
    int maior_soma = 0;
    int rodada_maior = 0;

    for(int i = 1; i <= 10; i++){
        int dado1 = rand() % 6 + 1;
        int dado2 = rand() % 6 + 1;
        int soma = dado1 + dado2;

        printf("Rodada %d: %d + %d = %d", i, dado1, dado2, soma);

        if(soma == 7 || soma == 11){
            pontos += 10;
            printf(" -> ganhou 10 pontos\n");
        }else if(soma == 2 || soma == 3 || soma == 12){
            pontos -= 5;
            printf(" -> perdeu 5 pontos\n");
        }else if(soma == soma_anterior){
            pontos += 3;
            printf(" -> soma repetida, ganhou 3 pontos extras\n");
        }else{
            printf("\n");
        }

        if(soma > maior_soma){
            maior_soma = soma;
            rodada_maior = i;
        }

        soma_anterior = soma;
    }

    printf("\nPontuacao total: %d\n", pontos);
    printf("Rodada de maior soma: %d (soma %d)\n", rodada_maior, maior_soma);

    return 0;
}
