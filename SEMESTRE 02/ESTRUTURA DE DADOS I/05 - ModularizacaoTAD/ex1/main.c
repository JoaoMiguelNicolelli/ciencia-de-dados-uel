#include <stdio.h>
#include "pontos.h"
#include "geometria.h"

int main() {

    Ponto p1 = {0, 0};
    Ponto p2 = {3, 0};
    Ponto p3 = {0, 4};

    printf("Distancia entre p1 e p2: %.2f\n", distancia(p1, p2));

    printf("Perimetro do triangulo: %.2f\n", perimetroTriangulo(p1, p2, p3));

    return 0;
}
