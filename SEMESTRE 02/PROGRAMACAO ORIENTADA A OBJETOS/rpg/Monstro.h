#ifndef MONSTRO_H
#define MONSTRO_H

#include <string>
#include "Personagem.h"

class Monstro : public Personagem {
private:
    int xpRecompensa;

public:
    Monstro(const std::string& nome, int hpMaximo, const Atributos& atributos, int xpRecompensa);

    int getXpRecompensa() const;
};

#endif