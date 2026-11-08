#include "Guerreiro.h"
#include <iostream>

using namespace std;

Guerreiro::Guerreiro(const string& nome, int hpMaximo, const Atributos& atributosBase, const Raca& raca)
    : Jogador(nome, hpMaximo, atributosBase, raca) {
}

void Guerreiro::agir(Personagem& alvo) {
    int dano = 5 + getAtributos().modificador(getAtributos().getForca());
    dano = dano + getBonusEquipamentos();

    cout << getNome() << " golpeia " << alvo.getNome()
         << " com a espada e causa " << dano << " de dano" << endl;

    alvo.receberDano(dano);
}

string Guerreiro::getClasse() const {
    return "Guerreiro";
}

bool Guerreiro::podeUsar(const Equipamento& equipamento) const {
    if (equipamento.getTipo() == TipoEquipamento::ArmaPesada) {
        return true;
    }
    if (equipamento.getTipo() == TipoEquipamento::Amuleto) {
        return true;
    }
    return false;
}