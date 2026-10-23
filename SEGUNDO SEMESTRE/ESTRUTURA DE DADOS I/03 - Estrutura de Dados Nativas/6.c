/*
Leia uma matriz de inteiros m × n e exiba-a no formato
tabular, com uma linha da matriz por linha da tela. Exiba
também a soma dos elementos de cada linha e de cada
coluna.
*/

#include <stdio.h>

int main(){

    int m, n;
    printf("Numero de linhas: ");
    scanf("%d", &m);
    printf("Numero de colunas: ");
    scanf("%d", &n);

    int mat[m][n];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    printf("\n-Matriz-\n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }

    printf("\n-Soma das linhas-\n");
    for(int i = 0; i < m; i++){
        int soma = 0;
        for(int j = 0; j < n; j++){
            soma += mat[i][j];
        }
        printf("Linha %d: %d\n", i+1, soma);
    }

    printf("\n-Soma das colunas-\n");
    for(int j = 0; j < n; j++){
        int soma = 0;
        for(int i = 0; i < m; i++){
            soma += mat[i][j];
        }
        printf("Coluna %d: %d\n", j+1, soma);
    }

    return 0;
}
