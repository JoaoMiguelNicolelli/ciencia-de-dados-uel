#include <stdio.h>

int main(){

    int n;

    printf("Digite um inteiro positivo: ");
    scanf("%d", &n);

    printf("Divisiveis de %d: ", n);
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            printf("%i ", i);
        }

    }

    return 0;
}