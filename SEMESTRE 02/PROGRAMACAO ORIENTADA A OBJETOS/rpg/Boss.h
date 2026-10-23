#ifndef BOSS_H
#define BOSS_H

#include <string>
#include "Monstro.h"

class Boss : public Monstro {
private:
    static int quantidade;
    int contadorAcoes;

    Boss(const std::string& nome, int hpMaximo, const Atributos& atributos, int xpRecompensa);

public:
    static Boss* criar(const std::string& nome, int hpMaximo, const Atributos& atributos, int xpRecompensa);

    ~Boss() override;

    void agir(Personagem& alvo) override;
};

#endif