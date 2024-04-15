// problema4.h

#ifndef PROBLEMA4_H
#define PROBLEMA4_H

#include <string>
#include <unordered_map>

class Codificador {
private:
    std::unordered_map<char, char> reglas;

public:
    void cargarReglas(const std::string& archivoReglas);
    std::string codificar(const std::string& mensaje);
    std::string decodificar(const std::string& mensaje);

    void problema4();
};

#endif // PROBLEMA4_H
