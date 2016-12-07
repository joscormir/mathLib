#include <iostream>
#include "Matrix.h"

int main() {
	double values[9] = {1,2,3,4,5,6,7,8,9};
	std::cout << sizeof(values)/sizeof(double) <<std::endl;
	std::cout << ((3*3) == (sizeof(values) / sizeof(double))) << std::endl;

	Matrix<double> mat(3, values);
	mat.represent();
	Matrix<double> matSum(3);
	Matrix<double> matS(3);
	matS = mat *4;
	matS.represent();

	Matrix<double> mat1(4);
	mat1.one();

	mat1.represent();
	
	mat1.zero();

	mat1.represent();
	
	Matrix <double> mat2(4, 3);
	//mat2.identity();
	mat2.represent();
	mat1.identity();
	mat1.represent();
	system("PAUSE");
}
