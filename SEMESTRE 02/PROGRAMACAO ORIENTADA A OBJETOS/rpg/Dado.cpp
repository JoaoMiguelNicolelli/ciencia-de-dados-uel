#include "Dado.h"
#include <cstdlib>
#include <ctime>

void Dado::iniciar() {
    srand(time(nullptr));
}

int Dado::rolar(int lados) {
    return rand() % lados + 1;
}