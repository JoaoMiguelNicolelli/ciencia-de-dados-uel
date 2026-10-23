#include "geometria.h"

float perimetroTriangulo(Ponto p1, Ponto p2, Ponto p3) {
    return distancia(p1, p2) +
           distancia(p2, p3) +
           distancia(p3, p1);
}