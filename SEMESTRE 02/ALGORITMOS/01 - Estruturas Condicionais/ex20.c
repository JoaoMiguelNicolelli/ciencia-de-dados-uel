#include <stdio.h>
#include <math.h>

int main(){

    int numero;
    printf("Digite um numero de 4 algarismos: ");
    scanf("%d", &numero);

    if (numero < 1000 || numero > 9999) {
        printf("Numero invalido! Digite um numero entre 1000 e 9999.\n");
        return 1;
    }

    int primeira_dezena = numero / 100;
    int segunda_dezena = numero % 100;
    int soma_dezenas = primeira_dezena + segunda_dezena;
    double raiz = sqrt(numero);

    printf("Dezenas: %02d + %02d = %d\n", primeira_dezena, segunda_dezena, soma_dezenas);
    printf("Raiz quadrada de %d: %.2f\n", numero, raiz);

    if (raiz == soma_dezenas) {
        printf("A raiz quadrada de %d e igual a soma de suas dezenas.\n", numero);
    }
    else {
        printf("A raiz quadrada de %d NAO e igual a soma de suas dezenas.\n", numero);
    }

    return 0;
}
