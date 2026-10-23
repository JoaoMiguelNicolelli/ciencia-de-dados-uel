#include <stdio.h>

int inverterNumero(int n){
    int invertido = 0;

    while(n > 0){
        int digito = n % 10;
        invertido = (invertido * 10) + digito;
        n /= 10;
    }
    return invertido;
}

int ehPalindromo(int n){
    if(inverterNumero(n) == n){
        return 1;
    }
    return 0;
}

int main(){

    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);

    if(ehPalindromo(num)){
        printf("\nO numero %d eh um palindromo!\n", num);
    }else{
        printf("\nO numero %d nao eh um palindromo.", num);
        printf("\nO numero %d invertido eh %d.", num, inverterNumero(num));
    }

    return 0;
}