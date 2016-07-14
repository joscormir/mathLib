#include <iostream>
#include "Matrix.h"

using namespace std;
int main() {
	
	Matrix<float> mat(3,3);
	for (auto i = 0; i < 3; ++i) {
		for (auto j = 0; j < 3; ++j) {
			cout << mat.ptrMat[i][j];
			if (j == 2)
				cout << endl;
		}
	}
	system("PAUSE");
}