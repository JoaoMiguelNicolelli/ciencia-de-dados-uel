#include "Arqueiro.h"
#include <iostream>

using namespace std;

Arqueiro::Arqueiro(const string& nome, int hpMaximo, const Atributos& atributosBase, const Raca& raca)
    : Jogador(nome, hpMaximo, atributosBase, raca) {
}

void Arqueiro::agir(Personagem& alvo) {
    int dano = 4 + getAtributos().modificador(getAtributos().getDestreza());
    dano = dano + getBonusEquipamentos();

    cout << getNome() << " dispara uma flecha em " << alvo.getNome()
         << " e causa " << dano << " de dano" << endl;

    alvo.receberDano(dano);
}

string Arqueiro::getClasse() const {
    return "Arqueiro";
}

bool Arqueiro::podeUsar(const Equipamento& equipamento) const {
    if (equipamento.getTipo() == TipoEquipamento::Arco) {
        return true;
    }
    if (equipamento.getTipo() == TipoEquipamento::Amuleto) {
        return true;
    }
    return false;
}