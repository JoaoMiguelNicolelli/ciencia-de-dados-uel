#include "Jogador.h"

using namespace std;

Jogador::Jogador(const string& nome, int hpMaximo, const Atributos& atributosBase, const Raca& raca)
    : Personagem(nome, hpMaximo, atributosBase + raca.getBonus()),
      xp(0),
      raca(raca) {
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

const Raca& Jogador::getRaca() const {
    return raca;
}