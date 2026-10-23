#include "Monstro.h"

using namespace std;

Monstro::Monstro(const string& nome, int hpMaximo, const Atributos& atributos, int xpRecompensa)
    : Personagem(nome, hpMaximo, atributos),
      xpRecompensa(xpRecompensa) {
}

int Monstro::getXpRecompensa() const {
    return xpRecompensa;
}