#include <stdio.h>

int main(){

    int n;

    while(1){

        printf("Digite um inteiro (multiplo de 9 para parar): ");
        scanf("%d", &n);


        if(n % 9 == 0){
            printf("Multiplo de 9 digitado. Encerrando progama!");
            break;
        }else{
            if(n % 5 == 0){
                printf("O numero %d eh um multiplo de 5.", n);
                printf("\n");
            }else{
                printf("O numero %d nao eh um multiplo de 5.", n);
                printf("\n");
            }
        }   
    }

    return 0;
}