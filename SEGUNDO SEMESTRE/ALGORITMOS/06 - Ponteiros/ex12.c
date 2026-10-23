#include <stdio.h>
#include <string.h>

void imprime_palavras(char *frase){
    char *p = frase;

    while (*p != '\0') {
        if (*p == ' ') {
            printf("\n");
            while (*p == ' ') {
                p++;
            }
        }
        else {
            printf("%c", *p);
            p++;
        }
    }
    printf("\n");
}

int main(){
    char frase[61];

    printf("Digite a frase (max 60 caracteres): ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';

    printf("\n");
    imprime_palavras(frase);

    return 0;
}
