#include "Boss.h"
#include <iostream>

using namespace std;

int Boss::quantidade = 0;

Boss::Boss(const string& nome, int hpMaximo, const Atributos& atributos, int xpRecompensa)
    : Monstro(nome, hpMaximo, atributos, xpRecompensa),
      contadorAcoes(0) {
    quantidade++;
}

Boss::~Boss() {
    quantidade--;
}

Boss* Boss::criar(const string& nome, int hpMaximo, const Atributos& atributos, int xpRecompensa) {
    if (quantidade > 0) {
        cout << "Ja existe um Boss em jogo. " << nome << " nao foi criado." << endl;
        return nullptr;
    }

    return new Boss(nome, hpMaximo, atributos, xpRecompensa);
}

void Boss::agir(Personagem& alvo) {
    contadorAcoes++;

    if (contadorAcoes % 3 == 0) {
        int dano = 10 + getAtributos().modificador(getAtributos().getForca());

        cout << getNome() << " usa GOLPE DEVASTADOR em " << alvo.getNome()
             << " e causa " << dano << " de dano!" << endl;

        alvo.receberDano(dano);
    } else {
        Monstro::agir(alvo);
    }
}