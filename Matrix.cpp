/** Title: Programming Assignment 1 - Matrix Manipulation
    Author: Ada Chen
    Date Created: September 11, 2015
    Brief Purpose: Program tests the big five implementation, overload of +, [], << and = operators, and swap functions.
**/

#ifndef MATRIX_CPP_INCLUDED
#define MATRIX_CPP_INCLUDED

#include "Matrix.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstddef>

using namespace std;

//constructor creates a matrix of size 0,0
template <typename Comparable>
Matrix<Comparable>::Matrix()
{
    num_rows_ = 0; //sets num of rows to 0
    num_cols_ = 0; //sets num of columns to 0
    for(size_t i=0; i< num_rows_; i++)
    {
        array_[i] = new Comparable[num_cols_];
    }
}

//destructor
template <typename Comparable>
Matrix<Comparable>::~Matrix()
{
    DeleteMatrix(); //calls the delete function
    array_= nullptr;
}

//accessor function
template <typename Comparable>
size_t Matrix<Comparable>::NumRows() const
{
    return num_rows_;
}

//accessor function
template <typename Comparable>
size_t Matrix<Comparable>::NumCols() const
{
    return num_cols_;
}

//delete matrix
template <typename Comparable>
void Matrix<Comparable>::DeleteMatrix()
{
    for(size_t i; i< NumRows(); i++)    //loops through a matrix and deletes all values
    {
        //of the matrix
        delete[] array_[i];
        array_[i] = nullptr;
    }
    delete[] array_;
}

//creates and fills in a matrix
template <typename Comparable>
void Matrix<Comparable>::ReadMatrix()
{
    Comparable value; //creates variable of type comparable

    cout<<"\nInput a number of rows for the matrix: "; //asks for number of rows from user
    cin>> num_rows_;

    cout<<"Input a number of columns for the matrix: "; //asks for number of columns from user
    cin>> num_cols_;

    array_ = new Comparable*[num_rows_];

    for(size_t i = 0; i < num_rows_; i++)       //loop fills the matrix with inputs from user
    {
        array_[i] = new Comparable[num_cols_];

        for(size_t j = 0; j< num_cols_; j++)
        {
            cout<<"\nInput the value for row " << i << " and column " << j << "\n";
            cin >> value;
            array_[i][j] = value; //inputs user value into matrix positions
        }
    }
}

//copy assignment operator
template <typename Comparable>
Matrix <Comparable>& Matrix<Comparable>::operator=(const Matrix<Comparable>& rhs)
{
    if( this != &rhs ) //if the two matrices are not the same, run code
    {
        DeleteMatrix(); //deletes matrix the operator is called for
        array_ = nullptr;

        array_ = new Comparable*[rhs.NumRows()]; //creates new comparable

        for(size_t i = 0; i < rhs.NumRows(); i++)
        {
            array_[i] = new Comparable[num_cols_];
        }
        for(size_t i = 0; i < rhs.NumRows(); i++)
        {
            for(size_t j = 0; j < rhs.NumCols(); j++)
            {
                array_[i][j] = rhs.array_[i][j];
            }
        }
        this->num_rows_ = rhs.NumRows();        //sets size of "this" matrix
        this->num_cols_ = rhs.NumCols();        //to the size of rhs rows and columns
        this->array_ = array_;
    }

    return *this; // handle self assignment
}

//move assignment operator
template <typename Comparable>
Matrix <Comparable>& Matrix<Comparable>::operator=(Matrix<Comparable> && rhs)
{
    for(size_t i = 0; i < rhs.NumRows(); i++)
    {
        for(size_t n=0; n< rhs.NumCols(); n++)
        {
            array_[i][n] = std::move(rhs.array_[i][n]); //implementation of std::move
        }
    }
    this->num_cols_ = rhs.NumCols();    //sets size of "this" matrix
    this->num_rows_ = rhs.NumRows();    //to the size of rhs rows and columns
    this->array_ = array_;
    return *this;
}

//copy constructor
template <typename Comparable>
Matrix <Comparable>::Matrix(const Matrix<Comparable> & rhs)
{
    num_rows_ = rhs.NumRows();
    num_cols_ = rhs.NumCols(); //set rows and columns to the size of rhs rows and columns

    array_ = new Comparable* [rhs.NumRows()];

    for(size_t i = 0; i < rhs.NumRows(); i++)
    {
        array_[i]= new Comparable[rhs.NumCols()];

        for(size_t j = 0; j < rhs.NumCols(); j++)
        {
            array_[i][j] = rhs.array_[i][j];    //copies values from rhs matrix to new comparable
        }
    }

}

//move constructor
template <typename Comparable>
Matrix <Comparable>::Matrix(Matrix<Comparable> && rhs)
{
    num_rows_ = (rhs.num_rows_);
    num_cols_ = (rhs.num_cols_);
    array_ = std::move(rhs.array_); //moves everything from rhs to array_
    rhs.num_rows_ = 0;
    rhs.num_cols_ = 0;
    rhs.array_ = nullptr;
}


//plus assignment operator
template <typename Comparable>
Matrix <Comparable> Matrix<Comparable>::operator+(const Matrix<Comparable>& rhs)
{
    Matrix<Comparable> sum = *this;

    Matrix<Comparable> error;

    if ((NumCols() == rhs.NumCols()) && (NumRows() == rhs.NumRows())) //if columns and rows are the same
    {
        for(size_t i = 0; i < NumRows(); i++ )
        {
            for(size_t j = 0; j < NumCols(); j++)
            {
                sum.array_[i][j] = ((array_[i][j])+ (rhs.array_[i][j])); //add the matrices
            }
        }
        return sum; //return the sum
    }
    else
    {
        cout << "The matrices do not have the same size." << endl; //if they do the not have same size, output error
        return error;
    }
}

//plus assignment operator for strings
template <typename Comparable>
Matrix <Comparable> Matrix<Comparable>::operator+(const string & rhs)
{
    Matrix<Comparable> sum = *this;
    for(size_t i = 0; i < NumRows(); i++ )
    {
        for(size_t n=0; n< NumCols(); n++)
        {
            sum.array_[i][n] = ((array_[i][n])+ rhs);
        }
    }
    return sum;
}

//bracket operator
template <typename Comparable>
vector <Comparable> Matrix<Comparable>::operator[](const size_t row_position)
{
    if(row_position >= this->NumCols())
    {
        cout << "Invalid row position\n";
        return *(new vector<Comparable>);
    }
    vector<Comparable> row(this->num_cols_);

    for(size_t j = 0; j < this->NumCols(); j++)
    {
        row.push_back(array_[row_position][j]);
    }

    return row;
}

//print vector
template <typename Comparable>
void Matrix<Comparable>::PrintVec(const vector <Comparable> row)
{
    for (size_t i= 0; i< row.size(); i++) //loops through vector and prints contents of row passed
    {
        cout << row.at(i)<<"  ";
    }
}

//swap function
template <typename Comparable>
void Matrix<Comparable>::Swap(Matrix<Comparable> & rhs)
{
    Matrix<Comparable> Copy = rhs;
    rhs = std::move(*this);     //swaps two matrices
    *this = std::move(Copy);
}

#endif

