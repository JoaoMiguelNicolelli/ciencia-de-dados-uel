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
      primeiraClasse(0) {
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

    if (jogadoresCriados == 1) {
        while (classe == primeiraClasse) {
            classe = Dado::rolar(3);
        }
    }

    return classe;
}

Jogador* CriadorDePersonagem::criarJogadorAleatorio() {
    string nomes[] = {"Aragorn", "Gandalf", "Legolas", "Gimli", "Boromir", "Arwen", "Eowyn", "Faramir"};
    string nome = nomes[jogadoresCriados % 8];

    Raca raca = sortearRaca();
    int classe = sortearClasse();
    Jogador* jogador = nullptr;
    Equipamento inicial("Nada", TipoEquipamento::Amuleto, 0);

    if (classe == 1) {
        Atributos base(16, 12, 14, 10, 8, 11);
        int hp = 30 + 2 * base.modificador((base + raca.getBonus()).getConstituicao());
        jogador = new Guerreiro(nome, hp, base, raca);
        inicial = Equipamento("Espada Curta", TipoEquipamento::ArmaPesada, 1);
    } else if (classe == 2) {
        Atributos base(8, 12, 10, 14, 17, 12);
        int hp = 18 + 2 * base.modificador((base + raca.getBonus()).getConstituicao());
        jogador = new Mago(nome, hp, base, raca);
        inicial = Equipamento("Varinha", TipoEquipamento::Cajado, 1);
    } else {
        Atributos base(10, 16, 12, 12, 10, 10);
        int hp = 24 + 2 * base.modificador((base + raca.getBonus()).getConstituicao());
        jogador = new Arqueiro(nome, hp, base, raca);
        inicial = Equipamento("Arco Curto", TipoEquipamento::Arco, 1);
    }

    jogadoresCriados++;

    cout << "Criado: " << jogador->getNome() << " ("
         << jogador->getClasse() << " " << jogador->getRaca().getNome() << ")" << endl;

    jogador->equipar(inicial);

    return jogador;
}

Monstro* CriadorDePersonagem::criarMonstroAleatorio() {
    monstrosCriados++;

    if (!Boss::existe()) {
        Monstro* boss = Boss::criar("Dragao", 80, Atributos(18, 10, 16, 12, 12, 14), 500);
        boss->adicionarLoot(Equipamento("Escama de Dragao", TipoEquipamento::Amuleto, 4));
        cout << "Criado: " << boss->getNome() << " (Boss)" << endl;
        return boss;
    }

    string numero = " " + to_string(monstrosCriados);
    int tipo = Dado::rolar(3);
    Monstro* minion = nullptr;

    if (tipo == 1) {
        minion = new Minion("Goblin" + numero, 18, Atributos(8, 14, 10, 6, 6, 4), 50);
    } else if (tipo == 2) {
        minion = new Minion("Orc" + numero, 26, Atributos(14, 10, 14, 6, 6, 6), 80);
    } else {
        minion = new Minion("Esqueleto" + numero, 22, Atributos(10, 12, 12, 6, 6, 4), 60);
    }

    minion->adicionarLoot(sortearEquipamento());

    cout << "Criado: " << minion->getNome() << " (Minion)" << endl;

    return minion;
}

Equipamento CriadorDePersonagem::sortearEquipamento() const {
    int sorteio = Dado::rolar(4);

    if (sorteio == 1) {
        return Equipamento("Machado de Guerra", TipoEquipamento::ArmaPesada, 3);
    }
    if (sorteio == 2) {
        return Equipamento("Cajado Arcano", TipoEquipamento::Cajado, 3);
    }
    if (sorteio == 3) {
        return Equipamento("Arco Longo", TipoEquipamento::Arco, 3);
    }
    return Equipamento("Amuleto da Sorte", TipoEquipamento::Amuleto, 1);
}