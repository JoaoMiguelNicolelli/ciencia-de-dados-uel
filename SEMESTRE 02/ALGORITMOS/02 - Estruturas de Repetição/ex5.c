#include <stdio.h>

int main(){

    int valores[7];

    for(int i = 0; i < 7; i++){
        printf("Numero %d: ", i+1);
        scanf("%d", &valores[i]);
    }

    for(int i = 0; i < 7; i++){
        if(valores[i] < 0){
            printf("Nao existe fatorial de numero negativo (%d)!\n", valores[i]);
        }else{
            long long fatorial = 1;

            for(int j = 2; j <= valores[i]; j++){
                fatorial *= j;
            }

            printf("%d! = %lld\n", valores[i], fatorial);
        }
    }

    return 0;
}
