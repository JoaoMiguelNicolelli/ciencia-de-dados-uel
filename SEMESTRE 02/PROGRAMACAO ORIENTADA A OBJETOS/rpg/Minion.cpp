#include "Minion.h"

using namespace std;

Minion::Minion(const string& nome, int hpMaximo, const Atributos& atributos, int xpRecompensa)
    : Monstro(nome, hpMaximo, atributos, xpRecompensa) {
}