#include <stdio.h>
#include <math.h>

int main(){

    int valor;

    printf("Digite um valor (zero ou negativo para sair): ");
    scanf("%d", &valor);

    while(valor > 0){
        if(valor % 2 == 0){
            printf("Quadrado de %d: %d\n", valor, valor * valor);
        }else{
            printf("Raiz quadrada de %d: %.2f\n", valor, sqrt(valor));
        }

        printf("Digite um valor (zero ou negativo para sair): ");
        scanf("%d", &valor);
    }

    printf("Fim da entrada de dados.\n");

    return 0;
}
