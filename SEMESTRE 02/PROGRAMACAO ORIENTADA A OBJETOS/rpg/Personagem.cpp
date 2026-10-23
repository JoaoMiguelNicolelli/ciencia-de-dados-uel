#include "Personagem.h"
#include <iostream>

using namespace std;

Personagem::Personagem(const string& nome, int hpMaximo, const Atributos& atributos)
    : nome(nome),
      hpMaximo(hpMaximo),
      hpAtual(hpMaximo),
      atributos(atributos) {
}

Personagem::~Personagem() {
}

const string& Personagem::getNome() const {
    return nome;
}

int Personagem::getHpMaximo() const {
    return hpMaximo;
}

int Personagem::getHpAtual() const {
    return hpAtual;
}

const Atributos& Personagem::getAtributos() const {
    return atributos;
}

bool Personagem::estaVivo() const {
    return hpAtual > 0;
}

void Personagem::receberDano(int dano) {
    if (dano < 0) {
        return;
    }

    hpAtual = hpAtual - dano;

    if (hpAtual < 0) {
        hpAtual = 0;
    }
}

void Personagem::curar(int quantidade) {
    if (quantidade < 0) {
        return;
    }

    if (!estaVivo()) {
        return;
    }

    hpAtual = hpAtual + quantidade;

    if (hpAtual > hpMaximo) {
        hpAtual = hpMaximo;
    }
}

void Personagem::mostrarStatus() const {
    cout << nome << " | HP: " << hpAtual << "/" << hpMaximo
         << " | FOR " << atributos.getForca()
         << " DES " << atributos.getDestreza()
         << " CON " << atributos.getConstituicao()
         << " SAB " << atributos.getSabedoria()
         << " INT " << atributos.getInteligencia()
         << " CAR " << atributos.getCarisma()
         << endl;
}

ostream& operator<<(ostream& saida, const Personagem& personagem) {
    const Atributos& a = personagem.getAtributos();

    saida << personagem.getNome()
          << " | HP: " << personagem.getHpAtual() << "/" << personagem.getHpMaximo()
          << " | FOR " << a.getForca()
          << " DES " << a.getDestreza()
          << " CON " << a.getConstituicao()
          << " SAB " << a.getSabedoria()
          << " INT " << a.getInteligencia()
          << " CAR " << a.getCarisma();

    return saida;
}