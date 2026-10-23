#include <stdio.h>

void produtoMatrizes(int m, int p, int n, int a[m][p], int b[p][n], int c[m][n]){

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            c[i][j] = 0;
            for(int k = 0; k < p; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main(){

    int m, p, n;
    printf("Linhas da matriz A (m): ");
    scanf("%d", &m);
    printf("Colunas de A / Linhas de B (p): ");
    scanf("%d", &p);
    printf("Colunas da matriz B (n): ");
    scanf("%d", &n);

    int a[m][p], b[p][n], c[m][n];

    printf("\n-Matriz A-\n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < p; j++){
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\n-Matriz B-\n");
    for(int i = 0; i < p; i++){
        for(int j = 0; j < n; j++){
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    produtoMatrizes(m, p, n, a, b, c);

    printf("\n-Matriz Produto (A x B)-\n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
