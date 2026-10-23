#include <stdio.h>

int main(){

    int opcao, linhas;

    printf("1 - Losango\n");
    printf("2 - Triangulo\n");
    printf("Escolha: ");
    scanf("%d", &opcao);

    printf("Tamanho (em linhas): ");
    scanf("%d", &linhas);

    if(linhas <= 0){
        printf("Tamanho invalido!\n");
        return 0;
    }

    if(opcao == 1){
        if(linhas % 2 == 0){
            linhas += 1;
            printf("Losango precisa de numero impar de linhas, usando %d.\n", linhas);
        }

        int metade = linhas / 2;

        for(int i = 0; i < linhas; i++){
            int distancia;

            if(i <= metade){
                distancia = i;
            }else{
                distancia = linhas - 1 - i;
            }

            for(int j = 0; j < metade - distancia; j++){
                printf(" ");
            }
            for(int j = 0; j < 2 * distancia + 1; j++){
                printf("%%");
            }
            printf("\n");
        }
    }else if(opcao == 2){
        for(int i = 0; i < linhas; i++){
            for(int j = 0; j < linhas - 1 - i; j++){
                printf(" ");
            }
            for(int j = 0; j < 2 * i + 1; j++){
                printf("%%");
            }
            printf("\n");
        }
    }else{
        printf("Opcao invalida!\n");
    }

    return 0;
}
