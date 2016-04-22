/** Title: Programming Assignment 1 - Matrix Manipulation
    Author: Ada Chen
    Date Created: September 11, 2015
    Brief Purpose: Program tests the big five implementation, overload of +, [], << and = operators, and swap functions.
**/

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <string>
#include <cstddef>

using namespace std;

template <typename Comparable>
class Matrix
{
public:
    Matrix(); //constructor
    ~Matrix(); //destructor
    size_t NumRows () const; //accessor function
    size_t NumCols () const; //accessor function
    void DeleteMatrix();
    void ReadMatrix ();

    friend ostream& operator<<(ostream & out, const Matrix<Comparable>& rhs) //friend function for operator<< overload
    {
        {
            for(size_t i=0; i< rhs.num_rows_; i++)
            {
                for(size_t j = 0; j < rhs.num_cols_; j++)
                {
                    out << rhs.array_[i][j] << " ";
                }

                out << endl;
            }
            return out;
        }
    }

    Matrix& operator=(const Matrix<Comparable>& rhs);   //copy assignment operator
    Matrix& operator=(Matrix<Comparable>&& rhs);    //move assignment operator
    Matrix(const Matrix<Comparable>& rhs);  //copy constructor
    Matrix(Matrix<Comparable>&& rhs);   //move constructor
    Matrix<Comparable> operator+(const Matrix<Comparable>& rhs); //plus operator
    Matrix<Comparable> operator+(const string & rhs);
    vector <Comparable> operator[](const size_t row_location);
    void PrintVec(const vector<Comparable> row);
    void Swap(Matrix & rhs);

private:
    size_t num_cols_;
    size_t num_rows_;
    Comparable **array_;
};


#include "Matrix.cpp"
#endif // MATRIX_H

