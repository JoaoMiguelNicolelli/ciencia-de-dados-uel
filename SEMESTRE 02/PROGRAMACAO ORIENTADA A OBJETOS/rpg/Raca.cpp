#include "Raca.h"

using namespace std;

Raca::Raca(const string& nome, const Atributos& bonus)
    : nome(nome),
      bonus(bonus) {
}

const string& Raca::getNome() const {
    return nome;
}

const Atributos& Raca::getBonus() const {
    return bonus;
}