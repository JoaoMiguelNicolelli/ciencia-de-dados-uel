#ifndef ASSISTENTE_H
#define ASSISTENTE_H

#include <string>
#include "Personagem.h"

class Assistente : public Personagem {
public:
    Assistente(const std::string& nome);

    void chegar(Personagem& aliado);
    void agir(Personagem& alvo) override;
};

#endif