#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    char prato[50];
    printf("--PRATOS DISPONIVEIS--\n1- Vegetariano\n2- Peixe Grelhado\n3- Frango Grelhado\n4- Carne Assada\n");

    fgets(prato, sizeof(prato), stdin);
    for(int i = 0; prato[i] != '\0'; i++){
        if(prato[i] == '\n'){
            prato[i] = '\0';
        }
        prato[i] = tolower(prato[i]);
    }

    int calorias_prato;
    if (strcmp(prato, "frango grelhado") == 0) {
        calorias_prato = 340;
    }
    else if (strcmp(prato, "vegetariano") == 0) {
        calorias_prato = 380;
    }
    else if (strcmp(prato, "peixe grelhado") == 0) {
        calorias_prato = 320;
    }
    else if (strcmp(prato, "carne assada") == 0) {
        calorias_prato = 560;
    }
    else {
        printf("Prato nao encontrado!\n");
        return 1;
    }

    char sobremesa[50];
    printf("--SOBREMESAS DISPONIVEIS--\n1- Salada de Frutas\n2- Pudim Pequeno\n3- Gelatina\n4- Mousse de Chocolate\n");

    fgets(sobremesa, sizeof(sobremesa), stdin);
    for(int i = 0; sobremesa[i] != '\0'; i++){
        if(sobremesa[i] == '\n'){
            sobremesa[i] = '\0';
        }
        sobremesa[i] = tolower(sobremesa[i]);
    }

    int calorias_sobremesa;
    if (strcmp(sobremesa, "salada de frutas") == 0) {
        calorias_sobremesa = 95;
    }
    else if (strcmp(sobremesa, "pudim pequeno") == 0) {
        calorias_sobremesa = 180;
    }
    else if (strcmp(sobremesa, "gelatina") == 0) {
        calorias_sobremesa = 50;
    }
    else if (strcmp(sobremesa, "mousse de chocolate") == 0) {
        calorias_sobremesa = 260;
    }
    else {
        printf("Sobremesa nao encontrada!\n");
        return 1;
    }

    char bebida[50];
    printf("--BEBIDAS DISPONIVEIS--\n1- Cha sem Acucar\n2- Suco de Laranja\n3- Suco de Melao\n4- Refrigerante Zero\n");

    fgets(bebida, sizeof(bebida), stdin);
    for(int i = 0; bebida[i] != '\0'; i++){
        if(bebida[i] == '\n'){
            bebida[i] = '\0';
        }
        bebida[i] = tolower(bebida[i]);
    }

    int calorias_bebida;
    if (strcmp(bebida, "cha sem acucar") == 0) {
        calorias_bebida = 2;
    }
    else if (strcmp(bebida, "suco de laranja") == 0) {
        calorias_bebida = 110;
    }
    else if (strcmp(bebida, "suco de melao") == 0) {
        calorias_bebida = 90;
    }
    else if (strcmp(bebida, "refrigerante zero") == 0) {
        calorias_bebida = 1;
    }
    else {
        printf("Bebida nao encontrada!\n");
        return 1;
    }

    int calorias_total = calorias_prato + calorias_sobremesa + calorias_bebida;
    printf("Total de calorias da refeicao: %d kcal\n", calorias_total);

    return 0;
}
