#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include "Personagem.h"

class Jogador : public Personagem {
private:
    int xp;

public:
    Jogador(const std::string& nome, int hpMaximo, const Atributos& atributos);

    int getXp() const;
    void ganharXp(int quantidade);
};

#endif