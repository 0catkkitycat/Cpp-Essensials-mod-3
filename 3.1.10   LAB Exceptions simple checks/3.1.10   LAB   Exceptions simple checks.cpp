#include <iostream>

using namespace std;


class MatrixException : public exception {
public:
    const char* what() const throw() {
        return "Matrices don't fit.";
    }
};

class Matrix {
private:
    int rows;
    int cols;
    float data[10][10]; 

public:

    Matrix(int r, int c) {
        rows = r;
        cols = c;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = 0;
            }
        }
    }

    void fill(float value) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = value;
            }
        }
    }


    void addValue(float value) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] += value;
            }
        }
    }


    Matrix addMatrix(Matrix other) {

        if (rows != other.rows || cols != other.cols) {
            throw MatrixException();
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }


    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j];
                if (j < cols - 1) cout << " ";
            }
            cout << endl;
        }
    }
};

int main(void) {
    int r1, c1, r2, c2, r3, c3;

    cin >> r1 >> c1;
    cin >> r2 >> c2;
    cin >> r3 >> c3;


    Matrix m1(r1, c1);
    Matrix m2(r2, c2);
    Matrix m3(r3, c3);


    try {
        Matrix result = m1.addMatrix(m2);
        result.print();
        cout << endl;
    }
    catch (MatrixException& e) {
        cout << e.what() << endl;
    }

    try {
        Matrix result = m1.addMatrix(m3);
        result.print();
        cout << endl;
    }
    catch (MatrixException& e) {
        cout << e.what() << endl;
    }


    try {
        Matrix result = m2.addMatrix(m3);
        result.print();
        cout << endl;
    }
    catch (MatrixException& e) {
        cout << e.what() << endl;
    }

    return 0;
}