#include <stdio.h>

int main(){

    int inferior, superior;

    printf("Limite inferior: ");
    scanf("%d", &inferior);
    printf("Limite superior: ");
    scanf("%d", &superior);

    int soma = 0;

    printf("Saida: ");

    for(int i = inferior + 1; i < superior; i++){
        if(i % 2 == 0){
            printf("%d ", i);
            soma += i;
        }
    }

    printf("\nSoma: %d\n", soma);

    return 0;
}
