#ifndef _MATRIX_OP_
#define _MATRIX_OP_
template<typename T>
class Matrix {
	
public:
	
	Matrix(const T& _rows,const T& _columns); //Default fill with zeroes. 
	Matrix(const T& _size); 
	Matrix(const T& _mat);//Copy constructor
	~Matrix();

	//Fill method
	void fill(const T _values[]);

	//Redefine operators to asign operations
	Matrix& operator=	(const Matrix& _equalMat);

	Matrix& operator+	(const Matrix& _addMat);
	Matrix& operator+	(const T& _scalar);	//add scalar

	Matrix& operator-	(const Matrix& _Mat);
	Matrix& operator-	(const T& _scalar);	//subtract by scalar

	Matrix& operator*	(const Matrix& _secondMat);
	Matrix& operator*	(const T& _scalar);	//Multiply by scalar
	
	Matrix& operator/	(const Matrix& _divideMat);
	Matrix& operator/	(const T& _scalar);	//Divide by scalar

	//Particular Matrix operations
	Matrix	transp		(const Matrix& _matToTransp);
	Matrix	inv			(const Matrix& _matToInv);
	int		range		(const Matrix&);

	//Particular matrix
	Matrix ones(const T& _size);
	Matrix ones(const T& _rows, const T& _columns);

	Matrix zero(const T& _rows, const T& _columns);
	Matrix zero(const T& _size);

	Matrix identity(const T& _size);
	
private:
		T rows, columns, size;
		T **ptrMat = nullptr;

};
#endif //_MATRIX_OP_
