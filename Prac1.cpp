/* 
Implement a class Complex which represents the Complex Number data type. Implement the following
1.	Constructor (including a default constructor which creates the complex number 0+0i).
2.	Overload operator+ to add two complex numbers.
3.	Overload operator* to multiply two complex numbers.
4.	Overload operators << and >> to print and read Complex Numbers
*/


// #include <iostream>
// using namespace std;

// class Complex {
//     private:
//         double real;
//         double img;

//     public:
//         // Default constructor
//         Complex() : real(0.0), img(0.0) {
//             // Optional: can be used for debugging
//             // cout << "This is a Default Constructor" << endl;
//         }

//         // Parameterized constructor
//         Complex(double a1, double a2) : real(a1), img(a2) {
//             cout << "This is a Parameterized Constructor" << endl;
//         }

//         // Copy constructor
//         Complex(const Complex& ne) : real(ne.real), img(ne.img) {
//             cout << "This is a Copy Constructor" << endl;
//         }

//         Complex(Complex& a,Complex& b): real(a.real+b.real),img(a.img+b.img){}

//         // Move constructor
//         Complex(Complex&& oth) noexcept : real(oth.real), img(oth.img) {
//             oth.real=0,oth.img=0;
//             cout << "This is a Move Constructor" << endl;
//             // No need to reset other object's members as they are not pointers
//             // But if there were pointers, we'd set them to nullptr here
//         }

//         ~Complex() {
//             // No need for delete, as we are not using new
//         }

//         void display() const {
//             cout << "The Complex Number is " << real << " + " << img << "i" << endl;
//         }
// };

// int main() {
//     Complex c1; // default
//     Complex c2(4.5, 4.6); // parameterized
//     Complex c3(c2); // copy
//     Complex c4(move(c2)); // move

//     c1.display(); // Default constructor output
//     c2.display(); // Parameterized constructor output
//     c3.display(); // Copy constructor output
//     c4.display(); // Move constructor output
//     c2.display(); // Moved-from state

//     return 0;
// }



#include <iostream>
using namespace std;

class Complex {
    private:
        double real;
        double img;

    public:
        // Default constructor
        Complex() : real(0.0), img(0.0) {}

        // Parameterized constructor
        Complex(double a1, double a2) : real(a1), img(a2) {}

        // Copy constructor
        Complex(const Complex& other) : real(other.real), img(other.img) {}

        // Move constructor
        Complex(Complex&& other) noexcept : real(other.real), img(other.img) {
            other.real = 0;
            other.img = 0;
        }

        // Destructor
        ~Complex() {}

        // Overload operator+
        Complex operator+(const Complex& other) const {
            return Complex(real + other.real, img + other.img);
        }

        // Overload operator*
        Complex operator*(const Complex& other) const {
            return Complex(
                real * other.real - img * other.img, 
                real * other.img + img * other.real
            );
        }

        // Overload operator<<
        friend ostream& operator<<(ostream& out, const Complex& c) {
            out << c.real << " + " << c.img << "i";
            return out;
        }

        // Overload operator>>
        friend istream& operator>>(istream& in, Complex& c) {
            in >> c.real >> c.img;
            return in;
        }
};

int main() {
    Complex c1; // default
    Complex c2(4.5, 4.6); // parameterized
    Complex c3(c2); // copy

    // Using overloaded operators
    Complex sum = c3 + c2;
    Complex product = c2 * c3;

    // Display results
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "c3: " << c3 << endl;
    cout << "Sum of c1 and c2: " << sum << endl;
    cout << "Product of c2 and c3: " << product << endl;

    // Input a complex number
    Complex c4;
    cout << "Enter a complex number (real and imaginary parts): ";
    cin >> c4;
    cout << "You entered: " << c4 << endl;

    return 0;
}
