#ifndef CRIADORDEPERSONAGEM_H
#define CRIADORDEPERSONAGEM_H

#include "Jogador.h"
#include "Monstro.h"
#include "Raca.h"
#include "Equipamento.h"

class CriadorDePersonagem {
private:
    int jogadoresCriados;
    int monstrosCriados;
    int primeiraClasse;

    Raca sortearRaca() const;
    int sortearClasse();

public:
    CriadorDePersonagem();

    Jogador* criarJogadorAleatorio();
    Monstro* criarMonstroAleatorio();
    Equipamento sortearEquipamento() const;
};

#endif