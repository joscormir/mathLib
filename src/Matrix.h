#ifndef _MATRIX_OP_
#define _MATRIX_OP_
#include <assert.h>
template<typename T_>
class Matrix {
	
public:
	
	Matrix(const unsigned int& _rows,const unsigned int& _columns); //Default fill with zeroes. 
	Matrix(const unsigned int& _size); 
	Matrix(const Matrix& _mat);//Copy constructor
	~Matrix();

	//Fill method
	void fill(const T_& _values);

	//Redefine operators to asign operations
	T_&		operator()	(const unsigned int& _row, const unsigned int& _column);
	Matrix& operator=	(const Matrix& _equalMat);

	Matrix& operator+	(const Matrix& _addMat);
	Matrix& operator+	(const T_& _scalar);	//add scalar

	Matrix& operator-	(const Matrix& _minusMat);
	Matrix& operator-	(const T_& _scalar);	//subtract by scalar

	Matrix& operator*	(const Matrix& _multMat);
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
	unsigned int rows, columns, size;
	T_ **ptrMat = nullptr;
};

//--------------------------------------------------------------------
//Methods implementation
//--------------------------------------------------------------------
template<typename T_>
Matrix<T_>::Matrix(const unsigned int& _rows, const unsigned int& _columns) : rows(_rows), columns(_columns) {
	ptrMat = new T_*[rows];
	for (unsigned int i = 0; i < rows; ++i) {
		ptrMat[i] = new T_[columns];
	}
	for (unsigned int i = 0; i < rows; ++i) {
		for (unsigned int j = 0; j < columns; ++j) {
			ptrMat[i][j] = (T_)0; //initialized by default with 0s
		}
	}
}

//--------------------------------------------------------------------
template<typename T_>
Matrix<T_>::Matrix(const unsigned int& _size) {
	rows = _size;
	columns = _size;
	ptrMat = new T_*[rows];
	for (unsigned int i = 0; i < rows; ++i) {
		ptrMat[i] = new T_[columns];
	}
}

//--------------------------------------------------------------------
template<typename T_>
Matrix<T_>::~Matrix() {
	for (unsigned int i = 0; i < rows; ++i) {
		delete[] ptrMat[i];
	}
	delete[] ptrMat;
}

//---------------------------------------------------------------------
template<typename T_>
Matrix<T_>::Matrix(const Matrix& _mat) {
	//copy constructor
	ptrMat = new T_*[_mat.rows];
	for (unsigned int i = 0; i < _mat.rows; ++i) {
		ptrMat[i] = new T_[_mat.columns];
	}
	for (unsigned int i = 0; i < _mat.rows; ++i) {
		for (unsigned int j = 0; j < _mat.columns; ++j) {
			ptrMat[i][j] = _mat.ptrMat[i][j];
		}
	}
	rows	= _mat.rows;
	columns = _mat.columns;
}

//---------------------------------------------------------------------
template<typename T_>
void Matrix<T_>::fill(const T_& _values) {
	for (auto i = 0; i < rows; ++i) {
		for (auto j = 0; j < columns; ++j) {
			ptrMat[i][j] = _values[i*rows + j];
		}
	}
}

//---------------------------------------------------------------------
template<typename T_>
T_& Matrix<T_>::operator()(const unsigned int& _row , const unsigned int& _column) {
	return ptrMat[_row][_column];
}

//---------------------------------------------------------------------
template<typename T_>
Matrix<T_>& Matrix<T_>::operator=	(const Matrix& _equalMat) {
	assert(((this->columns == _equalMat.columns) || (this->rows == _equalMat.rows)) && (this->size == _equalMat.size));
	for (auto i = 0; i < rows; ++i) {
		for (auto j = 0; j < columns; ++j) {
		ptrMat[i][j] = _equalMat.ptrMat[i][j];
		}
	}
	return *this;
}

//---------------------------------------------------------------------
template<typename T_>
Matrix<T_>& Matrix<T_>::operator+(const Matrix& _addMat) {
	assert((this->columns == _addMat.columns) || (this->rows == _addMat.rows) && (this->size == _addMat.size));
	for (auto i = 0; i < rows; ++i) {
		for (auto j = 0; j < columns; ++j) {
			ptrMat[i][j] += _addMat.ptrMat[i][j];
		}
	}
	return *this;
}

//---------------------------------------------------------------------
template<typename T_>
Matrix<T_>& Matrix<T_>::operator+	(const T_& _scalar) {
	for (auto i = 0; i < rows; ++i) {
		for (auto j = 0; j < columns; ++j) {
			ptrMat[i][j] += _scalar;
		}
	}
	return *this;
}

//---------------------------------------------------------------------
template<typename T_>
Matrix<T_>& Matrix<T_>::operator-	(const Matrix& _minusMat) {
	assert((this->columns == _minusMat.columns) || (this->rows == _minusMat.rows) && (this->size == _minusMat.size));
	for (auto i = 0; i < rows; ++i) {
		for (auto j = 0; j < columns; ++j) {
			ptrMat[i][j] -= _minusMat.ptrMat[i][j];
		}
	}
	return *this;

}
//---------------------------------------------------------------------
template<typename T_>
Matrix<T_>& Matrix<T_>::operator-	(const T_& _scalar) {
	for (auto i = 0; i < rows; ++i) {
		for (auto j = 0; j < columns; ++j) {
			ptrMat[i][j] -= _scalar;
		}
	}
	return *this;

}

//---------------------------------------------------------------------
template<typename T_>
Matrix<T_>& Matrix<T_>::operator*	(const Matrix& _secondMat) {}
//---------------------------------------------------------------------
template<typename T_>
Matrix<T_>& Matrix<T_>::operator*	(const T_& _scalar) {}
//---------------------------------------------------------------------
template<typename T_>
Matrix<T_>& Matrix<T_>::operator/	(const Matrix& _divideMat) {}
//---------------------------------------------------------------------
template<typename T_>
Matrix<T_>& Matrix<T_>::operator/	(const T_& _scalar) {}

#endif //_MATRIX_OP_
