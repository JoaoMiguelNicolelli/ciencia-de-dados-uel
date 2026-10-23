#include <stdio.h>

int main(){

    int febre, tosse, dor_cabeca, cansaco;
    printf("--INTENSIDADE DOS SINTOMAS--\n0- Nenhum\n1- Leve\n2- Moderado\n3- Forte\n");

    printf("Febre: ");
    scanf("%d", &febre);
    printf("Tosse: ");
    scanf("%d", &tosse);
    printf("Dor de cabeca: ");
    scanf("%d", &dor_cabeca);
    printf("Cansaco: ");
    scanf("%d", &cansaco);

    if (febre < 0 || febre > 3 || tosse < 0 || tosse > 3 || dor_cabeca < 0 || dor_cabeca > 3 || cansaco < 0 || cansaco > 3) {
        printf("Valores invalidos! Use apenas valores de 0 a 3.\n");
        return 1;
    }

    if (febre >= 2) {
        if (cansaco >= 2 || tosse >= 2) {
            printf("Sugestao: Gripe leve\n");
        }
        else {
            printf("Sugestao: Nenhuma indicacao clara\n");
        }
    }
    else if (tosse >= 2) {
        if (dor_cabeca <= 1) {
            printf("Sugestao: Resfriado\n");
        }
        else {
            printf("Sugestao: Nenhuma indicacao clara\n");
        }
    }
    else if (dor_cabeca >= 2) {
        if (febre == 0 && tosse == 0) {
            printf("Sugestao: Enxaqueca\n");
        }
        else {
            printf("Sugestao: Nenhuma indicacao clara\n");
        }
    }
    else {
        printf("Sugestao: Nenhuma indicacao clara\n");
    }

    printf("ATENCAO: este programa NAO substitui um diagnostico medico. Procure um profissional de saude.\n");

    return 0;
}
