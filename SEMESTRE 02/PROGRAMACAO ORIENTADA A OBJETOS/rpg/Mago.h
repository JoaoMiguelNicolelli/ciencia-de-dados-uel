#ifndef MAGO_H
#define MAGO_H

#include <string>
#include "Jogador.h"

class Mago : public Jogador {
public:
    Mago(const std::string& nome, int hpMaximo, const Atributos& atributos);

    void agir(Personagem& alvo) override;
};

#endif