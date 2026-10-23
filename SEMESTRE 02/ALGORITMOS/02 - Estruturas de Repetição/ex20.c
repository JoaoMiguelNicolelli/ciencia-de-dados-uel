#include <stdio.h>

int main(){

    int inicio, fim;

    printf("Inicio do intervalo: ");
    scanf("%d", &inicio);
    printf("Fim do intervalo: ");
    scanf("%d", &fim);

    if(inicio > fim){
        int aux = inicio;
        inicio = fim;
        fim = aux;
    }

    int qtd_primos = 0;
    int anterior = 0;
    int maior_gap = 0;

    printf("Primos no intervalo: ");

    for(int n = inicio; n <= fim; n++){
        if(n < 2){
            continue;
        }

        int primo = 1;

        for(int j = 2; j * j <= n; j++){
            if(n % j == 0){
                primo = 0;
                break;
            }
        }

        if(primo){
            printf("%d ", n);

            if(qtd_primos > 0 && n - anterior > maior_gap){
                maior_gap = n - anterior;
            }

            anterior = n;
            qtd_primos += 1;
        }
    }

    printf("\nQuantidade de primos: %d\n", qtd_primos);

    if(qtd_primos >= 2){
        printf("Maior gap entre primos consecutivos: %d\n", maior_gap);
    }else{
        printf("Nao ha primos suficientes para calcular o gap.\n");
    }

    return 0;
}
