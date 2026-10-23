#include <iostream>
#include <vector>
#include "Guerreiro.h"
#include "Mago.h"
#include "Monstro.h"

using namespace std;

int main() {
    vector<Personagem*> personagens;

    personagens.push_back(new Guerreiro("Aragorn", 30, Atributos(16, 12, 14, 10, 8, 11)));
    personagens.push_back(new Mago("Gandalf", 20, Atributos(8, 12, 10, 14, 17, 12)));
    personagens.push_back(new Monstro("Goblin", 10, Atributos(8, 14, 10, 6, 6, 4), 50));

    Monstro boneco("Boneco de treino", 100, Atributos(10, 10, 10, 10, 10, 10), 0);

    for (size_t i = 0; i < personagens.size(); i++) {
        personagens[i]->agir(boneco);
    }

    boneco.mostrarStatus();

    for (size_t i = 0; i < personagens.size(); i++) {
        delete personagens[i];
    }

    return 0;
}