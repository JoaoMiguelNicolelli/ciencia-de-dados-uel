#include <stdio.h>
#include <stdlib.h>

int *concatena(const int v1[], int n1, const int v2[], int n2){

    int *novo = malloc((n1 + n2) * sizeof(int));

    if(novo == NULL){
        return NULL;
    }

    for(int i = 0; i < n1; i++){
        novo[i] = v1[i];
    }

    for(int i = 0; i < n2; i++){
        novo[n1 + i] = v2[i]; 
    }

    return novo;
}

int main(){

    int n1, n2;

    printf("Tamanho do vetor 1: ");
    scanf("%d", &n1);

    int v1[n1];
    for(int i = 0; i < n1; i++){
        printf("Elemento %d: ", i+1);
        scanf("%d", &v1[i]);
    }

    printf("\nTamanho do vetor 2: ");
    scanf("%d", &n2);

    int v2[n2];
    for(int i = 0; i < n2; i++){
        printf("Elemento %d: ", i+1);
        scanf("%d", &v2[i]);
    }

    int *juntos = concatena(v1, n1, v2, n2);

    if(juntos == NULL){
        printf("Memoria insuficiente\n");
        return 1;
    }

    printf("\nVetor concatenado:\n");
    for(int i = 0; i < n1 + n2; i++){
        printf("%d ", juntos[i]);
    }
    printf("\n");

    free(juntos);
    juntos = NULL;

    return 0;
}
