#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inverteString(char *str) {
    int i, tam;
    char *invertida;

    tam = strlen(str);
    invertida = (char *) malloc((tam + 1) * sizeof(char));
    if (invertida == NULL) {
        return NULL;
    }

    for (i = 0; i < tam; i++) {
        invertida[i] = str[tam - 1 - i];
    }
    invertida[tam] = '\0';

    return invertida;
}

int main() {
    char str[100];
    char *invertida;

    printf("Digite uma string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';

    invertida = inverteString(str);
    if (invertida == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    printf("String invertida: %s\n", invertida);

    free(invertida);

    return 0;
}
