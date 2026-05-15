#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    int filas, columnas;

    cout << "Ingrese cantidad de filas: ";
    cin >> filas;

    cout << "Ingrese cantidad de columnas: ";
    cin >> columnas;

    Matrix<int> matriz(filas, columnas);