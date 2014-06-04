/*
	Title: CharlesLib Matrix package.
	Brief: Provides Matrix related functions.
	Author: Carlos Manuel Rodriguez y Martinez.
	License: GPLv3.
*/

#include <vector>
#ifndef _MatrixClass
#define _MatrixClass
using namespace std;

#ifndef NULL
#define NULL 0
#endif

/**
* @class Matrix
* @brief Basic matrix storage.
**/
template <class T> class Matrix
{
	T** m_matrix;
	unsigned int m_ncols;
	unsigned int m_nrows;

	T CalcDeterminant(T **inM, unsigned int size);
	void FreeMem();
public:

	///@brief Default constructor.
	Matrix();

	///@brief Copy constructor.
	Matrix(const Matrix<T> &other);

	///@brief Creates empty matrix.
	Matrix(unsigned int rows, unsigned int cols);

	///@brief Copy matrix from raw data.
	Matrix(unsigned int rows, unsigned int cols, T** input);

	~Matrix();

	// ## Set values. ##

	///@brief Creates empty matrix.
	bool SetMatrix(unsigned int rows, unsigned int cols);

	///@brief Copy matrix from raw data.
	bool SetMatrix(unsigned int rows, unsigned int cols, T** input);

	///@brief Copy matrix.
	bool SetMatrix(Matrix<T> *input);

	///@brief Safely set element.
	void SetElement(unsigned int i, unsigned int j, T val);


	// ## Get values. ##
	T** GetMatrix();
	std::vector<T> GetRow(unsigned int row);
	unsigned int GetNumCols();
	unsigned int GetNumRows();

	///@brief Safely access element.
	T At(unsigned int i, unsigned int j);
	T*& operator[](const unsigned int pos);
};

template <class T> Matrix<T>::Matrix()
{
	m_ncols = 0;
	m_nrows = 0;
	m_matrix = NULL;
}
template <class T> Matrix<T>::Matrix(const Matrix<T> &other)
{
	m_matrix = NULL;
	this->SetMatrix(other.m_nrows, other.m_ncols, other.m_matrix);
}
template <class T> Matrix<T>::Matrix(unsigned int rows, unsigned int cols, T** inputMatrix)
{
	m_matrix = NULL;
	m_ncols = 0;
	m_nrows = 0;
	this->SetMatrix(rows, cols, inputMatrix);
}
template <class T> Matrix<T>::Matrix(unsigned int rows, unsigned int cols)
{
	m_matrix = NULL;
	m_ncols = 0;
	m_nrows = 0;
	this->SetMatrix(rows, cols);
}
template <class T> Matrix<T>::~Matrix()
{
	this->FreeMem();
}
template <class T> void Matrix<T>::FreeMem()
{
	if(m_matrix != NULL)
	{
		for(unsigned int i=0; i<m_nrows; i++)
		{
			if(m_matrix[i] != NULL) delete[] m_matrix[i];
		}
		delete[] m_matrix;
	}
}
template <class T> bool Matrix<T>::SetMatrix(Matrix<T> *matrix)
{
	return this->SetMatrix(matrix->GetNumRows(), matrix->GetNumCols(), matrix->GetMatrix());
}
template <class T> bool Matrix<T>::SetMatrix(unsigned int rows, unsigned int cols, T** inputMatrix)
{
	this->FreeMem();
	m_nrows = rows;
	m_ncols = cols;
	try
	{
		m_matrix = new T*[m_nrows];
		for(unsigned int i=0; i<m_nrows; i++)
		{
			m_matrix[i] = new T[m_ncols];
		}
	}
	catch(std::bad_alloc& ba)
	{
		return false;
	}

	// Assign values.
	if(inputMatrix != NULL)
	{
		for(unsigned int i=0; i<m_nrows; i++)
		{
			for(unsigned int j=0; j<m_ncols; j++)
			{
				m_matrix[i][j] = inputMatrix[i][j];
			}
		}
	}
	else
	{
		for(unsigned int i=0; i<m_nrows; i++)
		{
			for(unsigned int j=0; j<m_ncols; j++)
			{
				m_matrix[i][j] = 0;
			}
		}
	}
	return true;
}
template <class T> bool Matrix<T>::SetMatrix(unsigned int rows, unsigned int cols)
{
	this->FreeMem();
	m_nrows = rows;
	m_ncols = cols;
	try
	{
		m_matrix = new T*[m_nrows];
		for(unsigned int i=0; i<m_nrows; i++)
		{
			m_matrix[i] = new T[m_ncols];
		}
	}
	catch(std::bad_alloc& ba)
	{
		return false;
	}
	return true;
}
template <class T> T** Matrix<T>::GetMatrix()
{
	return m_matrix;
}
template <class T> void Matrix<T>::SetElement(unsigned int i, unsigned int j, T val)
{
	if((i<m_nrows && i>=0) && (j<m_ncols && j>=0))
	{
		m_matrix[i][j] = val;
	}
}
template <class T> T Matrix<T>::At(unsigned int i, unsigned int j)
{
	if((i<m_nrows && i>=0) && (j<m_ncols && j>=0))
	{
		return m_matrix[i][j];
	}
	else return 0;
}
template <class T> std::vector<T> Matrix<T>::GetRow(unsigned int fil)
{
	std::vector<T> out;
	for(int j=0; j<m_ncols; j++)
	{
		out.push_back(m_matrix[fil][j]);
	}
	return out;
}
template <class T> unsigned int Matrix<T>::GetNumCols()
{
	return m_ncols;
}
template <class T> unsigned int Matrix<T>::GetNumRows()
{
	return m_nrows;
}

// Operators.
template <class T> T*& Matrix<T>::operator[](const unsigned int pos)
{
	return m_matrix[pos];
}

#endif //_MatrixClass
