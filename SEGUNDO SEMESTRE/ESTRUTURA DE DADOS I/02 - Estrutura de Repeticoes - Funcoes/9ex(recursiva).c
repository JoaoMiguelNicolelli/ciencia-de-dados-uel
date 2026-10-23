//ignora professor, uso pra estudar e quero deixar anotado

#include <stdio.h>

int MDC(int a, int b){
    if(b==0){
        return a;
    }
    return MDC(b, a % b); //return (b, a % b) ---recursividade---> return MDC(b, a % b)
}

int MMC(int a, int b){
    return ((a*b) / MDC(a, b));
}

int main(){

    int num1, num2;

    printf("Digite (num1 num2): ");
    scanf("%d %d", &num1, &num2);

    if(num1 > 0 && num2 > 0){
        int result = MMC(num1, num2);
        printf("MMC(%d, %d) = %d", num1, num2, result);
    }
    
    return 0;
}