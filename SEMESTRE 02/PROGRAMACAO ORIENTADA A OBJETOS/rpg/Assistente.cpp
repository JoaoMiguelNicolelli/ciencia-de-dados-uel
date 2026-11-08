#include "Assistente.h"
#include "Dado.h"
#include <iostream>

using namespace std;

Assistente::Assistente(const string& nome)
    : Personagem(nome, 10, Atributos(10, 10, 10, 14, 10, 12)) {
}

void Assistente::chegar(Personagem& aliado) {
    cout << getNome() << " chega e usa Toque Curativo em " << aliado.getNome()
         << " (+8 HP)" << endl;

    aliado.curar(8);
}

void Assistente::agir(Personagem& alvo) {
    int sorteio = Dado::rolar(2);

    if (sorteio == 1) {
        cout << getNome() << " usa Bencao em " << alvo.getNome() << " (+5 HP)" << endl;
        alvo.curar(5);
    } else {
        cout << getNome() << " usa Prece Maior em " << alvo.getNome() << " (+10 HP)" << endl;
        alvo.curar(10);
    }
}