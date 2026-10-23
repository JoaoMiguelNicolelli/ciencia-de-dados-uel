#ifndef ARQUEIRO_H
#define ARQUEIRO_H

#include <string>
#include "Jogador.h"

class Arqueiro : public Jogador {
public:
    Arqueiro(const std::string& nome, int hpMaximo, const Atributos& atributos);

    void agir(Personagem& alvo) override;
};

#endif