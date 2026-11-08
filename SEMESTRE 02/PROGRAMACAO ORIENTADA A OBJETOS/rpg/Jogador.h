#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include <vector>
#include "Personagem.h"
#include "Raca.h"
#include "Equipamento.h"

class Jogador : public Personagem {
private:
    int xp;
    Raca raca;
    std::vector<Equipamento> equipamentos;

public:
    Jogador(const std::string& nome, int hpMaximo, const Atributos& atributosBase, const Raca& raca);

    int getXp() const;
    void ganharXp(int quantidade);
    const Raca& getRaca() const;

    bool equipar(const Equipamento& equipamento);
    int getBonusEquipamentos() const;
    void mostrarEquipamentos() const;

    virtual std::string getClasse() const = 0;
    virtual bool podeUsar(const Equipamento& equipamento) const = 0;
};

#endif