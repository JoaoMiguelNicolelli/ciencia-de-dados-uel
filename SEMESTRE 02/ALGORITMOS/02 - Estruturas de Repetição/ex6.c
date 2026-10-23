#include <stdio.h>

int main(){

    int valores[10];

    for(int i = 0; i < 10; i++){
        do{
            printf("Numero %d: ", i+1);
            scanf("%d", &valores[i]);

            if(valores[i] <= 0){
                printf("Digite um valor positivo!\n");
            }
        }while(valores[i] <= 0);
    }

    for(int i = 0; i < 10; i++){
        int qtd_divisores = 0;
        int somatorio = 0;

        for(int j = 1; j <= valores[i]; j++){
            if(valores[i] % j == 0){
                qtd_divisores += 1;
            }
            somatorio += j;
        }

        printf("Valor %d: %d divisores | somatorio de 1 ate %d = %d\n", valores[i], qtd_divisores, valores[i], somatorio);
    }

    return 0;
}
