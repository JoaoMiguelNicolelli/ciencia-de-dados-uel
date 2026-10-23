#include <stdio.h>

int Encaixa(int a, int b){
    while(b > 0){
        if(a % 10 != b % 10){
            return 0;
        }
        a = a / 10;
        b = b / 10;
    }
    return 1;
}

int Segmento(int maior, int menor){
    while(maior >= menor){
        if(Encaixa(maior, menor)){
            return 1;
        }
        maior = maior / 10;
    }
    return 0;
}

int main(){
    int a, b;

    printf("Digite a e b: ");
    scanf("%d %d", &a, &b);

    if(a >= b && Segmento(a, b)){
        printf("b e segmento de a\n");
    }else if(b > a && Segmento(b, a)){
        printf("a e segmento de b\n");
    }else{
        printf("um nao e segmento do outro\n");
    }

    return 0;
}
