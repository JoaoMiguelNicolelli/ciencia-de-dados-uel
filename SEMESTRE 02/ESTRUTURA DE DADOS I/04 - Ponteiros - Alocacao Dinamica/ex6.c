#include <stdio.h>
#include <stdlib.h>

int *criaVetor(int n){

    int *v = malloc(n * sizeof(int));

    if(v == NULL){
        return NULL;
    }

    for(int i = 0; i < n; i++){
        v[i] = 3 * (i + 1); // 3, 6, 9, 12, ...
    }

    return v; 
}

int main(){

    int n;
    printf("Quantidade de multiplos: ");
    scanf("%d", &n);

    int *vetor = criaVetor(n);

    if(vetor == NULL){
        printf("Memoria insuficiente\n");
        return 1;
    }

    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor); 
    vetor = NULL;

    return 0;
}
