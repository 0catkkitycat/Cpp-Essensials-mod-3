#include <iostream>
using namespace std;
class LimitException : public exception {
public:
    const char* what() const throw() {
        return "Value could exceed limit.";
    }
};
class BoundedValue {
private:
    int value;
    int minLimit;
    int maxLimit;
public:
    BoundedValue(int val, int minL, int maxL) {
        value = val;
        minLimit = minL;
        maxLimit = maxL;
    }
    void add(int amount) {
        if (value + amount > maxLimit || value + amount < minLimit) {
            throw LimitException();
        }
        value += amount;
    }
    void subtract(int amount) {
        if (value - amount < minLimit || value - amount > maxLimit) {
            throw LimitException();
        }
        value -= amount;
    }
    int getValue() {
        return value;
    }
};
int main(void) {
    int val1, min1, max1;
    int val2, min2, max2;
    int op1, op2;
    cin >> val1 >> min1 >> max1;
    cin >> val2 >> min2 >> max2;
    cin >> op1;
    cin >> op2;

    BoundedValue obj1(val1, min1, max1);
    BoundedValue obj2(val2, min2, max2);

    try {
        obj1.add(op1);
    }
    catch (LimitException& e) {
        cout << e.what() << endl;
    }
    try {
        obj1.subtract(op2);
    }
    catch (LimitException& e) {
        cout << e.what() << endl;
    }
    try {
        obj2.add(op1);
    }
    catch (LimitException& e) {
        cout << e.what() << endl;
    }

    cout << obj1.getValue() << endl;
    cout << obj2.getValue() << endl;
    return 0;
}