#ifndef GUERREIRO_H
#define GUERREIRO_H

#include <string>
#include "Jogador.h"

class Guerreiro : public Jogador {
public:
    Guerreiro(const std::string& nome, int hpMaximo, const Atributos& atributos);

    void agir(Personagem& alvo) override;
};

#endif