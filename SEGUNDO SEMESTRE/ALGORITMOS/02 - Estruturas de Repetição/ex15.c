#include <stdio.h>

int main(){

    int num;
    int intervalo1 = 0;
    int intervalo2 = 0;
    int intervalo3 = 0;
    int intervalo4 = 0;

    printf("Digite um numero (negativo para sair): ");
    scanf("%d", &num);

    while(num >= 0){
        if(num <= 25){
            intervalo1 += 1;
        }else if(num <= 50){
            intervalo2 += 1;
        }else if(num <= 75){
            intervalo3 += 1;
        }else if(num <= 100){
            intervalo4 += 1;
        }else{
            printf("%d esta fora dos intervalos.\n", num);
        }

        printf("Digite um numero (negativo para sair): ");
        scanf("%d", &num);
    }

    printf("\n[0-25]: %d\n", intervalo1);
    printf("[26-50]: %d\n", intervalo2);
    printf("[51-75]: %d\n", intervalo3);
    printf("[76-100]: %d\n", intervalo4);

    return 0;
}
