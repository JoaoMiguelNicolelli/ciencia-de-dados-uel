#include <stdio.h>

int main(){

    char frase[200];
    printf("Digite uma frase: ");
    fgets(frase, 200, stdin);

    int palavras = 0;
    int dentroPalavra = 0;

    for(int i = 0; frase[i] != '\0'; i++){
        if(frase[i] == ' ' || frase[i] == '\n' || frase[i] == '\t'){
            dentroPalavra = 0;
        }else if(!dentroPalavra){
            dentroPalavra = 1;
            palavras++;
        }
    }

    printf("Quantidade de palavras: %d\n", palavras);

    return 0;
}
