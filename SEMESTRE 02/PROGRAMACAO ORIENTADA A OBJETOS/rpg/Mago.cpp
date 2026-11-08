#include "Mago.h"
#include <iostream>

using namespace std;

Mago::Mago(const string& nome, int hpMaximo, const Atributos& atributosBase, const Raca& raca)
    : Jogador(nome, hpMaximo, atributosBase, raca) {
}

void Mago::agir(Personagem& alvo) {
    int dano = 4 + getAtributos().modificador(getAtributos().getInteligencia());
    dano = dano + getBonusEquipamentos();

    cout << getNome() << " lanca uma bola de fogo em " << alvo.getNome()
         << " e causa " << dano << " de dano" << endl;

    alvo.receberDano(dano);
}

string Mago::getClasse() const {
    return "Mago";
}

bool Mago::podeUsar(const Equipamento& equipamento) const {
    if (equipamento.getTipo() == TipoEquipamento::Cajado) {
        return true;
    }
    if (equipamento.getTipo() == TipoEquipamento::Amuleto) {
        return true;
    }
    return false;
}