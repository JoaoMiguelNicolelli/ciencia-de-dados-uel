#include <stdio.h>

int main(){

    int qtd;

    printf("Quantos numeros deseja ler? ");
    scanf("%d", &qtd);

    if(qtd <= 0){
        printf("Quantidade invalida!\n");
        return 0;
    }

    int num;
    int maior = 0;
    int vezes = 0;

    for(int i = 0; i < qtd; i++){
        printf("Numero %d: ", i+1);
        scanf("%d", &num);

        if(i == 0 || num > maior){
            maior = num;
            vezes = 1;
        }else if(num == maior){
            vezes += 1;
        }
    }

    printf("Maior numero: %d\n", maior);
    printf("Ele foi lido %d vez(es).\n", vezes);

    return 0;
}
