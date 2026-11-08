#include "Dado.h"
#include "Jogo.h"

int main() {
    Dado::iniciar();

    Jogo jogo(3);
    jogo.executar();

    return 0;
}