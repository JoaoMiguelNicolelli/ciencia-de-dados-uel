#include <stdio.h>
#include <string.h>

void conta_letras(char *frase, int *vogais, int *consoantes){
    char *p = frase;

    *vogais = 0;
    *consoantes = 0;

    while (*p != '\0') {
        char c = *p;

        if (c >= 'A' && c <= 'Z') {
            c = c + ('a' - 'A');
        }

        if (c >= 'a' && c <= 'z') {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                (*vogais)++;
            }
            else {
                (*consoantes)++;
            }
        }
        p++;
    }
}

int main(){
    char frase[81];
    int vogais, consoantes;

    printf("Digite a frase (max 80 caracteres): ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';

    conta_letras(frase, &vogais, &consoantes);

    printf("\nVogais: %d\n", vogais);
    printf("Consoantes: %d\n", consoantes);

    return 0;
}
