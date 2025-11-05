#include <iostream>
#include <fstream>
using namespace std;

class Matrix2x2 {
private:
    int data[2][2];

public:
    Matrix2x2() {
        data[0][0] = 0;
        data[0][1] = 0;
        data[1][0] = 0;
        data[1][1] = 0;
    }

    void loadFromFile(string path) {
        ifstream file(path);

        if (!file) {
            cout << "File not found at: " << path << endl;
            throw runtime_error("Error");
        }

        file >> data[0][0] >> data[0][1];
        file >> data[1][0] >> data[1][1];

        file.close();
    }

    void saveToFile(string path) {
        ofstream file(path);

        if (!file) {
            cout << "No rights to write to file: " << path << endl;
            throw runtime_error("Error");
        }

        file << data[0][0] << " " << data[0][1] << endl;
        file << data[1][0] << " " << data[1][1] << endl;

        file.close();
    }
};

int main() {
    Matrix2x2 matrix;


    try {
        matrix.loadFromFile("archivo_que_no_existe.txt");
    }
    catch (exception& e) {
    }


    try {
        matrix.saveToFile("/root/archivo.txt");
    }
    catch (exception& e) {
    }

    return 0;
}