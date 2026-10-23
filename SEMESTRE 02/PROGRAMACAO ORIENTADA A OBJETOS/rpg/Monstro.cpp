#include "Monstro.h"
#include <iostream>

using namespace std;

Monstro::Monstro(const string& nome, int hpMaximo, const Atributos& atributos, int xpRecompensa)
    : Personagem(nome, hpMaximo, atributos),
      xpRecompensa(xpRecompensa) {
}

int Monstro::getXpRecompensa() const {
    return xpRecompensa;
}

void Monstro::agir(Personagem& alvo) {
    int dano = 3 + getAtributos().modificador(getAtributos().getForca());

    if (dano < 1) {
        dano = 1;
    }

    cout << getNome() << " ataca " << alvo.getNome()
         << " e causa " << dano << " de dano" << endl;

    alvo.receberDano(dano);
}