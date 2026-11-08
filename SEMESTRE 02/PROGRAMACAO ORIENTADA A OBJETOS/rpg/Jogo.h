#ifndef JOGO_H
#define JOGO_H

#include <vector>
#include "CriadorDePersonagem.h"
#include "Jogador.h"
#include "Monstro.h"

class Jogo {
private:
    CriadorDePersonagem criador;
    std::vector<Jogador*> jogadores;
    std::vector<Monstro*> monstros;
    int quantidade;
    int turno;

    void prepararPersonagens();
    void mostrarPersonagens() const;
    bool jogadoresAtacam();
    bool monstrosAtacam();
    void chamarAssistente();

public:
    Jogo(int quantidade);
    ~Jogo();

    void executar();
};

#endif