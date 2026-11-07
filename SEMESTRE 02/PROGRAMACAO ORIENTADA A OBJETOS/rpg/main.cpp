#include <iostream>
#include <vector>
#include "CriadorDePersonagem.h"

using namespace std;

int main() {
    CriadorDePersonagem criador;
    vector<Personagem*> personagens;

    int quantidade = 3;

    for (int i = 0; i < quantidade; i++) {
        personagens.push_back(criador.criarJogadorAleatorio());
    }

    for (int i = 0; i < quantidade; i++) {
        personagens.push_back(criador.criarMonstroAleatorio());
    }

    cout << endl << "=== Personagens ===" << endl;
    for (size_t i = 0; i < personagens.size(); i++) {
        cout << *personagens[i] << endl;
    }

    for (size_t i = 0; i < personagens.size(); i++) {
        delete personagens[i];
    }

    return 0;
}