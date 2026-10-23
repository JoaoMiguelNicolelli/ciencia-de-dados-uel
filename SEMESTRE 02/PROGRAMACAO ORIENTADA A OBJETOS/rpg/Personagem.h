#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <string>
#include <iostream>
#include "Atributos.h"

class Personagem {
private:
    std::string nome;
    int hpMaximo;
    int hpAtual;
    Atributos atributos;

public:
    Personagem(const std::string& nome, int hpMaximo, const Atributos& atributos);
    virtual ~Personagem();

    const std::string& getNome() const;
    int getHpMaximo() const;
    int getHpAtual() const;
    const Atributos& getAtributos() const;

    bool estaVivo() const;
    void receberDano(int dano);
    void curar(int quantidade);
    void mostrarStatus() const;

    virtual void agir(Personagem& alvo) = 0;
};

std::ostream& operator<<(std::ostream& saida, const Personagem& personagem);

#endif