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

    srand(time(0));

    int opcion = -1;

    while (opcion != 0) {
        cout << "\nEstado actual de la matriz:\n";
        matriz.print();

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

        if (opcion == 1) {
            int row, col;
            cin >> row >> col;

            if (row >= 0 && row < matriz.getRows() && col >= 0 && col < matriz.getColumns()) {
                cout << matriz.getValue(row, col) << endl;
            }
            else {
                cout << "No se puede realizar esta operacion." << endl;
            }
        }

        else if (opcion == 2) {
            int row, col, value;
            cin >> row >> col >> value;

            if (row >= 0 && row < matriz.getRows() && col >= 0 && col < matriz.getColumns()) {
                matriz.setValue(row, col, value);
            }
            else {
                cout << "No se puede realizar esta operacion." << endl;
            }
        }

        else if (opcion == 3) {
            cout << matriz.getRows() << endl;
        }

        else if (opcion == 4) {
            cout << matriz.getColumns() << endl;
        }

        else if (opcion == 5) {
            int value;
            cin >> value;
            matriz.setAll(value);
        }

        else if (opcion == 6) {
            matriz.transpose();
        }

        else if (opcion == 7) {
            int value;
            cin >> value;
            matriz.addRow(value);
        }

        else if (opcion == 8) {
            int value;
            cin >> value;
            matriz.addColumn(value);
        }

        else if (opcion == 9) {
            int row;
            cin >> row;

            if (row >= 0 && row < matriz.getRows()) {
                matriz.removeRow(row);
            }
            else {
                cout << "No se puede realizar esta operacion." << endl;
            }
        }

        else if (opcion == 10) {
            int col;
            cin >> col;

            if (col >= 0 && col < matriz.getColumns()) {
                matriz.removeColumn(col);
            }
            else {
                cout << "No se puede realizar esta operacion." << endl;
            }
        }

        else if (opcion == 11) {
            for (int i = 0; i < matriz.getRows(); i++) {
                for (int j = 0; j < matriz.getColumns(); j++) {
                    matriz.setValue(i, j, rand() % 100);
                }
            }
        }

        else if (opcion != 0) {
            cout << "Opcion invalida." << endl;
        }
    }

    return 0;
}