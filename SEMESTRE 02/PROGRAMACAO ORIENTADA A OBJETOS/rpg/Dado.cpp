#include "Dado.h"
#include <ctime>

using namespace std;

mt19937 Dado::gerador(static_cast<unsigned int>(time(nullptr)));

int Dado::entre(int minimo, int maximo) {
    uniform_int_distribution<int> distribuicao(minimo, maximo);
    return distribuicao(gerador);
}

int Dado::rolar(int lados) {
    return entre(1, lados);
}