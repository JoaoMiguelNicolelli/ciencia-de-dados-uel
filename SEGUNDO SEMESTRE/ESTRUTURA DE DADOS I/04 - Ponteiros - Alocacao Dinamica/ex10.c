#include <stdio.h>
#include <stdlib.h>

int **alocaMatriz(int linhas, int colunas){

    int **mat = malloc(linhas * sizeof(int *));

    if(mat == NULL){
        return NULL;
    }

    for(int i = 0; i < linhas; i++){
        mat[i] = malloc(colunas * sizeof(int));
    }

    return mat;
}

void liberaMatriz(int **mat, int linhas){

    for(int i = 0; i < linhas; i++){
        free(mat[i]); 
    }

    free(mat); 
}

void imprimeMatriz(int **mat, int linhas, int colunas){

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main(){

    int m, n;

    printf("Linhas (m): ");
    scanf("%d", &m);
    printf("Colunas (n): ");
    scanf("%d", &n);

    int **matriz = alocaMatriz(m, n);
    int **transposta = alocaMatriz(n, m); 

    if(matriz == NULL || transposta == NULL){
        printf("Memoria insuficiente\n");
        return 1;
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            transposta[j][i] = matriz[i][j]; 
        }
    }

    printf("\n-Matriz %dx%d-\n", m, n);
    imprimeMatriz(matriz, m, n);

    printf("\n-Transposta %dx%d-\n", n, m);
    imprimeMatriz(transposta, n, m);

    liberaMatriz(matriz, m);
    liberaMatriz(transposta, n);

    matriz = NULL;
    transposta = NULL;

    return 0;
}
