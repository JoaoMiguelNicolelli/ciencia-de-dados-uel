#include <stdio.h>

int potencia(int base, int expoente){

    if(expoente == 0){
        return 1;
    }

    int resultado = 1;

    for(int i = 1; i <= expoente; i++){
        resultado *= base; //resultado recebe a multiplicacao entre resultado * base (expoente vezes) --> num1 = 9 e num2 = 3 --> for(int i = 1, i <= 3; i++) --> 1 *= 9 --> 9 *= 9 --> 81 *= 9
    }
    return resultado;
}

int main(){

    int num1, num2;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num1);

    printf("Digite o numero que quer elevar %d: ", num1);
    scanf("%d", &num2);

    if(num2 >= 0){
        
        int result = potencia(num1, num2);
        printf("O numero %d elevado a %d resulta em %d.", num1, num2, result);

    }

    return 0;
}