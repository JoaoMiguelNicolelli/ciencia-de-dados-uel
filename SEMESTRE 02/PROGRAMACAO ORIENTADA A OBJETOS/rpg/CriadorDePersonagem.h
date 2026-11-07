#ifndef CRIADORDEPERSONAGEM_H
#define CRIADORDEPERSONAGEM_H

#include "Jogador.h"
#include "Monstro.h"
#include "Raca.h"

class CriadorDePersonagem {
private:
    int jogadoresCriados;
    int monstrosCriados;
    int primeiraClasse;
    int deslocamentoNomes;

    Raca sortearRaca() const;
    int sortearClasse();

public:
    CriadorDePersonagem();

    Jogador* criarJogadorAleatorio();
    Monstro* criarMonstroAleatorio();
};

#endif