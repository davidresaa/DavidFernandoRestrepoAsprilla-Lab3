#ifndef PROBLEMA2_H
#define PROBLEMA2_H

#include <string>

class GestorArchivo {
public:
    GestorArchivo(); // Constructor
    void escribirArchivo(const std::string& ruta); // Método para escribir en el archivo
    void leerArchivo(const std::string& ruta); // Método para leer del archivo
};

// Prototipo de la función para el problema 2
void problema2();

#endif
