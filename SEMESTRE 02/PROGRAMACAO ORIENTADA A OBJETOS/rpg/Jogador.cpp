#include "Jogador.h"
#include <iostream>

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

bool Jogador::equipar(const Equipamento& equipamento) {
    if (!podeUsar(equipamento)) {
        cout << getNome() << " (" << getClasse() << ") nao pode usar "
             << equipamento.getNome() << endl;
        return false;
    }

    equipamentos.push_back(equipamento);

    cout << getNome() << " equipou " << equipamento.getNome()
         << " (+" << equipamento.getBonusDano() << " de dano)" << endl;

    return true;
}

int Jogador::getBonusEquipamentos() const {
    int total = 0;

    for (size_t i = 0; i < equipamentos.size(); i++) {
        total = total + equipamentos[i].getBonusDano();
    }

    return total;
}

void Jogador::mostrarEquipamentos() const {
    cout << getNome() << " tem: ";

    if (equipamentos.empty()) {
        cout << "nenhum equipamento";
    }

    for (size_t i = 0; i < equipamentos.size(); i++) {
        cout << equipamentos[i].getNome();

        if (i + 1 < equipamentos.size()) {
            cout << ", ";
        }
    }

    cout << endl;
}