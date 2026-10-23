#include <stdio.h>
#include <string.h>

int Pertence(char *frase, char *palavra){
    char *p = frase;

    while(*p != '\0'){
        char *p1 = p;
        char *p2 = palavra;

        while(*p != '\0' && *p1 == *p2){
            p1++;
            p2++;
        }

        if(*p2 == '\0'){
            return 1;
        }
        p++;
    }

    return 0;
}

int main(){
    char frase[100];
    char palavra[100];

    printf("Digite a frase: ");
    fgets(frase, 100, stdin);
    frase[strcspn(frase, "\n")] = '\0';

    printf("Digite a palavra que quer procurar: ");
    fgets(palavra, 100, stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    if (Pertence(frase, palavra)){
        printf("\nEncontrado: \"%s\" ocorre dentro da frase.\n", palavra);
    }
    else{
        printf("\nNao encontrado: \"%s\" nao ocorre na frase.\n", palavra);
    }
        
    return 0;
}