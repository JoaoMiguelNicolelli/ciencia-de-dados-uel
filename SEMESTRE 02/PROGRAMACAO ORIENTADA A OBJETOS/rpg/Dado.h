#ifndef DADO_H
#define DADO_H

#include <random>

class Dado {
private:
    static std::mt19937 gerador;

public:
    static int rolar(int lados);
    static int entre(int minimo, int maximo);
};

#endif