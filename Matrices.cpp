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

}