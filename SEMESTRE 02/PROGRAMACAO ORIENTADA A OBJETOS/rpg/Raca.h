#ifndef RACA_H
#define RACA_H

#include <string>
#include "Atributos.h"

class Raca {
private:
    std::string nome;
    Atributos bonus;

public:
    Raca(const std::string& nome, const Atributos& bonus);

    const std::string& getNome() const;
    const Atributos& getBonus() const;
};

#endif