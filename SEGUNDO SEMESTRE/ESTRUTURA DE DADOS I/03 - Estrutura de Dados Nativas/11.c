#include <stdio.h>

int meu_strlen(char s[]){

    int tam = 0;
    while(s[tam] != '\0'){
        tam++;
    }
    return tam;
}

int main(){

    char palavra[100];
    printf("Digite uma palavra: ");
    scanf("%99s", palavra);

    printf("Comprimento: %d\n", meu_strlen(palavra));

    return 0;
}
