#include <stdio.h>

int *busca(int v[], int tam, int x){

    for(int i = 0; i < tam; i++){
        if(v[i] == x){
            return &v[i]; 
        }
    }

    return NULL; 
}

int main(){

    int tamanho, procurado;
    printf("Tamanho da lista: ");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    for(int i = 0; i < tamanho; i++){
        printf("Elemento %d: ", i+1);
        scanf("%d", &vetor[i]);
    }

    printf("Valor procurado: ");
    scanf("%d", &procurado);

    int *achado = busca(vetor, tamanho, procurado);

    if(achado != NULL){
        int indice = achado - vetor; // subtracao de ponteiros
        printf("Valor %d encontrado no indice %d\n", procurado, indice);
    } else {
        printf("Valor %d nao encontrado\n", procurado);
    }

    return 0;
}
