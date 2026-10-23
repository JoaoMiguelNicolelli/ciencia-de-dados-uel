#include <stdio.h>

int main(){

    float frequencia, nota;
    printf("Frequencia do aluno (0 a 100%%): ");
    scanf("%f", &frequencia);
    printf("Nota do aluno (0.0 a 10.0): ");
    scanf("%f", &nota);

    if (frequencia < 0 || frequencia > 100 || nota < 0 || nota > 10) {
        printf("Valores invalidos!\n");
        return 1;
    }

    if (frequencia <= 75) {
        printf("REPROVADO\n");
    }
    else if (nota <= 3.0f) {
        printf("REPROVADO\n");
    }
    else if (nota < 7.0f) {
        printf("EXAME\n");
    }
    else {
        printf("APROVADO\n");
    }

    return 0;
}
