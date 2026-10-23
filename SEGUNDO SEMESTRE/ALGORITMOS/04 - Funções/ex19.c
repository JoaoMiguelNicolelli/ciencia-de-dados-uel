#include <stdio.h>

void HanoiRecursivo(int n, int origem, int destino, int auxiliar){
    if(n == 0){
        return;
    }
    HanoiRecursivo(n - 1, origem, auxiliar, destino);
    printf("Mover disco %d do pino %d para o pino %d\n", n, origem, destino);
    HanoiRecursivo(n - 1, auxiliar, destino, origem);
}

void HanoiIterativo(int n){
    int i, total = 1, origem, destino, disco, k;

    for(i = 0; i < n; i++){
        total = total * 2;
    }

    for(i = 1; i < total; i++){
        origem = (i & (i - 1)) % 3;
        destino = ((i | (i - 1)) + 1) % 3;

        if(n % 2 == 0){
            if(origem != 0){
                origem = 3 - origem;
            }
            if(destino != 0){
                destino = 3 - destino;
            }
        }

        disco = 1;
        k = i;
        while(k % 2 == 0){
            disco++;
            k = k / 2;
        }

        printf("Mover disco %d do pino %d para o pino %d\n", disco, origem, destino);
    }
}

int main(){
    int n;

    printf("Digite o numero de discos: ");
    scanf("%d", &n);

    printf("\nVersao recursiva:\n");
    HanoiRecursivo(n, 0, 2, 1);

    printf("\nVersao iterativa:\n");
    HanoiIterativo(n);

    return 0;
}
