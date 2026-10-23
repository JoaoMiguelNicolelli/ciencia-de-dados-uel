#include <stdio.h>

int main(){

    int homem1, homem2, mulher1, mulher2;
    printf("Idade do primeiro homem: ");
    scanf("%d", &homem1);
    printf("Idade do segundo homem: ");
    scanf("%d", &homem2);
    printf("Idade da primeira mulher: ");
    scanf("%d", &mulher1);
    printf("Idade da segunda mulher: ");
    scanf("%d", &mulher2);

    int homem_velho, homem_novo;
    if (homem1 > homem2) {
        homem_velho = homem1;
        homem_novo = homem2;
    }
    else {
        homem_velho = homem2;
        homem_novo = homem1;
    }

    int mulher_velha, mulher_nova;
    if (mulher1 > mulher2) {
        mulher_velha = mulher1;
        mulher_nova = mulher2;
    }
    else {
        mulher_velha = mulher2;
        mulher_nova = mulher1;
    }

    int soma = homem_velho + mulher_nova;
    int produto = homem_novo * mulher_velha;

    printf("Soma (homem mais velho + mulher mais nova): %d\n", soma);
    printf("Produto (homem mais novo x mulher mais velha): %d\n", produto);

    return 0;
}
