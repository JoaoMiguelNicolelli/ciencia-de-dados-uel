#ifndef ARQUEIRO_H
#define ARQUEIRO_H

#include <string>
#include "Jogador.h"

class Arqueiro : public Jogador {
public:
    Arqueiro(const std::string& nome, int hpMaximo, const Atributos& atributosBase, const Raca& raca);

    void agir(Personagem& alvo) override;
    std::string getClasse() const override;
    bool podeUsar(const Equipamento& equipamento) const override;
};

#endif