#include <stdio.h>

void transposta(int m, int n, int mat[m][n], int t[n][m]){

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            t[j][i] = mat[i][j];
        }
    }
}

int main(){

    int m, n;
    printf("Numero de linhas: ");
    scanf("%d", &m);
    printf("Numero de colunas: ");
    scanf("%d", &n);

    int mat[m][n], t[n][m];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    transposta(m, n, mat, t);

    printf("\n-Matriz Transposta-\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d\t", t[i][j]);
        }
        printf("\n");
    }

    return 0;
}
