#include <stdio.h>

void Triangulo(int n){
    int i, j;

    for(i = 1; i <= n; i++){
        for(j = 0; j < i; j++){
            printf("*");
        }
        printf("\n");
    }
    for(i = n - 1; i >= 1; i--){
        for(j = 0; j < i; j++){
            printf("*");
        }
        printf("\n");
    }
}

int main(){
    int n;

    printf("Digite n: ");
    scanf("%d", &n);

    Triangulo(n);

    return 0;
}
