#include "pontos.h"
#include <math.h>

float distancia(Ponto p1, Ponto p2){
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
};