/**********************************************
 * Name: Ethan Haley                          *
 * Date: November 6, 2012                     *
 * Assignment: Project 6: Matrices            *
 **********************************************
 * Reads in two matrices and multiplies them  *
 **********************************************/

#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
    string in;
    cout << "Enter first matrix (put // to denote row breaks): ";
    getline(cin, in);
    int pos = in.find_first_of("//", 0);
    string temp = in.substr(0, pos);
    int col = 0;
    for(int i = 0; i < temp.length(); i++)
    {
        if(temp[i] >= 48 && temp[i] <= 57)
        {
            col++;
        }
    }
    int row = 0;
    for(int i = 0; i < in.length(); i++)
    {
        if(in[i] == 47)
        {
            row++;
        }
    }
    row = (row/2) + 1;
    Matrix* m1 = new Matrix(col, row);
    
    cout << "Enter second matrix (put // to denote row breaks): ";
    getline(cin, in);
    pos = in.find_first_of("//", 0);
    temp = in.substr(0, pos);
    col = 0;
    for(int i = 0; i < temp.length(); i++)
    {
        if(temp[i] >= 48 && temp[i] <= 57)
        {
            col++;
        }
    }
    row = 0;
    for(int i = 0; i < in.length(); i++)
    {
        if(in[i] == 47)
        {
            row++;
        }
    }
    row = (row/2) + 1;
    Matrix* m2 = new Matrix(col, row);

    
    return 0;
}