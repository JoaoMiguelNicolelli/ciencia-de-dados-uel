#include <stdio.h>

int main(){
    int a, *b, **c, ***d;

    printf("Digite um valor: ");
    scanf("%d", &a);

    b = &a;    
    c = &b;    
    d = &c;    

    printf("\nValor lido: %d\n", a);
    printf("Dobro (usando b): %d\n", *b   * 2);
    printf("Triplo (usando c): %d\n", **c  * 3);
    printf("Quadruplo (usando d): %d\n", ***d * 4);

    return 0;
}