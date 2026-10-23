#include <stdio.h>
#include <ctype.h>

int main(){

    char frase[200];
    printf("Digite uma frase: ");
    fgets(frase, 200, stdin);

    int vogais = 0, consoantes = 0, digitos = 0, espacos = 0;

    for(int i = 0; frase[i] != '\0'; i++){
        char c = tolower(frase[i]);

        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            vogais++;
        }else if(c >= 'a' && c <= 'z'){
            consoantes++;
        }else if(c >= '0' && c <= '9'){
            digitos++;
        }else if(c == ' '){
            espacos++;
        }
    }

    printf("Vogais: %d\n", vogais);
    printf("Consoantes: %d\n", consoantes);
    printf("Digitos: %d\n", digitos);
    printf("Espacos em branco: %d\n", espacos);

    return 0;
}
