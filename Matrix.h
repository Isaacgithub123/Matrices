#include <iostream>
#include <stdexcept>

using namespace std;

template <class E>
class Matrix {
private:
    int rows;
    int cols;
    E** matrix;

public:

    // Constructor
    Matrix(int rows, int cols) {
        if (rows <= 0 || cols <= 0)
            throw runtime_error("Las dimensiones deben ser positivas.");
        this->rows = rows;
        this->cols = cols;
        matrix = new E * [rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new E[cols];
        }
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    // getValue
    E getValue(int row, int col) {
        if (row < 0 || row >= rows || col < 0 || col >= cols)
            throw runtime_error("Índices inválidos.");

        return matrix[row][col];
    }

    // setValue
    void setValue(int row, int col, E value) {
        if (row < 0 || row >= rows || col < 0 || col >= cols)
            throw runtime_error("Índices inválidos.");

        matrix[row][col] = value;
    }

    // getRows
    int getRows() {
        return rows;
    }

    // getColumns
    int getColumns() {
        return cols;
    }

    // setAll
    void setAll(E value) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = value;
            }
        }
    }

    // transpose
    void transpose() {
        E** newMatrix = new E * [cols];
        for (int i = 0; i < cols; i++) {
            newMatrix[i] = new E[rows];
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                newMatrix[j][i] = matrix[i][j];
            }
        }
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;

        int temp = rows;
        rows = cols;
        cols = temp;

        matrix = newMatrix;
    }

    // addRow
    void addRow(E value) {
        E** newMatrix = new E * [rows + 1];
        for (int i = 0; i < rows; i++) {
            newMatrix[i] = new E[cols];
            for (int j = 0; j < cols; j++) {
                newMatrix[i][j] = matrix[i][j];
            }
        }
        newMatrix[rows] = new E[cols];
        for (int j = 0; j < cols; j++) {
            newMatrix[rows][j] = value;
        }
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
        matrix = newMatrix;
        rows++;
    }

    // addColumn
    void addColumn(E value) {
        transpose();
        addRow(value);
        transpose();
    }

    // removeRow
    void removeRow(int row) {
        if (row < 0 || row >= rows)
            throw runtime_error("Fila inválida.");
        E** newMatrix = new E * [rows - 1];
        int newRow = 0;
        for (int i = 0; i < rows; i++) {
            if (i == row) continue;
            newMatrix[newRow] = new E[cols];
            for (int j = 0; j < cols; j++) {
                newMatrix[newRow][j] = matrix[i][j];
            }
            newRow++;
        }
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
        matrix = newMatrix;
        rows--;
    }

    void removeColumn(int col) {
        if (col < 0 || col >= cols)
            throw runtime_error("Columna inválida.");

        transpose();
        removeRow(col);
        transpose();
    }

    // print
    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }
    }
};