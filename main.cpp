#include <iostream>
using namespace std;
// Prototipos de funciones para cada problema
void problema1();
void problema2();
void problema3();
void problema4();
void problema5();

int main() {
    int opcion;

    cout << "Seleccione un problema para ejecutar:" << std::endl;
    cout << "1. Problema 1" << std::endl;
    cout << "2. Problema 2" << std::endl;
    cout << "3. Problema 3" << std::endl;
    cout << "4. Problema 4" << std::endl;
    cout << "5. Problema 5" << std::endl;

    cin >> opcion;

    switch(opcion) {
        case 1:
            problema1();
            break;
        case 2:
            problema2();
            break;
      //  case 3:
         //   problema3();
         //   break;
      //  case 4:
          //  problema4();
          //  break;
     //   case 5:
          //  problema5();
          //  break;
        default:
            std::cout << "Opción inválida. Por favor seleccione un número del 1 al 5." << std::endl;
            break;
    }

    return 0;
}
