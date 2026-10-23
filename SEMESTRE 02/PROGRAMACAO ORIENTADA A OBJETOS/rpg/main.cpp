#include <iostream>
#include "Personagem.h"

using namespace std;

int main() {
    Atributos atributosAragorn(16, 12, 14, 10, 8, 11);
    Personagem aragorn("Aragorn", 30, atributosAragorn);

    aragorn.mostrarStatus();

    aragorn.receberDano(12);
    aragorn.mostrarStatus();

    aragorn.curar(50);
    aragorn.mostrarStatus();

    aragorn.receberDano(100);
    aragorn.mostrarStatus();
    cout << "Esta vivo? " << aragorn.estaVivo() << endl;

    return 0;
}