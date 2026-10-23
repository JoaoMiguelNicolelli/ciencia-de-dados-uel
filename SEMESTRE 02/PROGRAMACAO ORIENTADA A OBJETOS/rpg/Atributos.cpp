#include "Atributos.h"

Atributos::Atributos(int forca, int destreza, int constituicao,
                     int sabedoria, int inteligencia, int carisma)
    : forca(forca),
      destreza(destreza),
      constituicao(constituicao),
      sabedoria(sabedoria),
      inteligencia(inteligencia),
      carisma(carisma) {
}

int Atributos::getForca() const {
    return forca;
}

int Atributos::getDestreza() const {
    return destreza;
}

int Atributos::getConstituicao() const {
    return constituicao;
}

int Atributos::getSabedoria() const {
    return sabedoria;
}

int Atributos::getInteligencia() const {
    return inteligencia;
}

int Atributos::getCarisma() const {
    return carisma;
}