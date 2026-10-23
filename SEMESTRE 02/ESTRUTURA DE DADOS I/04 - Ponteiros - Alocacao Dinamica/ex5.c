#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    printf("Tamanho da lista: ");
    scanf("%d", &n);

    int *vetor = malloc(n * sizeof(int));

    if(vetor == NULL){
        printf("Memoria insuficiente\n");
        return 1;
    }

    for(int i = 0; i < n; i++){
        printf("Elemento %d: ", i+1);
        scanf("%d", &vetor[i]);
    }

    double soma = 0;
    for(int i = 0; i < n; i++){
        soma += vetor[i];
    }

    double media = soma / n;
    printf("\nMedia: %.2f\n", media);

    printf("Maiores que a media:\n");
    for(int i = 0; i < n; i++){
        if(vetor[i] > media){
            printf("%d\n", vetor[i]);
        }
    }

    free(vetor);
    vetor = NULL;

    return 0;
}
