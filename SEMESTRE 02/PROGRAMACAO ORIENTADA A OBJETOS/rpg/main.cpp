#include <iostream>
#include "Jogador.h"
#include "Monstro.h"

using namespace std;

int main() {
    Atributos atributosAragorn(16, 12, 14, 10, 8, 11);
    Jogador aragorn("Aragorn", 30, atributosAragorn);

    Atributos atributosGoblin(8, 14, 10, 6, 6, 4);
    Monstro goblin("Goblin", 10, atributosGoblin, 50);

    aragorn.mostrarStatus();
    goblin.mostrarStatus();

    goblin.receberDano(15);
    goblin.mostrarStatus();

    if (!goblin.estaVivo()) {
        aragorn.ganharXp(goblin.getXpRecompensa());
    }

    cout << aragorn.getNome() << " agora tem " << aragorn.getXp() << " de XP" << endl;

    return 0;
}