# Complex-Numbers
Adds overloads of basic arithmetic operators to allow for basic mathematical operators with complex numbers

Include the complex.h file in your main and you should be good to go!

In all of these examples I use the constant "i" to represent sqrt(-1), however in the code, I prefer to use "j"

Three types of constructors when defining a new complex variable
complex z;      // z = 0 + 0i;
complex z(x);   // z = x + 0i;
complex z(x,y)  // z = x + iy;

The following operators are overloaded
{ + , += , - , -= , * , *= , / , /= , == , < , <= , > , >= , << , >> }

When inputing a complex number, the stream extraction operator is expecting the real part followed by a space 
and then the imaginary part
example:  std::cin >> z;
console -> 4 6 [enter]  
z is now equal to 4 + 6i

When a complex object is sent into a stream insertion operator it is output in the form a + bi
example:  std::cout << "Hello World! : " << z << "\n";  
output :  Hello World! : a + bi;

When adding a non complex number to a complex number, the result is casted into a complex number.
example: 
complex z;
std::cout << z + 4.4 << "\n";
output : 4.4 + 0i;

The <cmath> library is included, and the following functions are curently able to except complex numbers
{ exp , log , pow , sin , cos , tan }

Four other functions are included
{ Re , Im , mod , conj } 
Re(z) returns the real part of the complex number
Im(z) returns the imaginary part of the complex number
mod(z) returns the modulus "absolute value" of the complex number
conj(z) returns the complex conjugate of the complex number -> z  (z.re -1*z.im)
