#include "complex.h"

complex j(0,1);
//-----------------------------------------------------------------------------------------------------
// constructors
complex::complex() { re = 0; im = 0; }
complex::complex(long double x) { re = x; im = 0; }
complex::complex(long double x , long double y) { re = x ; im = y; }

complex::~complex() {}
//-----------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------
// iostream overloading
std::ostream& operator<<(std::ostream &s , const complex &z) {
    if (z.im >= 0) {
        s << z.re << " + " << z.im << "j"; 
        return s;
    }
    s << z.re << " - " << -1.0*z.im << "j"; 
    return s;
}

std::istream& operator>>(std::istream &s , complex &z) {
    s >> z.re >> z.im; 
    return s;
}
//-----------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------
// bool logic overloading
bool operator==(const complex &z1, const complex &z2){
    return (z1.re == z2.re) && (z1.im == z2.im);
}

bool operator==(long double x  , const complex &z) {
    return (z.re == x) && (z.im == 0);
}

bool operator==(const complex &z, long double x  ) {
    return (z.re == x) && (z.im == 0);
}

bool operator< (const complex &z1 , const complex &z2) {
    return mod(z1) < mod(z2);
}

bool operator< (const complex &z , long double x) {
    return mod(z) < x;
}

bool operator< (long double x   , const complex &z ) {
    return x < mod(z);
}

bool operator<=(const complex &z1 , const complex &z2) {
    return (z1 < z2) || (z1 == z2);
}

bool operator<=(const complex &z , long double x  ) {
    return (z < x) || (z == x);
}

bool operator<=(long double x   , const complex &z) {
    return (x < z) || (x == z);
}

bool operator> (const complex &z1 , const complex &z2) {
    return mod(z1) > mod(z2);
}

bool operator> (const complex &z , long double x  ) {
    return mod(z) > x;
}

bool operator> (long double x   , const complex &z) {
    return x > mod(z);
}

bool operator>=(const complex &z1 , const complex &z2) {
    return (z1 > z2) || (z1 == z2);
}

bool operator>=(const complex &z , long double x  ) {
    return (z > x) || (z == x);
}

bool operator>=(long double x   , const complex &z) {
    return (x > z) || (x == z);
}
//-----------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------
// addition overloading
complex operator+(const complex &z , long double x) {
    return complex(z.re + x , z.im);
}

complex operator+(long double x , const complex &z) {
    return complex(z.re + x , z.im);
}

complex operator+(const complex &z1 , const complex &z2) {
    return complex(z1.re + z2.re , z1.im + z2.im);
}

void operator+=(complex &z1 , const complex &z2) {
    z1.re += z2.re;
    z1.im += z2.im;
}

void operator+=(complex &z1 , long double x) {
    z1.re += x;
}
//-----------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------
// subtraction overloading
complex operator-(const complex &z , long double x) {
    return complex(z.re - x , z.im);
}

complex operator-(long double x , const complex &z) {
    return complex(x - z.re , -1.0 * z.im);
}

complex operator-(const complex &z1 , const complex &z2) {
    return complex(z1.re - z2.re , z1.im - z2.im);
}

void operator-=(complex &z1 , const complex &z2) {
    z1.re -= z2.re;
    z1.im -= z2.im;
}

void operator-=(complex &z1 , long double x) {
    z1.re -= x;
}
//-----------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------
// multiplication overloading
complex operator*(const complex &z , long double x) {
    return complex(x * z.re , x * z.im);
}

complex operator*(long double x , const complex &z) {
    return complex(x * z.re , x * z.im);
}

complex operator*(const complex &z1 , const complex &z2) {
    return complex(z1.re * z2.re - z1.im * z2.im , z1.re * z2.im + z1.im * z2.re);
}

void operator*=(complex &z1 , const complex &z2) {
    complex temp(z1.re , z1.im);
    z1.re = temp.re * z2.re - temp.im * z2.im;
    z1.im = temp.re * z2.im + temp.im * z2.re;
}

void operator*=(complex &z , long double x) {
    z.re *= x;
    z.im *= x;
}
//-----------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------
// division overloading
complex operator/(const complex &z , long double x) {
    if (x == 0) {
        std::cout << "Error : dividing by zero in \"operator/(const complex &z , long double x)\"\n";
        exit(-1);
    }
    return complex(z.re / x , z.im / x);
}

complex operator/(long double x , const complex &z) {
    if (z == 0) {
        std::cout << "Error : dividing by zero in \"operator/(long double x , const complex &z)\"\n";
        exit(-1);
    }
    return x * conj(z) / (mod(z) * mod(z));
}

complex operator/(const complex &z1 , const complex &z2) {
    if (z2 == 0) {
        std::cout << "Error : dividing by zero in \"operator/(const complex &z1 , const complex &z2)\"\n";
        exit(-1);
    }
    return z1 * conj(z2) / (mod(z2) * mod(z2));
}

void operator/=(complex &z1 , const complex &z2) {
    if (z2 == 0) {
        std::cout << "Error : dividing by zero in \"operator/=(const complex &z1 , const complex &z2)\"\n";
        exit(-1);
    }
    complex temp(z1.re , z1.im);
    z1 = temp / z2;
}

void operator/=(complex &z , long double x) {
    if (x == 0) {
        std::cout << "Error : dividing by zero in \"operator/=(complex &z , long double x)\"\n";
        exit(-1);
    }
    z.re /= x;
    z.im /= x;
}
//-----------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------
// mathematical operators
long double Re(const complex &z) {
    return z.re;
}

long double Im(const complex &z) {
    return z.im;
}

long double mod(const complex &z) {
    return sqrt(z.re * z.re + z.im * z.im);
}

complex conj(const complex &z) {
    return complex(z.re , -1.0 * z.im);
}

long double arg(const complex &z) {
    return atan2(z.im , z.re) * 180.0 / 3.14159265359;
}

long double arg(long double x) {
    return x-x;
}

complex pow(const complex &z1 , const complex &z2) {
    if ((z1 == 0) && (z2 == 0)) {
        std::cout << "Error : invalid arguments in \"pow(const complex &z1 , const complex &z2)\"\n";
        exit(-1);
    }
    if (z1 == 0) {
        return complex(0.0 , 0.0);
    }
    return exp(z2 * log(z1));
}

complex pow(const complex &z , long double x) {
    if ((z == 0) && (x == 0)) {
        std::cout << "Error : invalid arguments in \"pow(const complex &z , long double x)\"\n";
        exit(-1);
    }
    if (z == 0) {
        return complex(0.0 , 0.0);
    }
    return exp(x * log(z));
}

complex pow(long double x , const complex &z) {
    if ((z == 0) && (x == 0)) {
        std::cout << "Error : invalid arguments in \"pow(long double x , const complex &z)\"\n";
        exit(-1);
    }
    if (x == 0) {
        return complex(0.0 , 0.0);
    }
    return exp(z * log(x));
}

complex exp(const complex &z) {
    return complex(exp(z.re) * cos(z.im) , exp(z.re) * sin(z.im));
}

complex log(const complex &z) {
    if (z == 0) {
        std::cout << "Error : invalid argument in \"log(const complex &z)\"\n";
        exit(-1);
    }
    return complex(log(mod(z)) , atan2(z.im , z.re));
}

complex sin(const complex &z) {
    return (exp(j * z) - exp(j * z * -1.0)) / (2 * j);
}

complex cos(const complex &z) {
    return (exp(j * z) + exp(j * z * -1.0)) / 2;
}

complex tan(const complex &z) {
    if (cos(z) == 0) {
        std::cout << "Error : invalid argument in \"tan(const complex &z)\"\n";
        exit(-1);
    }
    return sin(z) / cos(z);
}
//-----------------------------------------------------------------------------------------------------