#ifndef MINION_H
#define MINION_H

#include <string>
#include "Monstro.h"

class Minion : public Monstro {
public:
    Minion(const std::string& nome, int hpMaximo, const Atributos& atributos, int xpRecompensa);
};

#endif