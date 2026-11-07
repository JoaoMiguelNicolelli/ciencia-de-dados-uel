#include "CriadorDePersonagem.h"
#include "Guerreiro.h"
#include "Mago.h"
#include "Arqueiro.h"
#include "Minion.h"
#include "Boss.h"
#include "Dado.h"
#include <iostream>

using namespace std;

CriadorDePersonagem::CriadorDePersonagem()
    : jogadoresCriados(0),
      monstrosCriados(0),
      primeiraClasse(0),
      deslocamentoNomes(Dado::entre(0, 7)) {
}

Raca CriadorDePersonagem::sortearRaca() const {
    int sorteio = Dado::rolar(3);

    if (sorteio == 1) {
        return Raca("Humano", Atributos(1, 1, 1, 1, 1, 1));
    }
    if (sorteio == 2) {
        return Raca("Elfo", Atributos(0, 2, 0, 0, 1, 0));
    }
    return Raca("Anao", Atributos(1, 0, 2, 0, 0, 0));
}

int CriadorDePersonagem::sortearClasse() {
    int classe = Dado::rolar(3);

    if (jogadoresCriados == 0) {
        primeiraClasse = classe;
    }

    if (jogadoresCriados == 1 && classe == primeiraClasse) {
        classe = classe % 3 + 1;
    }

    return classe;
}

Jogador* CriadorDePersonagem::criarJogadorAleatorio() {
    string nomes[] = {"Aragorn", "Gandalf", "Legolas", "Gimli", "Boromir", "Arwen", "Eowyn", "Faramir"};
    string nome = nomes[(deslocamentoNomes + jogadoresCriados) % 8];

    Raca raca = sortearRaca();
    int classe = sortearClasse();
    Jogador* jogador = nullptr;

    if (classe == 1) {
        Atributos base(16, 12, 14, 10, 8, 11);
        int hp = 30 + 2 * base.modificador((base + raca.getBonus()).getConstituicao());
        jogador = new Guerreiro(nome, hp, base, raca);
    } else if (classe == 2) {
        Atributos base(8, 12, 10, 14, 17, 12);
        int hp = 18 + 2 * base.modificador((base + raca.getBonus()).getConstituicao());
        jogador = new Mago(nome, hp, base, raca);
    } else {
        Atributos base(10, 16, 12, 12, 10, 10);
        int hp = 24 + 2 * base.modificador((base + raca.getBonus()).getConstituicao());
        jogador = new Arqueiro(nome, hp, base, raca);
    }

    jogadoresCriados++;

    cout << "Criado: " << jogador->getNome() << " ("
         << jogador->getClasse() << " " << jogador->getRaca().getNome() << ")" << endl;

    return jogador;
}

Monstro* CriadorDePersonagem::criarMonstroAleatorio() {
    monstrosCriados++;

    if (!Boss::existe()) {
        Monstro* boss = Boss::criar("Dragao", 60, Atributos(18, 10, 16, 12, 12, 14), 500);
        cout << "Criado: " << boss->getNome() << " (Boss)" << endl;
        return boss;
    }

    string numero = " " + to_string(monstrosCriados);
    int tipo = Dado::rolar(3);
    Monstro* minion = nullptr;

    if (tipo == 1) {
        minion = new Minion("Goblin" + numero, 10, Atributos(8, 14, 10, 6, 6, 4), 50);
    } else if (tipo == 2) {
        minion = new Minion("Orc" + numero, 16, Atributos(14, 10, 14, 6, 6, 6), 80);
    } else {
        minion = new Minion("Esqueleto" + numero, 12, Atributos(10, 12, 12, 6, 6, 4), 60);
    }

    cout << "Criado: " << minion->getNome() << " (Minion)" << endl;

    return minion;
}