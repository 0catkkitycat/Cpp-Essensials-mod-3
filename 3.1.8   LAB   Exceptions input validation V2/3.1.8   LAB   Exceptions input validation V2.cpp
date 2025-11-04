#include <iostream>

using namespace std;
const int DivideByZero = 111;
using namespace std;
float internaldiv(float arg1, float arg2)
{
	if (0 == arg2)
		throw DivideByZero;
	return arg1 / arg2;
}

float div(float arg1, float arg2) {
	if (arg2 == 0) 
	{
		throw DivideByZero;
	}
	return internaldiv(arg1, arg2);
}

int main(void) {
	float r, a, b;
	while (cin >> a) {
		cin >> b;

		try {
			r = div(a, b);
			cout << r << endl;
		}
		catch (int e) {
			cout << "Are you kidding me?" << endl;
			cout << "Your input is not valid. You can't divide by zero." << endl;
		}
	}
	return 0;
}