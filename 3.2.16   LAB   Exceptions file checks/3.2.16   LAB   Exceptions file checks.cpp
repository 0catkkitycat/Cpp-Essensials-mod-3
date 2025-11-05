#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Matrix2x2 {
private:
    int data[2][2];

public:
    Matrix2x2() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                data[i][j] = 0;
            }
        }
    }

    void setData(int a, int b, int c, int d) {
        data[0][0] = a;
        data[0][1] = b;
        data[1][0] = c;
        data[1][1] = d;
    }

    void loadFromFile(const string& path) {
        ifstream file(path);

        if (!file.is_open()) {
            cout << "File not found at: " << path << endl;
            throw runtime_error("File not found");
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                file >> data[i][j];
            }
        }

        file.close();
    }

    void saveToFile(const string& path) {
        ofstream file(path);

        if (!file.is_open()) {
            cout << "No rights to write to file: " << path << endl;
            throw runtime_error("No write permissions");
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                file << data[i][j];
                if (j < 1) file << " ";
            }
            file << endl;
        }

        file.close();
    }

    void display() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix2x2 matrix;


    try {
        matrix.loadFromFile("nonexistent_file.txt");
    }
    catch (runtime_error& e) {

    }


    try {
        matrix.setData(1, 2, 3, 4);

#ifdef _WIN32
        matrix.saveToFile("C:\\Windows\\System32\\test.txt");
#else
        matrix.saveToFile("/root/test.txt");
#endif
    }
    catch (runtime_error& e) {

    }

    return 0;
}