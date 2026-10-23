#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    char frase[200];
    printf("Digite uma frase: ");
    fgets(frase, 200, stdin);
    frase[strcspn(frase, "\n")] = '\0';

    // copia sem espacos e em minusculo
    char limpa[200];
    int tam = 0;
    for(int i = 0; frase[i] != '\0'; i++){
        if(frase[i] != ' '){
            limpa[tam] = tolower(frase[i]);
            tam++;
        }
    }
    limpa[tam] = '\0';

    int palindromo = 1;
    for(int i = 0; i < tam / 2; i++){
        if(limpa[i] != limpa[tam - 1 - i]){
            palindromo = 0;
            break;
        }
    }

    if(palindromo){
        printf("A frase e um palindromo.\n");
    }else{
        printf("A frase nao e um palindromo.\n");
    }

    return 0;
}
