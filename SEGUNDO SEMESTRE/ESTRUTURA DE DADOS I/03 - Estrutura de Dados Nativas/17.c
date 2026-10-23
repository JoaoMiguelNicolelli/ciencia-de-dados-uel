#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Ponto;

double distancia(Ponto a, Ponto b){
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    return sqrt(dx * dx + dy * dy);
}

Ponto pontoMedio(Ponto a, Ponto b){
    Ponto m;
    m.x = (a.x + b.x) / 2;
    m.y = (a.y + b.y) / 2;
    return m;
}

int main(){

    Ponto p1, p2;
    printf("Ponto 1 (x y): ");
    scanf("%lf %lf", &p1.x, &p1.y);
    printf("Ponto 2 (x y): ");
    scanf("%lf %lf", &p2.x, &p2.y);

    printf("\nDistancia: %.2f\n", distancia(p1, p2));

    Ponto m = pontoMedio(p1, p2);
    printf("Ponto medio: (%.2f, %.2f)\n", m.x, m.y);

    return 0;
}
