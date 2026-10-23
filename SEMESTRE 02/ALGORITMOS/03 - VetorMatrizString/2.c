#include <stdio.h>

int main(){

    int vetor[10];

    printf("Elemento 1: ");
    scanf("%d", &vetor[0]);

    int aux;
    for(int i = 1; i < 10; i++){
        int repetido;
        do{
            printf("Elemento %d: ", i+1);
            scanf("%d", &aux);

            repetido = 0;
            for(int j = 0; j < i; j++){
                if(vetor[j] == aux){
                    repetido = 1;
                    printf("Elemento ja existente, digite outro.\n");
                    break;
                }
            }

        }while(repetido);

        vetor[i] = aux;
    }

    for(int i = 0; i < 10; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}
