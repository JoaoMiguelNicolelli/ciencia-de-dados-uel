#ifndef ATRIBUTOS_H
#define ATRIBUTOS_H

class Atributos {
private:
    int forca;
    int destreza;
    int constituicao;
    int sabedoria;
    int inteligencia;
    int carisma;

public:
    Atributos(int forca, int destreza, int constituicao,
              int sabedoria, int inteligencia, int carisma);

    int getForca() const;
    int getDestreza() const;
    int getConstituicao() const;
    int getSabedoria() const;
    int getInteligencia() const;
    int getCarisma() const;
};

#endif