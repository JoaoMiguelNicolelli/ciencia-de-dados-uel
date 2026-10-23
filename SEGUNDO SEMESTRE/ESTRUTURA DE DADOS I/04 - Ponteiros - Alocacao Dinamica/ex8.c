#include <stdio.h>
#include <stdlib.h>

char *copiaCadeia(const char *s){

    int tam = 0;
    const char *p = s;

    while(*p != '\0'){
        tam++;
        p++;
    }

    char *copia = malloc((tam + 1) * sizeof(char)); // +1 para o '\0'

    if(copia == NULL){
        return NULL;
    }

    const char *origem = s;
    char *destino = copia;

    while(*origem != '\0'){
        *destino = *origem;
        origem++;
        destino++;
    }

    *destino = '\0'; 

    return copia;
}

int main(){

    char cadeia[100];

    printf("Cadeia: ");
    fgets(cadeia, 100, stdin);

    for(char *p = cadeia; *p != '\0'; p++){
        if(*p == '\n'){
            *p = '\0';
        }
    }

    char *copia = copiaCadeia(cadeia);

    if(copia == NULL){
        printf("Memoria insuficiente\n");
        return 1;
    }

    printf("Original: %s\n", cadeia);
    printf("Copia:    %s\n", copia);

    free(copia);
    copia = NULL;

    return 0;
}
