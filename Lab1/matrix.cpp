/**********************************************
 * Name: Ethan Haley                          *
 * Date: November 6, 2012                     *
 * Assignment: Project 6: Matrices            *
 **********************************************
 * Reads in two matrices and multiplies them  *
 **********************************************/

#include "matrix.h"
#include <iostream>
#include <cstdio>
using namespace std;

Matrix::Matrix(int r, int c)
{
	rows = r;
	columns = c;
	arr = new int *[rows];
	for(int i = 0; i < rows; i++)
	{
		arr[i] = new int [columns];
	}
}

Matrix::~Matrix()
{
	for(int i = 0; i < rows; i++)
	{
		delete [] arr[i];
		delete [] arr;
	}
}

void Matrix::setElem(int r, int c, int val)
{
	arr[r][c] = val;
}

int Matrix::getElem(int r, int c)
{
	return arr[r][c];
}

Matrix* Matrix::times(Matrix* mat)
{
	if(this->columns != mat->rows)
	{
		cout << "Error: Dimensions do not match" << endl;
		return NULL;
	}
	Matrix* retMatrix = new Matrix(this->rows, mat->columns);
	for(int i = 0; i < retMatrix->rows; i++)
	{
		for(int j = 0; j < retMatrix->columns; j++)
		{
			int temp = 0;
			for(int k = 0; k < mat->rows; k++)
			{
				temp += this->getElem(i, k) * mat->getElem(k, j);
			}
            retMatrix->setElem(i, j, temp);
		}
	}
	return retMatrix;
}

void Matrix::print(void)
{
	for(int i = 0; i < this->rows; i++)
	{
		cout << "\n";
		for(int j = 0; j < this->columns; j++)
		{
			cout << " " << this->getElem(i, j);
		}
		cout << endl;
	}
}






