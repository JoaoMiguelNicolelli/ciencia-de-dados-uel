#include <stdio.h>

int main(){

    int a, b, MDC, MMC;
    
    printf("Agregue um valor para A: ");
    scanf("%d", &a);

    
    printf("Agregue um valor para B: ");
    scanf("%d", &b);

    if(a >= 0 && b >= 0){
       
        int tmpA = a;
        int tmpB = b;
        int aux;

        while(tmpB != 0){

            aux = tmpA % tmpB;
            tmpA = tmpB;
            tmpB = aux;

        }

        MDC = tmpA;
        MMC = (a*b) / MDC;
    
        printf("\n");
        printf("MDC (%d, %d) = %d\n", a, b, MDC);
        printf("MMC (%d, %d) = %d\n", a, b, MMC);

    }else{
        printf("OPERACAO INVALIDA.");
    }

    return 0;
}