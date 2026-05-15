#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    Matrix<int> m(2, 2);

    // Asignar valores
    m.setValue(0, 0, 1);
    m.setValue(0, 1, 2);
    m.setValue(1, 0, 3);
    m.setValue(1, 1, 4);

    cout << "Matriz original:" << endl;
    m.print();

    // Agregar fila
    m.addRow(9);
    cout << "\nDespues de agregar fila:" << endl;
    m.print();

    // Agregar columna
    m.addColumn(7);
    cout << "\nDespues de agregar columna:" << endl;
    m.print();

    // Transponer
    m.transpose();
    cout << "\nDespues de transpose:" << endl;
    m.print();

    // Eliminar fila
    m.removeRow(0);
    cout << "\nDespues de eliminar fila 0:" << endl;
    m.print();

    // Eliminar columna
    m.removeColumn(0);
    cout << "\nDespues de eliminar columna 0:" << endl;
    m.print();

    return 0;
}