#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));

    int secreto = rand() % 100 + 1;
    int chute = 0;
    int tentativas = 0;

    printf("Adivinhe o numero entre 1 e 100!\n");

    while(chute != secreto){
        printf("Seu chute: ");
        scanf("%d", &chute);
        tentativas += 1;

        if(chute > secreto){
            printf("Muito alto!\n");
        }else if(chute < secreto){
            printf("Muito baixo!\n");
        }else{
            printf("Acertou! O numero era %d. Tentativas: %d\n", secreto, tentativas);
        }
    }

    return 0;
}
