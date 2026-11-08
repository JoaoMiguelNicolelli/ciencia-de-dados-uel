#ifndef GUERREIRO_H
#define GUERREIRO_H

#include <string>
#include "Jogador.h"

class Guerreiro : public Jogador {
public:
    Guerreiro(const std::string& nome, int hpMaximo, const Atributos& atributosBase, const Raca& raca);

    void agir(Personagem& alvo) override;
    std::string getClasse() const override;
    bool podeUsar(const Equipamento& equipamento) const override;
};

#endif