#include <iostream>

using namespace std;

class NegativeAreaException : public exception {
public:
    const char* what() const throw() {
        return "Your input is not valid. The area can't be negative.";
    }
};


float square_area(float a) {
    if (a <= 0) {
        throw NegativeAreaException();
    }
    return a * a;
}


float rectangle_area(float a, float b) {
    if (a <= 0 || b <= 0) {
        throw NegativeAreaException();
    }
    return a * b;
}

int main(void) {
    float a, b, r;
    cin >> a;
    cin >> b;
    try
    {
        float rsquare = square_area(a);
        float rrectangle = rectangle_area(a, b);
        cout << rsquare << endl << rrectangle << endl;
    }
    catch (NegativeAreaException& e) {
        cout << e.what() << endl;
    }
    return 0;
}