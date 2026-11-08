#include "Jogo.h"
#include "Dado.h"
#include "Assistente.h"
#include <iostream>

using namespace std;

Jogo::Jogo(int quantidade)
    : quantidade(quantidade),
      turno(0) {
}

Jogo::~Jogo() {
    for (size_t i = 0; i < jogadores.size(); i++) {
        delete jogadores[i];
    }
    for (size_t i = 0; i < monstros.size(); i++) {
        delete monstros[i];
    }
}

void Jogo::prepararPersonagens() {
    cout << "=== Criando personagens ===" << endl;

    for (int i = 0; i < quantidade; i++) {
        jogadores.push_back(criador.criarJogadorAleatorio());
    }

    for (int i = 0; i < quantidade; i++) {
        monstros.push_back(criador.criarMonstroAleatorio());
    }
}

void Jogo::mostrarPersonagens() const {
    for (size_t i = 0; i < jogadores.size(); i++) {
        cout << *jogadores[i] << endl;
    }
    for (size_t i = 0; i < monstros.size(); i++) {
        cout << *monstros[i] << endl;
    }
}

bool Jogo::jogadoresAtacam() {
    for (size_t i = 0; i < jogadores.size(); i++) {
        Monstro* alvo = monstros[Dado::rolar(monstros.size()) - 1];

        if (Dado::rolar(20) < 9) {
            cout << jogadores[i]->getNome() << " errou o ataque em " << alvo->getNome() << endl;
            continue;
        }

        jogadores[i]->agir(*alvo);

        if (!alvo->estaVivo()) {
            cout << endl << ">>> " << alvo->getNome() << " foi eliminado por "
                 << jogadores[i]->getNome() << "!" << endl;

            jogadores[i]->ganharXp(alvo->getXpRecompensa());

            vector<Equipamento> loot = alvo->soltarLoot();
            for (size_t j = 0; j < loot.size(); j++) {
                cout << alvo->getNome() << " deixou cair " << loot[j].getNome() << endl;
                jogadores[i]->equipar(loot[j]);
            }

            return true;
        }
    }

    return false;
}

bool Jogo::monstrosAtacam() {
    for (size_t i = 0; i < monstros.size(); i++) {
        Jogador* alvo = jogadores[Dado::rolar(jogadores.size()) - 1];

        if (Dado::rolar(20) < 9) {
            cout << monstros[i]->getNome() << " errou o ataque em " << alvo->getNome() << endl;
            continue;
        }

        monstros[i]->agir(*alvo);

        if (!alvo->estaVivo()) {
            cout << endl << ">>> " << alvo->getNome() << " foi eliminado por "
                 << monstros[i]->getNome() << "!" << endl;
            return true;
        }
    }

    return false;
}

void Jogo::chamarAssistente() {
    Assistente assistente("Clerigo Errante");

    cout << "Um assistente apareceu: " << assistente.getNome() << endl;

    Jogador* primeiro = jogadores[Dado::rolar(jogadores.size()) - 1];
    assistente.chegar(*primeiro);

    Jogador* segundo = jogadores[Dado::rolar(jogadores.size()) - 1];
    assistente.agir(*segundo);

    cout << assistente.getNome() << " vai embora" << endl;
}

void Jogo::executar() {
    prepararPersonagens();

    bool acabou = false;

    while (!acabou) {
        turno++;
        cout << endl << "===== Turno " << turno << " =====" << endl;

        if (turno % 2 == 0) {
            monstros.push_back(criador.criarMonstroAleatorio());
        } else {
            chamarAssistente();
        }

        mostrarPersonagens();
        cout << endl;

        acabou = jogadoresAtacam();

        if (!acabou) {
            acabou = monstrosAtacam();
        }
    }

    cout << endl << "Fim da simulacao no turno " << turno << endl;
}