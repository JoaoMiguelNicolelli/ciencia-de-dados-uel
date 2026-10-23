#include <stdio.h>

void inverteCadeia(char *s){

    if(*s == '\0') return; 

    char *inicio = s;
    char *fim = s;

    while(*(fim + 1) != '\0'){ 
        fim++;
    }

    while(inicio < fim){
        char aux = *inicio;
        *inicio = *fim;
        *fim = aux;

        inicio++;
        fim--;
    }
}

int main(){

    char cadeia[100];

    printf("Digite uma frase: ");
    fgets(cadeia, 100, stdin);

    for(char *p = cadeia; *p != '\0'; p++){
        if(*p == '\n'){
            *p = '\0';
        }
    }

    inverteCadeia(cadeia);

    printf("Invertida: %s\n", cadeia);

    return 0;
}
