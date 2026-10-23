#include "Arqueiro.h"
#include <iostream>

using namespace std;

Arqueiro::Arqueiro(const string& nome, int hpMaximo, const Atributos& atributos)
    : Jogador(nome, hpMaximo, atributos) {
}

void Arqueiro::agir(Personagem& alvo) {
    int dano = 4 + getAtributos().modificador(getAtributos().getDestreza());

    cout << getNome() << " dispara uma flecha em " << alvo.getNome()
         << " e causa " << dano << " de dano" << endl;

    alvo.receberDano(dano);
}