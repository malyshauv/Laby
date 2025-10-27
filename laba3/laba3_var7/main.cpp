#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
void deleteMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
int& getEl(int** matrix, int i, int j) {
    return matrix[i][j];
}
void inputMatrix(int** matrix, int n) {
    cout << "vvedite elementy matritsy " << n << "x" << n << ":" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> getEl(matrix, i, j);
        }
    }
}
void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << getEl(matrix, i, j) << "\t";
        }
        cout << endl;
    }
}
bool isSymetric(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (getEl(matrix, i, j) != getEl(matrix, j, i)) {
                return false;
            }
        }
    }
    return true;
}
vector<int> getAllEl(int** matrix, int n) {
    vector<int> elements;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
                elements.push_back(getEl(matrix, i, j));
        }
    }
    return elements;
}
void perestanovka(int** matrix, int n) {
    vector<int> elements = getAllEl(matrix, n);
    sort(elements.begin(), elements.end(), greater<int>());
    int index = 0;
    for (int i = 0; i < n; i++) {
        getEl(matrix, i, i) = elements[index++];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                getEl(matrix, i, j) = elements[index++];
            }
        }
    }
}
int findRow(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        bool hasPos = false;
        for (int j = 0; j < n; j++) {
            if (getEl(matrix, i, j) > 0) {
                hasPos = true;
                break;
            }
        }
        if (!hasPos) {
            return i + 1;
        }
    }
    return -1;
}
int main() {
    int n;
    cout << "vvedite razmer(n <= 10): ";
    cin >> n;
    if (n <= 0 || n > 10) {
        cout << "error. razmer dolzhen byts v diapazone 1-10" << endl;
        return 1;
    }
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    inputMatrix(matrix, n);
    if (!isSymetric(matrix, n)) {
        cout << "error. matix ne symetrichna" << endl;
        deleteMatrix(matrix, n);
        return 1;
    }
    cout << "\nmatrix:" << endl;
    printMatrix(matrix, n);
    perestanovka(matrix, n);
    cout << "\nnew matrix:" << endl;
    printMatrix(matrix, n);
    int rowNum = findRow(matrix, n);
    if (rowNum != -1) {
        cout << "\npervaya srtoka bez polozhitelnyh elementov: " << rowNum << endl;
    } else {
        cout << "\nvse stroki soderzhat polozhitelnyy element" << endl;
    }
    deleteMatrix(matrix, n);
    return 0;
}
