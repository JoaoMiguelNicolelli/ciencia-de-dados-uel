#include <stdio.h>
#include <math.h>

struct Ponto{
    int x;
    int y;
};

int main (){

    struct Ponto a, b;

    printf("Ponto a (X, Y): ");
    scanf("%d %d", &a.x, &a.y);

    printf("Ponto b (X, Y): ");
    scanf("%d %d", &b.x, &b.y);

    double distancia;
    distancia = sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));

    printf("\nPonto A: (%d, %d)\tPonto B: (%d, %d)\n", a.x, a.y, b.x, b.y);
    printf("Distancia: %.2f", distancia);

    return 0;
}