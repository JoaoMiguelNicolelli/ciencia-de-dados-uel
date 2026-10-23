#include "Jogador.h"

using namespace std;

Jogador::Jogador(const string& nome, int hpMaximo, const Atributos& atributos)
    : Personagem(nome, hpMaximo, atributos),
      xp(0) {
}

int Jogador::getXp() const {
    return xp;
}

void Jogador::ganharXp(int quantidade) {
    if (quantidade < 0) {
        return;
    }

    xp = xp + quantidade;
}