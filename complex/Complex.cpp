//========================================================
// Tom Vodrey, Anna Nguyen, and Khoa Ho
// Complex.cpp
// November 2023
// This file contains the class methods for the
// Complex number class.
//========================================================

#include "Complex.h"
#include <string.h>
#include <iostream>
#include <cmath>
using namespace std;

//========================================================
// setReal access method
// Tom Vodrey
// Sets the real number of a Complex number object
//
// Parameters:
// - float r - The new real number
//
// Return Value: None, changes this object
//========================================================
void Complex::setReal ( float r )
{
    a = r;
}

//========================================================
// getReal access method
// Hoa Nguyen
// Returns the real part of the complex number.
// Parameters: none
// Return Value: the real part as float
//========================================================
float Complex::getReal ( void ) const
{
    return a;
}

//========================================================
// setImag access method
// Khoa Ho
// Sets the imaginary part of a Complex number object
//
// Parameters:
// - float r - the new imaginary part
//
// Return Value: None, changes this object
//========================================================
void Complex::setImag ( float r )
{
    b = r;
}

//========================================================
// getImag
// Tom Vodrey
// Returns the value of the imaginary number
//
// Parameters: None
//
// Return Value: float of the imaginary number
//========================================================
float Complex::getImag ( void ) const
{
    return b;
}

//========================================================
// assignment operator
// Tom Vodrey
// Assigns the value of this Complex number
//
// Parameters:
// - Complex &c - The value being assigned
//
// Return Value: The changed value, changes this object
//========================================================
Complex Complex::operator= ( const Complex &c )
{
    a = c.a;
    b = c.b;
    return *this;
}

//========================================================
// addition operators
//========================================================
//========================================================
// addition operator with Complex
// Tom Vodrey
// Adds two Complex objects together
//
// Parameters:
// - Complex &c - The Complex being added to this object
//
// Return Value: The sum of the two Complex number objects
//========================================================
Complex Complex::operator+ ( const Complex &c ) const
{
    Complex ret;
    ret.a = a + c.a;
    ret.b = b + c.b;
    return ret;
}

//========================================================
// addition operator with float
// Hoa Nguyen
// Adds complex number with float.
// Parameters:
// - float f
// Return value:
// - Complex object which is sum of calling object and
// parameter.
//========================================================
Complex Complex::operator+ ( float f ) const
{
    Complex ret;
    ret.a = a + f;
    ret.b = b;
    return ret;
}

//========================================================
// addition operators with integer
// Khoa Ho
// Adds complex number with integer.
// Parameters:
// - int i
// Return value:
// - Complex object which is sum of calling object and
// parameter.
//========================================================
Complex Complex::operator+ ( int i ) const
{
    Complex ret;
    ret.a = a + i;
    ret.b = b;
    return ret;
}

//========================================================
// subtraction operators
// Hoa Nguyen
// Subtracts a Complex from this Complex object
// Parameters:
// - Complex reference to c
// Return Value:
// - Complex object which is the subtraction between
// calling object and parameter.
//========================================================
Complex Complex::operator- ( const Complex &c ) const
{
    Complex ret;
    ret.a = a - c.a;
    ret.b = b - c.b;
    return ret;
}

//========================================================
// Tom Vodrey
// Subtracts a float from this Complex object
//
// Parameters:
// - float f - The float being added to this object
//
// Return Value: The remainder of the Complex after subtraction
//========================================================
Complex Complex::operator- ( float f ) const
{
    Complex ret;
    ret.a = a - f;
    ret.b = b;
    return ret;
}

//========================================================
// subtraction operator with integer
// Khoa Ho
// Subtracts an integer from this Complex object
//
// Parameters:
// - int i
// subtraction operator with float
//========================================================
Complex Complex::operator- ( int i ) const
{
    Complex ret;
    ret.a = a - i;
    return ret;
}

//========================================================
// multiplication operators
//========================================================
//========================================================
// multiplication operator with Complex
// Hoa Nguyen
// Multiply two complex numbers
// Parameters:
// - Complex reference to c
// Return value:
// - Complex object which is the multiplication between
// calling object and parameter.
//========================================================
Complex Complex::operator* ( const Complex &c ) const
{
    Complex ret;
    ret.a = a * c.a - b * c.b;
    ret.b = a * c.b + b * c.a;
    return ret;
}

//========================================================
// multiplication operator with float
// Khoa Ho
// Multiplies this Complex object by a float
//
// Parameters:
// - float f
//
// Return Value: The product of this Complex and the float
//========================================================
Complex Complex::operator* ( float f ) const
{
    Complex ret;
    ret.a = a * f;
    ret.b = b * f;
    return ret;
}

//========================================================
// multiplication operator with int
// Tom Vodrey
// Multiplies this Complex object by an integer
//
// Parameters:
// - int i - The int this object will be multiplied by
//
// Return Value: The product of this Complex and the int
//========================================================
Complex Complex::operator* ( int i ) const
{
    Complex ret;
    ret.a = a * i;
    ret.b = b * i;
    return ret;
}

//========================================================
// division operators
//========================================================
//========================================================
// division operator with float
// Hoa Nguyen
// Divide a complex number by a float
// Parameters:
// - float f
// Return value:
// - Complex object which is the division between
// calling object and parameter.
//========================================================
Complex Complex::operator/ ( float f ) const
{
    Complex ret;
    ret.a = a / f;
    ret.b = b / f;
    return ret;
}

//========================================================
// division operator with int
// Tom Vodrey
// Divides this Complex object by an integer
//
// Parameters:
// - int i - The int this object will be divided by
//
// Return Value: The quotient of this Complex and the int
//========================================================
Complex Complex::operator/ ( int i ) const
{
    Complex ret;
    ret.a = a / i;
    ret.b = b / i;
    return ret;
}

//========================================================
// division operator with Complex
// Khoa Ho
// Divide a complex number by a complex number
// Parameters:
// - Complex reference to c
// Return value:
// - Complex object which is the division between
// calling object and parameter.
//========================================================
Complex Complex::operator/ ( const Complex &c ) const
{
    Complex ret;
    ret.a = (a * c.a + b * c.b) / (c.a * c.a + c.b * c.b);
    ret.b = (b * c.a - a * c.b) / (c.a * c.a + c.b * c.b);
    return ret;
}

//========================================================
// exponentiation
// Tom Vodrey
// Raises this Complex object by an integer
//
// Parameters:
// - int p - The power to which this object will be raised
//
// Return value: The raised value of this Complex
//========================================================
Complex Complex::operator^ ( int p ) const
{
    Complex ret;
    if ( p == 0 )
    {
        // To the power of zero
        ret.a = 1;
        ret.b = 0;
    }
    else
    {
        // Convert to polar form
        float mag = sqrt( pow(a, 2) + pow(b, 2) );
        float angle = atan2( b, a );
        // Raise polar form values to power using Euler's formula
        float magToP = pow( mag, p );
        float angleToP = angle * p;
        // Convert back to a + bi form
        ret.a = magToP * cos( angleToP );
        ret.b = magToP * sin( angleToP );
    }
    return ret;
}

//========================================================
// operator~
// Tom Vodrey
// Returns the conjugate of this Complex object
//
// Parameters:
// - None
//
// Return value: The conjugate of this Complex object
//========================================================
Complex Complex::operator~ ( void ) const
{
    Complex ret;
    ret.a = a;
    ret.b = -b;
    return ret;
}

//========================================================
// abs
// Khoa Ho
// Return the distance from the origin of the
// Complex number
// Parameters:
// - Complex reference to c
// Return value:
// - The distance of the Complex number to the origin,
// which is the absolute value of the Complex number
//========================================================
float Complex::abs ( void ) const
{
    return sqrt(a*a + b*b);
}

//========================================================
// equality operator
// Hoa Nguyen
// Determines if both real and imaginary parts are equal
// Parameters:
// - complex calling object and complex parameter
// Return value:
// - True if both real and imaginary parts are equal
//========================================================
bool Complex::operator== ( const Complex &c ) const
{
    return ( a == c.a ) && ( b == c.b );
}

//========================================================
// inequality operator
// Khoa Ho
// Determines if both real and imaginary parts are not equal
// Parameters:
// - complex calling object and complex parameter
// Return value:
// - True if both real and imaginary parts are not equal
//========================================================
bool Complex::operator!= ( const Complex &c ) const
{
    return ( a != c.a ) || ( b != c.b );
}

//==================================================
// negation
// Hoa Nguyen
// Parameters : none
// Return Value: -1 * calling Complex object
//==================================================
Complex Complex::operator- ( void )
{
    Complex ret;
    ret.a = a * -1;
    ret.b = b * -1;
    return ret;
}

//========================================================
// overload >> for cin
// Hoa Nguyen
// Allows reading of a complex number as a string .
// cin >> c1;
// reads: a+bi, a-bi, -a+bi, -a-bi, a+-bi, +a+bi
// reads: a, -a, +a, bi, -bi, +bi
// where a,b can be integers or reals with decimal points
//========================================================
istream &operator>> ( istream &, Complex &c )
{
    string input;
    cin >> input;
    c.a = 0;
    c.b = 0;
    size_t spot = input.find('i');
    if ( spot == string::npos )
        c.a = stof(input);
    else
    {
        size_t spot_sign = input.rfind('-', spot);
        if (spot_sign == string::npos || spot_sign == 0)
            spot_sign = input.rfind('+', spot);
        if ( spot_sign != string::npos )
        {
            if ( spot_sign != 0)
                c.a = stof(input.substr(0, spot_sign));
            else if (spot_sign == 0)
                c.a = 0;
            if ( input.substr( input.length() -2, 2 ) == "+i" )
                c.b = 1;
            else if ( input.substr( input.length() -2, 2 ) == "-i"
            )
                c.b = -1;
            else
                c.b = stof(input.substr( spot_sign, input.length() - spot_sign - 1 ));
        }
        if ( spot_sign == string::npos )
        {
            if ( input == "i" || input == "+i" )
                c.b = 1;
            else if ( input == "-i")
                c.b = -1;
            else
                c.b = stof( input );
        }
    }
    return cin;
}

//========================================================
// overload << for cout
// Khoa Ho
// Overload the ostream << operator so we can use
// cout to print our Complex object
// Parameters:
// ostream reference (current "ostream stack")
// Complex ( thing to add to the ostream )
// Return value:
// new ostream reference (with our object added)
//========================================================
ostream & operator<< ( ostream &os, const Complex c)
{
    if ( c.a == 0 && c.b == 0)
        os << "0";
    else if ( c.b == 0 )
        os << c.a;
    else if ( c.a == 0 )
    {
        if (c.b == 1)
            os << "i";
        else if (c.b == -1)
            os << "-i";
        else
            os << c.b << "i";
    }
    else if ( c.b < 0 )
    {
        if (c.b == -1)
            os << c.a << "-i";
        else
            os << c.a << c.b << "i";
    }
    else
    {
        if (c.b == 1)
            os << c.a << "+i";
        else
            os << c.a << "+" << c.b << "i";
    }
    return os;
}