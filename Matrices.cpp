#include <iostream>
#include "Matrix.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int filas, columnas;
    cout << "Ingrese cantidad de filas: ";
    cin >> filas;

    cout << "Ingrese cantidad de columnas: ";
    cin >> columnas;

    Matrix<int> matriz(filas, columnas);
    return 0;
    
    rand(time(0));

    int opcion = -1;

    while (opcion != 0) {
        matriz->print();

        cout << "\nMenu:\n";
        cout << "1. getValue\n";
        cout << "2. setValue\n";
        cout << "3. getRows\n";
        cout << "4. getColumns\n";
        cout << "5. setAll\n";
        cout << "6. transpose\n";
        cout << "7. addRow\n";
        cout << "8. addColumn\n";
        cout << "9. removeRow\n";
        cout << "10. removeColumn\n";
        cout << "11. Cargar numeros aleatorios\n";
        cout << "0. Salir\n";

        cout << "Seleccione una opcion: ";
        cin >> opcion;
}