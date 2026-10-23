#include <stdio.h>

int MDC(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int MMC (int a, int b){
    return ((a*b) / MDC(a, b));
}
    
int main(){

    int num1, num2;

    printf("Digite o numero 1: ");
    scanf("%d", &num1);

    printf("Digite o numero 2: ");
    scanf("%d", &num2);

    if(num1 > 0 && num2 > 0){
        int result = MMC(num1, num2);
        printf("MMC (%d, %d) = %d", num1, num2, result);
    }else{
        printf("Erro: Digite apenas numeros maiores que zero.\n");
    }
    
    return 0;
}