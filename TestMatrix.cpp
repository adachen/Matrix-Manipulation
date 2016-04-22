/** Title: Programming Assignment 1 - Matrix Manipulation
    Author: Ada Chen
    Date Created: September 11, 2015
    Brief Purpose: Program tests the big five implementation, overload of +, [], << and = operators, and swap functions.
**/

#include "Matrix.h"
#include <iostream>
#include <string>

using namespace std;

void TestPart1(void);   //tests implementation of big five
void TestPart2(void);   //tests overload of + and [] operators
void TestPart3(void);   //tests implementation of swap function

int main()
{
    //function calls for each test
    TestPart1();
    TestPart2();
    TestPart3();
    return 0;
} //end main

//test part 1 tests the implementation of the big five
void TestPart1()
{
    Matrix<int> a, b;      //two matrices are created, it will call the constructor
    cout <<"Test Part 1:\n\nThis is testing the two empty matricies \n" << a.NumRows() << "  " << a.NumCols() << endl; // yields 0 0

    a.ReadMatrix(); // user provides number of rows, columns and matrix values
    cout<< "This is matrix A \n" << a <<endl;

    b.ReadMatrix();
    cout << "This is matrix B \n" << b << endl;

    a = b;  //calls the copy assignment operator for a.
    cout << "This is the result of the copy assignment operator \n" << a << endl;

    Matrix<int> c = b;  //calls the copy constructor for a.
    cout << "This is the result of the copy constructor \n" << c << endl;

    Matrix<int> d = std::move(c);  // calls move constructor for d.
    cout << "This is the result of the move constructor \n" << d << endl;

    a = std::move(d);  //calls the move assignment operator for a.
    cout << "This is the result of move assignment operator \n" << a << endl;

}  // destructors called

//tests overload of + and [] operators
void TestPart2()
{
    Matrix<string> a, b;
    cout << "Test Part 2: \n";
    a.ReadMatrix();  // user provides input for matrix a.
    cout << "Test Matrix A strings\n" << a << endl;

    b.ReadMatrix();  // user provides input for matrix b.
    cout << "Test Matrix B strings \n" << b << endl;


    cout << "Add matrices A and B \n" << a + b << endl; // matrices should have same size.

    Matrix<string> d = a + b;

    cout << "Test a + b \n" << d <<endl;

    cout << "Test d+hi_there\n" << d + "hi_there" <<endl;

    cout <<"\nPrinting first row of a\n";
    a.PrintVec(a[0]);  // Should print the first row of a.
    cout <<"\nPrinting second row of b\n";
    b.PrintVec(b[1]);  // Should be print the second row of b.

}

//tests the swap function
void TestPart3()
{
    Matrix<double> a, b;

    cout << "\nTest Part 3:\n";
    a.ReadMatrix();  // User provides input for matrix a.

    cout <<"Testing type double Matrix a \n" << a << endl;

    b.ReadMatrix();  // User provides input for matrix b.
    cout << "Testing type double Matrix b \n" << b << endl;

    a.Swap(b); //swaps a and b
    cout << "Testing swap a\n" << a << endl;
    cout << "Testing swap b\n" << b << endl;
}  // End of TestPart3.



