#ifndef EQUIPAMENTO_H
#define EQUIPAMENTO_H

#include <string>

enum class TipoEquipamento {
    ArmaPesada,
    Cajado,
    Arco,
    Amuleto
};

class Equipamento {
private:
    std::string nome;
    TipoEquipamento tipo;
    int bonusDano;

public:
    Equipamento(const std::string& nome, TipoEquipamento tipo, int bonusDano);

    const std::string& getNome() const;
    TipoEquipamento getTipo() const;
    int getBonusDano() const;
};

#endif