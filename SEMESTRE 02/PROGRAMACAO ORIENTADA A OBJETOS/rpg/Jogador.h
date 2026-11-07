#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include "Personagem.h"
#include "Raca.h"

class Jogador : public Personagem {
private:
    int xp;
    Raca raca;

public:
    Jogador(const std::string& nome, int hpMaximo, const Atributos& atributosBase, const Raca& raca);

    int getXp() const;
    void ganharXp(int quantidade);
    const Raca& getRaca() const;

    virtual std::string getClasse() const = 0;
};

#endif