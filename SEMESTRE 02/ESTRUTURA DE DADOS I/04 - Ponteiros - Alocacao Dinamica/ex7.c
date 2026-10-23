#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    printf("Quantidade de notas: ");
    scanf("%d", &n);

    int *freq = calloc(11, sizeof(int));

    if(freq == NULL){
        printf("Memoria insuficiente\n");
        return 1;
    }

    for(int i = 0; i < n; i++){
        int nota;

        printf("Nota %d: ", i+1);
        scanf("%d", &nota);

        freq[nota]++; 
    }

    printf("\n--Frequencias--\n");
    for(int i = 0; i <= 10; i++){
        if(freq[i] > 0){
            printf("Nota %d: %d ocorrencia(s)\n", i, freq[i]);
        }
    }

    free(freq);
    freq = NULL;

    return 0;
}
