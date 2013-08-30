/**********************************************
 * Name: Ethan Haley                          *
 * Date: November 6, 2012                     *
 * Assignment: Project 6: Matrices            *
 **********************************************
 * Reads in two matrices and multiplies them  *
 **********************************************/

#ifndef __Project6__matrix__
#define __Project6__matrix__
#include <iostream>

class Matrix {
private:
    int **arr;
    int rows;
    int columns;
public:
    Matrix(int, int);
    ~Matrix();
    void setElem(int, int, int);
    int getElem(int, int);
    Matrix* times(Matrix*);
    void print(void);
};

#endif