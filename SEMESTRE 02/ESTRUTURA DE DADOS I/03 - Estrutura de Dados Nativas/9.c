#include <stdio.h>

int main(){

    int n;
    printf("Ordem da matriz: ");
    scanf("%d", &n);

    int mat[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    int somaPrincipal = 0, somaSecundaria = 0;
    for(int i = 0; i < n; i++){
        somaPrincipal += mat[i][i];
        somaSecundaria += mat[i][n - 1 - i];
    }

    printf("\nSoma da diagonal principal: %d\n", somaPrincipal);
    printf("Soma da diagonal secundaria: %d\n", somaSecundaria);

    int simetrica = 1;
    for(int i = 0; i < n && simetrica; i++){
        for(int j = i + 1; j < n; j++){
            if(mat[i][j] != mat[j][i]){
                simetrica = 0;
                break;
            }
        }
    }

    if(simetrica){
        printf("A matriz e simetrica.\n");
    }else{
        printf("A matriz nao e simetrica.\n");
    }

    return 0;
}
