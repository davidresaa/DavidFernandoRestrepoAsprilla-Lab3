#include <iostream>
#include "problema1.h"
using namespace std;

// Implementación de los métodos de la clase CuentaCorriente
CuentaCorriente::CuentaCorriente() : saldo(0.0) {}

CuentaCorriente::CuentaCorriente(string nombre, string apellidos, string direccion, string telefono, double saldo)
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
    cout << "Nombre: " << nombre << endl;
    cout << "Apellidos: " << apellidos << endl;
    cout << "Dirección: " << direccion << endl;
    cout << "Teléfono: " << telefono << endl;
    cout << "Saldo: " << saldo << endl;
}

bool CuentaCorriente::saldoNegativo() const {
    return saldo < 0;
}

// Función para interactuar con la clase CuentaCorriente
void problema1() {
    int opcion;
    string nombre, apellidos, direccion, telefono;
    double saldoInicial;
    CuentaCorriente cuenta;

    cout << "Seleccione una opción:" << std::endl;
    cout << "1. Ingresar datos de la cuenta" << std::endl;
    cout << "2. Crear cuenta con datos predefinidos" << std::endl;
    cin >> opcion;

    if (opcion == 1) {
        cout << "Ingrese nombre: ";
        cin >> nombre;
        cuenta.setNombre(nombre);

        cout << "Ingrese apellidos: ";
        cin >> apellidos;
        cuenta.setApellidos(apellidos);

        cout << "Ingrese dirección: ";
        cin >> direccion;
        cuenta.setDireccion(direccion);

        cout << "Ingrese teléfono: ";
        cin >> telefono;
        cuenta.setTelefono(telefono);

        cout << "Ingrese saldo inicial: ";
        cin >> saldoInicial;
        cuenta.ingresarDinero(saldoInicial);
    }
    else if (opcion == 2) {
        // Datos predefinidos
        cuenta = CuentaCorriente("John", "Doe", "123 Main St", "555-1234", 1000.0);
    }
    else {
        cout << "Opción inválida." << endl;
        return;
    }

    // Menú de interacción con la cuenta
    do {
        cout << "\nSeleccione una opción:" << endl;
        cout << "1. Consultar cuenta" << endl;
        cout << "2. Editar datos de usuario" << endl;
        cout << "3. Retirar dinero" << endl;
        cout << "4. Ingresar dinero" << endl;
        cout << "5. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                cuenta.consultarCuenta();
                break;
            case 2:
                cout << "Ingrese nombre: ";
                cin >> nombre;
                cuenta.setNombre(nombre);

                cout << "Ingrese apellidos: ";
                cin >> apellidos;
                cuenta.setApellidos(apellidos);

                cout << "Ingrese dirección: ";
                cin >> direccion;
                cuenta.setDireccion(direccion);

                cout << "Ingrese teléfono: ";
                cin >> telefono;
                cuenta.setTelefono(telefono);
                break;
            case 3:
                double cantidadRetiro;
                cout << "Ingrese la cantidad a retirar: ";
                cin >> cantidadRetiro;
                cuenta.retirarDinero(cantidadRetiro);
                break;
            case 4:
                double cantidadIngreso;
                cout << "Ingrese la cantidad a ingresar: ";
                cin >> cantidadIngreso;
                cuenta.ingresarDinero(cantidadIngreso);
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
                break;
        }
    } while (opcion != 5);
}
