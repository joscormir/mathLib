#ifndef _MATRIX_OP_
#define _MATRIX_OP_

template<typename T_>
class Matrix {
	
public:
	
	Matrix(const T_& _rows,const T_& _columns); //Default fill with zeroes. 
	Matrix(const T_& _size); 
	Matrix(const Matrix& _mat);//Copy constructor
	~Matrix();

	//Fill method
	void fill(const T_ _values[]);

	//Redefine operators to asign operations
	Matrix& operator=	(const Matrix& _equalMat);

	Matrix& operator+	(const Matrix& _addMat);
	Matrix& operator+	(const T_& _scalar);	//add scalar

	Matrix& operator-	(const Matrix& _Mat);
	Matrix& operator-	(const T_& _scalar);	//subtract by scalar

	Matrix& operator*	(const Matrix& _secondMat);
	Matrix& operator*	(const T_& _scalar);	//Multiply by scalar
	
	Matrix& operator/	(const Matrix& _divideMat);
	Matrix& operator/	(const T_& _scalar);	//Divide by scalar

	//Particular Matrix operations
	Matrix	transp		(const Matrix& _matToTransp);
	Matrix	inv			(const Matrix& _matToInv);
	int		range		(const Matrix&);

	//Particular matrix
	Matrix ones(const T_& _size);
	Matrix ones(const T_& _rows, const T_& _columns);

	Matrix zero(const T_& _rows, const T_& _columns);
	Matrix zero(const T_& _size);

	Matrix identity(const T_& _size);
	
private:
	T_ rows, columns, size;
	T_ **ptrMat = nullptr;
};

//--------------------------------------------------------------------
//Methods implementation
//--------------------------------------------------------------------
template<typename T_>
Matrix<T_>::Matrix(const T_& _rows, const T_& _columns) : rows(_rows), columns(_columns) {
	ptrMat = new T_*[rows];
	for (auto i = 0; i < rows; ++i) {
		ptrMat[i] = new T_[columns];
	}
	for (auto i = 0; i < rows; ++i) {
		for (auto j = 0; j < columns; ++j) {
			ptrMat[i][j] = 0; //initialized by default with 0s
		}
	}
}

//--------------------------------------------------------------------
template<typename T_>
Matrix<T_>::Matrix(const T_& _size) {
	rows = _size;
	columns = _size;
	ptrMat = new T_*[rows];
	for (auto i = 0; i < rows; ++i) {
		ptrMat[i] = new T_[columns];
	}
}

//--------------------------------------------------------------------
template<typename T_>
Matrix<T_>::~Matrix() {
	for (auto i = 0; i < rows; ++i) {
		delete[] ptrMat[i];
	}
	delete[] ptrMat;
}

//---------------------------------------------------------------------
template<typename T_>
Matrix<T_>::Matrix(const Matrix& _mat) {
	//copy constructor
	ptrMat = new T_*[_mat.rows];
	for (auto i = 0; i < _mat.rows; ++i) {
		ptrMat[i] = new T_[_mat.columns];
	}
	for (auto i = 0; i < _mat.rows; ++i) {
		for (auto j = 0; j < _mat.columns; ++j) {
			ptrMat[i][j] = _mat.ptrMat[i][j];
		}
	}
	rows	= _mat.rows;
	columns = _mat.columns;
}


#endif //_MATRIX_OP_
