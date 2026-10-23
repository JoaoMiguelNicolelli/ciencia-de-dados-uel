#include <stdio.h>
#include <math.h>

typedef struct{
    int x;
    int y;
}Ponto;

typedef struct{
    Ponto sup_esq;
    Ponto inf_dir;
}Retangulo;

int main(){

    Retangulo ret;
    int largura, altura, area, perimetro;
    double diagonal;

    printf("Ponto superior esquerdo (x, y): ");
    scanf("%d %d", &ret.sup_esq.x, &ret.sup_esq.y);

    printf("Ponto inferior direito (x, y): ");
    scanf("%d %d", &ret.inf_dir.x, &ret.inf_dir.y);

    largura = ret.inf_dir.x - ret.sup_esq.x;
    altura = ret.sup_esq.y - ret.inf_dir.y;
    
    area = largura * altura;
    perimetro = 2 * (largura + altura);

    diagonal = sqrt((largura * largura) + (altura * altura));

    printf("Largura: %d | Altura: %d\n", largura, altura);
    printf("Área: %d\n", area);
    printf("Perímetro: %d\n", perimetro);
    printf("Comprimento da Diagonal: %.2f\n", diagonal);

    return 0;
}