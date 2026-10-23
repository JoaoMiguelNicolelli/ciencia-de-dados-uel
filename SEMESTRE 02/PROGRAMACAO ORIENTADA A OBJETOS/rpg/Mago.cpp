#include "Mago.h"
#include <iostream>

using namespace std;

Mago::Mago(const string& nome, int hpMaximo, const Atributos& atributos)
    : Jogador(nome, hpMaximo, atributos) {
}

void Mago::agir(Personagem& alvo) {
    int dano = 4 + getAtributos().modificador(getAtributos().getInteligencia());

    cout << getNome() << " lanca uma bola de fogo em " << alvo.getNome()
         << " e causa " << dano << " de dano" << endl;

    alvo.receberDano(dano);
}