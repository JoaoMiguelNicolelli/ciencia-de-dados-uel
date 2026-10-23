#include <stdio.h>

int main(){

    int matricula;
    float nota1, nota2, nota3, media_exercicios;
    printf("Numero de matricula: ");
    scanf("%d", &matricula);
    printf("Nota 1: ");
    scanf("%f", &nota1);
    printf("Nota 2: ");
    scanf("%f", &nota2);
    printf("Nota 3: ");
    scanf("%f", &nota3);
    printf("Media dos exercicios: ");
    scanf("%f", &media_exercicios);

    float media_total = (nota1 + nota2 + nota3 + media_exercicios) / 4;

    char conceito;
    if (media_total >= 90) {
        conceito = 'A';
    }
    else if (media_total >= 75) {
        conceito = 'B';
    }
    else if (media_total >= 60) {
        conceito = 'C';
    }
    else if (media_total >= 40) {
        conceito = 'D';
    }
    else {
        conceito = 'E';
    }

    printf("\nMatricula: %d\n", matricula);
    printf("Notas: %.2f | %.2f | %.2f\n", nota1, nota2, nota3);
    printf("Media dos exercicios: %.2f\n", media_exercicios);
    printf("Media total: %.2f\n", media_total);
    printf("Conceito: %c\n", conceito);

    if (conceito == 'A' || conceito == 'B' || conceito == 'C') {
        printf("Aprovado\n");
    }
    else {
        printf("Reprovado\n");
    }

    return 0;
}
