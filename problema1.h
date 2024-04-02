#ifndef PROBLEMA1_H
#define PROBLEMA1_H

#include <string>

class CuentaCorriente {
private:
    std::string nombre;
    std::string apellidos;
    std::string direccion;
    std::string telefono;
    double saldo;

public:
    // Constructores
    CuentaCorriente();
    CuentaCorriente(std::string nombre, std::string apellidos, std::string direccion, std::string telefono, double saldo);

    // Métodos get
    std::string getNombre() const;
    std::string getApellidos() const;
    std::string getDireccion() const;
    std::string getTelefono() const;
    double getSaldo() const;

    // Métodos set para modificar datos del usuario
    void setNombre(std::string nombre);
    void setApellidos(std::string apellidos);
    void setDireccion(std::string direccion);
    void setTelefono(std::string telefono);

    // Métodos para operaciones con el saldo
    void retirarDinero(double cantidad);
    void ingresarDinero(double cantidad);
    void consultarCuenta() const;
    bool saldoNegativo() const;
};

// Prototipo de la función para el problema 1
void problema1();

#endif
