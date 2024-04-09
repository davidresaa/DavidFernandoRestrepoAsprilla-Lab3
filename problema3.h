#ifndef PROBLEMA3_H
#define PROBLEMA3_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BuscadorTexto {
public:
    BuscadorTexto();
    void buscarCaracter(const string& rutaArchivo, char caracter, ofstream& resultado);
    void buscarSecuencia(const string& rutaArchivo, const string& secuencia, ofstream& resultado);
};

void problema3();

#endif
