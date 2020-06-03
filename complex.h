#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>

class complex
{

private:
    long double re , im;

public:
    //-----------------------------------------------------------------------------------------------------
    // Constructors
    complex();
    complex(long double);
    complex(long double , long double);
    // Destructor
    ~complex();
    //-----------------------------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------------------------
    // iostream overloading
    friend std::ostream& operator<<(std::ostream& , const complex&); // output to console
    friend std::istream& operator>>(std::istream& , complex&      ); // input to complex variable object
    //-----------------------------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------------------------
    // bool logic overloading
    friend bool     operator==(const complex& , const complex&);     // L = (z1.re == z2.re) && (z1.im == z2.im)
    friend bool     operator==(long double    , const complex&);     // L = (z1.re == R) && (z1.im == 0)
    friend bool     operator==(const complex& , long double   );     // L = (z1.re == R) && (z1.im == 0)
    friend bool     operator< (const complex& , const complex&);     // L = mod(z1) < mod(z2)
    friend bool     operator< (const complex& , long double   );     // L = mod(z1) < R
    friend bool     operator< (long double    , const complex&);     // L = R < mod(z1)
    friend bool     operator<=(const complex& , const complex&);     // L = (z1 < z2) || (z1 == z2)
    friend bool     operator<=(const complex& , long double   );     // L = (z1 < R) || (z1 == R)
    friend bool     operator<=(long double    , const complex&);     // L = (R < z1) || (R == z1)
    friend bool     operator> (const complex& , const complex&);     // L = mod(z1) > mod(z2)
    friend bool     operator> (const complex& , long double   );     // L = mod(z1) > R
    friend bool     operator> (long double    , const complex&);     // L = R > mod(z1)
    friend bool     operator>=(const complex& , const complex&);     // L = (z1 > z2) || (z1 == z2)
    friend bool     operator>=(const complex& , long double   );     // L = (z1 > R) || (z1 == R)
    friend bool     operator>=(long double    , const complex&);     // L = (R > z1) || (R == z1)
    //-----------------------------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------------------------
    // Addition overloading
    friend complex  operator+ (const complex& , long double   );     // C = Z + R
    friend complex  operator+ (long double    , const complex&);     // C = R + Z
    friend complex  operator+ (const complex& , const complex&);     // C = Z0 + Z1 
    friend void     operator+=(complex&       , const complex&);     // C = C + Z
    friend void     operator+=(complex&       , long double   );     // C = C + R
    //-----------------------------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------------------------
    // Subtraction overloading
    friend complex  operator- (const complex& , long double   );     // C = Z - R
    friend complex  operator- (long double    , const complex&);     // C = R - Z
    friend complex  operator- (const complex& , const complex&);     // C = Z0 - Z1 
    friend void     operator-=(complex&       , const complex&);     // C = C - Z
    friend void     operator-=(complex&       , long double   );     // C = C - R
    //-----------------------------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------------------------
    // Multiplication overloading
    friend complex  operator* (const complex& , long double   );     // C = Z * R
    friend complex  operator* (long double    , const complex&);     // C = R * Z
    friend complex  operator* (const complex& , const complex&);     // C = Z0 * Z1 
    friend void     operator*=(complex&       , const complex&);     // C = C * Z
    friend void     operator*=(complex&       , long double   );     // C = C * R
    //-----------------------------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------------------------
    // Division overloading
    friend complex  operator/ (const complex& , long double   );     // C = Z / R
    friend complex  operator/ (long double    , const complex&);     // C = R / Z
    friend complex  operator/ (const complex& , const complex&);     // C = Z0 / Z1 
    friend void     operator/=(complex&       , const complex&);     // C = C / Z
    friend void     operator/=(complex&       , long double   );     // C = C / R
    //-----------------------------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------------------------
    // Mathematical operators
    friend long double Re  (const complex&                 );        // R = z.re
    friend long double Im  (const complex&                 );        // R = z.im
    friend long double mod (const complex&                 );        // R = sqrt(z.re^2 + z.im^2)
    friend complex     conj(const complex&                 );        // C = (Z.re , -1*Z.im)
    friend long double arg (const complex&                 );        // R = arg(Z)
    friend long double arg (long double                    );        // R = arg(R)
    friend complex     pow (const complex& , const complex&);        // C = Z0^Z1
    friend complex     pow (const complex& , long double   );        // C = Z^R
    friend complex     pow (long double    , const complex&);        // C = R^Z
    friend complex     exp (const complex&                 );        // C = e^Z
    friend complex     log (const complex&                 );        // C = log(Z)
    friend complex     sin (const complex&                 );        // C = sin(Z)
    friend complex     cos (const complex&                 );        // C = cos(Z)
    friend complex     tan (const complex&                 );        // C = tan(Z)

    //-----------------------------------------------------------------------------------------------------



};

#endif