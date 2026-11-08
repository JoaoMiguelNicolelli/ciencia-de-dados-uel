#ifndef MAGO_H
#define MAGO_H

#include <string>
#include "Jogador.h"

class Mago : public Jogador {
public:
    Mago(const std::string& nome, int hpMaximo, const Atributos& atributosBase, const Raca& raca);

    void agir(Personagem& alvo) override;
    std::string getClasse() const override;
    bool podeUsar(const Equipamento& equipamento) const override;
};

#endif