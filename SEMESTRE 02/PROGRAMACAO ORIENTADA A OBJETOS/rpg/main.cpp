#include <iostream>
#include <vector>
#include "Minion.h"
#include "Boss.h"

using namespace std;

int main() {
    vector<Personagem*> personagens;

    personagens.push_back(new Minion("Goblin", 10, Atributos(8, 14, 10, 6, 6, 4), 50));

    Boss* dragao = Boss::criar("Dragao", 80, Atributos(20, 10, 18, 12, 12, 14), 500);
    if (dragao != nullptr) {
        personagens.push_back(dragao);
    }

    Boss* lich = Boss::criar("Lich", 60, Atributos(10, 10, 12, 16, 18, 10), 400);
    if (lich != nullptr) {
        personagens.push_back(lich);
    }

    Monstro boneco("Boneco de treino", 100, Atributos(10, 10, 10, 10, 10, 10), 0);

    for (int rodada = 1; rodada <= 3; rodada++) {
        cout << "--- Rodada " << rodada << " ---" << endl;

        for (size_t i = 0; i < personagens.size(); i++) {
            personagens[i]->agir(boneco);
        }
    }

    boneco.mostrarStatus();

    for (size_t i = 0; i < personagens.size(); i++) {
        delete personagens[i];
    }

    return 0;
}