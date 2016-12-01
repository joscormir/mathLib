#include <iostream>
#include "Matrix.h"

using namespace std;

class Number{

	virtual void getNumber() = 0;
	protected:
		int n;
};

class Natural : Number{
	public:
		void getNumber(){
			std::cout << "Soy un numero natural: " << num << std::endl;
		};

	private:
		unsigned int num;
};

class Complex : Number{
	public:
		Complex():real(0),img(0){};
		Complex(double _real, double _img): real(_real),img(_img){};

		~Complex(){
			delete ptr;
		};
		void getNumber(){
			std::cout << "Soy un complejo con aprte real:";
		};
	private:
		Complex* ptr = new Complex();
		double real;
		double img;
};
int main() {
	
	Matrix<float> mat(3,3);
	cout << mat(2, 1) << endl;
	Complex numComp1;
	Complex numcomp2(1.2,2.3);
	return 0;
}

void birthDate(int _day, int _month, int _year) {
	std::cout << "Your birthday is: " << _day << "/" << _month << "/" << _year << std::endl;
}