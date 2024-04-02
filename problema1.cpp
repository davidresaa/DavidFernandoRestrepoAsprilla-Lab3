#include <iostream>
#include "problema1.h"

// Implementación de los métodos de la clase CuentaCorriente
CuentaCorriente::CuentaCorriente() : saldo(0.0) {}

CuentaCorriente::CuentaCorriente(std::string nombre, std::string apellidos, std::string direccion, std::string telefono, double saldo)
    : nombre(nombre), apellidos(apellidos), direccion(direccion), telefono(telefono), saldo(saldo) {}

void CuentaCorriente::setNombre(std::string nombre) {
    this->nombre = nombre;
}

std::string CuentaCorriente::getNombre() const {
    return nombre;
}

void CuentaCorriente::setApellidos(std::string apellidos) {
    this->apellidos = apellidos;
}

std::string CuentaCorriente::getApellidos() const {
    return apellidos;
}

void CuentaCorriente::setDireccion(std::string direccion) {
    this->direccion = direccion;
}

std::string CuentaCorriente::getDireccion() const {
    return direccion;
}

void CuentaCorriente::setTelefono(std::string telefono) {
    this->telefono = telefono;
}

std::string CuentaCorriente::getTelefono() const {
    return telefono;
}

double CuentaCorriente::getSaldo() const {
    return saldo;
}

void CuentaCorriente::retirarDinero(double cantidad) {
    saldo -= cantidad;
}

void CuentaCorriente::ingresarDinero(double cantidad) {
    saldo += cantidad;
}

void CuentaCorriente::consultarCuenta() const {
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Apellidos: " << apellidos << std::endl;
    std::cout << "Dirección: " << direccion << std::endl;
    std::cout << "Teléfono: " << telefono << std::endl;
    std::cout << "Saldo: " << saldo << std::endl;
}

bool CuentaCorriente::saldoNegativo() const {
    return saldo < 0;
}

// Función para interactuar con la clase CuentaCorriente
void problema1() {
    int opcion;
    std::string nombre, apellidos, direccion, telefono;
    double saldoInicial;
    CuentaCorriente cuenta;

    std::cout << "Seleccione una opción:" << std::endl;
    std::cout << "1. Ingresar datos de la cuenta" << std::endl;
    std::cout << "2. Crear cuenta con datos predefinidos" << std::endl;
    std::cin >> opcion;

    if (opcion == 1) {
        std::cout << "Ingrese nombre: ";
        std::cin >> nombre;
        cuenta.setNombre(nombre);

        std::cout << "Ingrese apellidos: ";
        std::cin >> apellidos;
        cuenta.setApellidos(apellidos);

        std::cout << "Ingrese dirección: ";
        std::cin >> direccion;
        cuenta.setDireccion(direccion);

        std::cout << "Ingrese teléfono: ";
        std::cin >> telefono;
        cuenta.setTelefono(telefono);

        std::cout << "Ingrese saldo inicial: ";
        std::cin >> saldoInicial;
        cuenta.ingresarDinero(saldoInicial);
    }
    else if (opcion == 2) {
        // Datos predefinidos
        cuenta = CuentaCorriente("John", "Doe", "123 Main St", "555-1234", 1000.0);
    }
    else {
        std::cout << "Opción inválida." << std::endl;
        return;
    }

    // Menú de interacción con la cuenta
    do {
        std::cout << "\nSeleccione una opción:" << std::endl;
        std::cout << "1. Consultar cuenta" << std::endl;
        std::cout << "2. Editar datos de usuario" << std::endl;
        std::cout << "3. Retirar dinero" << std::endl;
        std::cout << "4. Ingresar dinero" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                cuenta.consultarCuenta();
                break;
            case 2:
                std::cout << "Ingrese nombre: ";
                std::cin >> nombre;
                cuenta.setNombre(nombre);

                std::cout << "Ingrese apellidos: ";
                std::cin >> apellidos;
                cuenta.setApellidos(apellidos);

                std::cout << "Ingrese dirección: ";
                std::cin >> direccion;
                cuenta.setDireccion(direccion);

                std::cout << "Ingrese teléfono: ";
                std::cin >> telefono;
                cuenta.setTelefono(telefono);
                break;
            case 3:
                double cantidadRetiro;
                std::cout << "Ingrese la cantidad a retirar: ";
                std::cin >> cantidadRetiro;
                cuenta.retirarDinero(cantidadRetiro);
                break;
            case 4:
                double cantidadIngreso;
                std::cout << "Ingrese la cantidad a ingresar: ";
                std::cin >> cantidadIngreso;
                cuenta.ingresarDinero(cantidadIngreso);
                break;
            case 5:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opción inválida." << std::endl;
                break;
        }
    } while (opcion != 5);
}
