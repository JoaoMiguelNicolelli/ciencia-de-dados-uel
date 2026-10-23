#include "Guerreiro.h"
#include <iostream>

using namespace std;

Guerreiro::Guerreiro(const string& nome, int hpMaximo, const Atributos& atributos)
    : Jogador(nome, hpMaximo, atributos) {
}

void Guerreiro::agir(Personagem& alvo) {
    int dano = 5 + getAtributos().modificador(getAtributos().getForca());

    cout << getNome() << " golpeia " << alvo.getNome()
         << " com a espada e causa " << dano << " de dano" << endl;

    alvo.receberDano(dano);
}