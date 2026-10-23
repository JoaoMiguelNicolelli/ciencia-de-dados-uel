#include <stdio.h>

int main(){

    int x, y;

    for(int i = 0; i < 5; i++){
        int a, b;

        printf("Par %d - primeiro valor: ", i+1);
        scanf("%d", &a);
        printf("Par %d - segundo valor: ", i+1);
        scanf("%d", &b);

        if(a < b){
            x = a;
            y = b;
        }else{
            x = b;
            y = a;
        }

        int soma = 0;

        for(int j = x; j <= y; j++){
            soma += j;
        }

        printf("Soma dos inteiros de %d ate %d: %d\n\n", x, y, soma);
    }

    return 0;
}
