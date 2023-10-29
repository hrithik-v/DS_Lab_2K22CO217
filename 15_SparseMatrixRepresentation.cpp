// 15. Sparse Matrix Representation

#include <iostream>
#include <vector>

using namespace std;

// Structure to represent a triplet (row, column, value)
struct Triplet {
    int row, col, value;
    Triplet(int r, int c, int v) : row(r), col(c), value(v) {}
};

// Function to display a sparse matrix
void displaySparseMatrix(const vector<Triplet>& sparseMatrix, int numRows, int numCols) {
    int currentIndex = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (currentIndex < sparseMatrix.size() && sparseMatrix[currentIndex].row == i && sparseMatrix[currentIndex].col == j) {
                cout << sparseMatrix[currentIndex].value << " ";
                currentIndex++;
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

// Function to add two sparse matrices
vector<Triplet> addSparseMatrices(const vector<Triplet>& matrixA, const vector<Triplet>& matrixB, int numRows, int numCols) {
    vector<Triplet> result;
    int indexA = 0;
    int indexB = 0;

    while (indexA < matrixA.size() && indexB < matrixB.size()) {
        if (matrixA[indexA].row == matrixB[indexB].row && matrixA[indexA].col == matrixB[indexB].col) {
            int sum = matrixA[indexA].value + matrixB[indexB].value;
            if (sum != 0) {
                result.push_back(Triplet(matrixA[indexA].row, matrixA[indexA].col, sum));
            }
            indexA++;
            indexB++;
        } else if (matrixA[indexA].row < matrixB[indexB].row || (matrixA[indexA].row == matrixB[indexB].row && matrixA[indexA].col < matrixB[indexB].col)) {
            result.push_back(matrixA[indexA]);
            indexA++;
        } else {
            result.push_back(matrixB[indexB]);
            indexB++;
        }
    }

    // Copy any remaining elements from matrixA and matrixB
    while (indexA < matrixA.size()) {
        result.push_back(matrixA[indexA]);
        indexA++;
    }

    while (indexB < matrixB.size()) {
        result.push_back(matrixB[indexB]);
        indexB++;
    }

    return result;
}

int main() {
    // Example sparse matrices
    vector<Triplet> matrixA = {Triplet(0, 0, 1), Triplet(1, 1, 2)};
    vector<Triplet> matrixB = {Triplet(0, 0, 3), Triplet(0, 1, 4), Triplet(1, 1, 5)};

    int numRows = 2;
    int numCols = 2;

    cout << "Sparse Matrix A:" << endl;
    displaySparseMatrix(matrixA, numRows, numCols);

    cout << "Sparse Matrix B:" << endl;
    displaySparseMatrix(matrixB, numRows, numCols);

    vector<Triplet> result = addSparseMatrices(matrixA, matrixB, numRows, numCols);

    cout << "Resultant Sparse Matrix (A + B):" << endl;
    displaySparseMatrix(result, numRows, numCols);

    return 0;
}
