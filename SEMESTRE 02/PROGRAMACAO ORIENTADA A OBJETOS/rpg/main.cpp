#include <iostream>
#include "Personagem.h"

using namespace std;

int main() {
    Atributos atributosAragorn(16, 12, 14, 10, 8, 11);
    Personagem aragorn("Aragorn", 30, atributosAragorn);

    aragorn.mostrarStatus();

    cout << "Mod FOR (16): " << atributosAragorn.modificador(atributosAragorn.getForca()) << endl;
    cout << "Mod INT (8): " << atributosAragorn.modificador(atributosAragorn.getInteligencia()) << endl;
    cout << "Mod SAB (10): " << atributosAragorn.modificador(atributosAragorn.getSabedoria()) << endl;

    return 0;
}