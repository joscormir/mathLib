#include <iostream>
#include "Matrix.h"

using namespace std;
int main() {
	
	Matrix<float> mat(3,3);
	cout << mat(2, 1) << endl;

	system("PAUSE");
}

void birthDate(int _day, int _month, int _year) {
	std::cout << "Your birthday is: " << _day << "/" << _month << "/" << _year << std::endl;
}