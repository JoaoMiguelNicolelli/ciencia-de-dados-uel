#include "Equipamento.h"

using namespace std;

Equipamento::Equipamento(const string& nome, TipoEquipamento tipo, int bonusDano)
    : nome(nome),
      tipo(tipo),
      bonusDano(bonusDano) {
}

const string& Equipamento::getNome() const {
    return nome;
}

TipoEquipamento Equipamento::getTipo() const {
    return tipo;
}

int Equipamento::getBonusDano() const {
    return bonusDano;
}