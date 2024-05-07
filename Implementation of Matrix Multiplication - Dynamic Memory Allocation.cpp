#include <iostream>

using namespace std;

// Function to dynamically allocate memory for a matrix
int** allocateMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

// Function to deallocate memory for a matrix
void deallocateMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Function to multiply two matrices
int** multiplyMatrices(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2) {
    if (cols1 != rows2) {
        cout << "Error: Matrix dimensions are not compatible for multiplication.";
        return nullptr;
    }

    int** result = allocateMatrix(rows1, cols2);

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

// Function to display a matrix
void displayMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    cout << "Enter the number of rows and columns for first matrix: ";
    cin >> rows1 >> cols1;

    cout << "Enter the number of rows and columns for second matrix: ";
    cin >> rows2 >> cols2;

    if (cols1 != rows2) {
        cout << "Error: Matrix dimensions are not compatible for multiplication.";
        return 1;
    }

    int** matrix1 = allocateMatrix(rows1, cols1);
    int** matrix2 = allocateMatrix(rows2, cols2);

    cout << "Enter elements of first matrix:" << endl;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            cin >> matrix1[i][j];
        }
    }

    cout << "Enter elements of second matrix:" << endl;
    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < cols2; ++j) {
            cin >> matrix2[i][j];
        }
    }

    int** result = multiplyMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2);

    if (result) {
        cout << "Resultant Matrix:" << endl;
        displayMatrix(result, rows1, cols2);
        deallocateMatrix(result, rows1);
    }

    deallocateMatrix(matrix1, rows1);
    deallocateMatrix(matrix2, rows2);

    return 0;
}
