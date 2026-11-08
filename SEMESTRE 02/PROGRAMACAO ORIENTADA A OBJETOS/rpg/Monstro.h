#ifndef MONSTRO_H
#define MONSTRO_H

#include <string>
#include <vector>
#include "Personagem.h"
#include "Equipamento.h"

class Monstro : public Personagem {
private:
    int xpRecompensa;
    std::vector<Equipamento> loot;

public:
    Monstro(const std::string& nome, int hpMaximo, const Atributos& atributos, int xpRecompensa);

    int getXpRecompensa() const;

    void adicionarLoot(const Equipamento& equipamento);
    std::vector<Equipamento> soltarLoot();

    void agir(Personagem& alvo) override;
};

#endif