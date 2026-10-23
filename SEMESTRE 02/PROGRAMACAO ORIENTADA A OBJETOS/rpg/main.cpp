#include <iostream>
#include <vector>
#include "Guerreiro.h"
#include "Mago.h"
#include "Arqueiro.h"
#include "Minion.h"
#include "Boss.h"

using namespace std;

int main() {
    Atributos baseLegolas(10, 14, 12, 12, 10, 10);
    Atributos bonusElfo(0, 2, 0, 0, 1, 0);

    vector<Personagem*> personagens;

    personagens.push_back(new Guerreiro("Aragorn", 30, Atributos(16, 12, 14, 10, 8, 11)));
    personagens.push_back(new Mago("Gandalf", 20, Atributos(8, 12, 10, 14, 17, 12)));
    personagens.push_back(new Arqueiro("Legolas", 25, baseLegolas + bonusElfo));
    personagens.push_back(new Minion("Goblin", 10, Atributos(8, 14, 10, 6, 6, 4), 50));

    Boss* dragao = Boss::criar("Dragao", 80, Atributos(20, 10, 18, 12, 12, 14), 500);
    if (dragao != nullptr) {
        personagens.push_back(dragao);
    }

    cout << "=== Personagens ===" << endl;
    for (size_t i = 0; i < personagens.size(); i++) {
        cout << *personagens[i] << endl;
    }

    Monstro boneco("Boneco de treino", 100, Atributos(10, 10, 10, 10, 10, 10), 0);

    cout << endl << "=== Ataques ===" << endl;
    for (size_t i = 0; i < personagens.size(); i++) {
        personagens[i]->agir(boneco);
    }

    cout << endl << boneco << endl;

    for (size_t i = 0; i < personagens.size(); i++) {
        delete personagens[i];
    }

    return 0;
}