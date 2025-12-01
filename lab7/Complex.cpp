#include "Complex.h"
#include <cmath>
#include <iostream>

using namespace std;

// ============================================================================
// CONSTRUCTORS
// ============================================================================

// Default constructor: creates 0 + 0i
Complex::Complex() {
    real = 0.0;
    imaginary = 0.0;
}

// Parameterized constructor: creates a + bi
Complex::Complex(double r, double i) {
    real = r;
    imaginary = i;
}

// ============================================================================
// GETTERS
// ============================================================================

double Complex::getReal() const {
    return real;
}

double Complex::getImaginary() const {
    return imaginary;
}

// ============================================================================
// SETTERS
// ============================================================================

void Complex::setReal(double r) {
    real = r;
}

void Complex::setImaginary(double i) {
    imaginary = i;
}

// ============================================================================
// ARITHMETIC OPERATORS
// ============================================================================

// Example: (3+4i) + (1+2i) = 4+6i
Complex Complex::operator+(const Complex &other) const {
    // Create new Complex number with sum
    Complex result;
    result.real = this->real + other.real;           // Add real parts
    result.imaginary = this->imaginary + other.imaginary;  // Add imaginary parts
    return result;
}


// Example: (5+6i) - (2+3i) = 3+3i
Complex Complex::operator-(const Complex &other) const {
    Complex result;
    result.real = this->real - other.real;           // Subtract real parts
    result.imaginary = this->imaginary - other.imaginary;  // Subtract imaginary parts
    return result;
}

// Multiplication: (a+bi) * (c+di) = (ac-bd) + (ad+bc)i
// Formula comes from: (a+bi)(c+di) = ac + adi + bci + bdi²
// Since i² = -1, we get: ac + adi + bci - bd = (ac-bd) + (ad+bc)i
// Example: (2+3i) * (1+4i) = (2*1 - 3*4) + (2*4 + 3*1)i = -10 + 11i
Complex Complex::operator*(const Complex &other) const {
    Complex result;
    // Real part: ac - bd
    result.real = (this->real * other.real) - (this->imaginary * other.imaginary);
    // Imaginary part: ad + bc
    result.imaginary = (this->real * other.imaginary) + (this->imaginary * other.real);
    return result;
}

// Division: (a+bi) / (c+di)
// Formula: multiply top and bottom by conjugate of denominator
// Result: [(ac+bd) + (bc-ad)i] / (c²+d²)
// Example: (4+2i) / (1+1i) = 3 - 1i
Complex Complex::operator/(const Complex &other) const {
    Complex result;
    
    // Calculate denominator: c² + d²
    double denominator = (other.real * other.real) + (other.imaginary * other.imaginary);
    
    // Check for division by zero
    if (denominator == 0) {
        cout << "Error: Division by zero!" << endl;
        return Complex(0, 0);
    }
    
    // Real part: (ac + bd) / (c² + d²)
    result.real = ((this->real * other.real) + (this->imaginary * other.imaginary)) / denominator;
    
    // Imaginary part: (bc - ad) / (c² + d²)
    result.imaginary = ((this->imaginary * other.real) - (this->real * other.imaginary)) / denominator;
    
    return result;
}

// ============================================================================
// COMPARISON OPERATORS
// ============================================================================

// Equal: two complex numbers are equal if both real and imaginary parts match
bool Complex::operator==(const Complex &other) const {
    return (this->real == other.real) && (this->imaginary == other.imaginary);
}

// Not equal: opposite of equal
bool Complex::operator!=(const Complex &other) const {
    return !(*this == other);  // Use the == operator and negate it
}

// ============================================================================
// STREAM OPERATORS (must be friend functions)
// ============================================================================

// Output operator: allows cout << complexNumber
// Displays as: a + bi or a - bi
ostream& operator<<(ostream &out, const Complex &c) {
    // Display real part
    out << c.real;
    
    // Display imaginary part with proper sign
    if (c.imaginary >= 0) {
        out << " + " << c.imaginary << "i";
    } else {
        // If negative, the minus sign is already there
        out << " - " << (-c.imaginary) << "i";
    }
    
    return out;
}

// Input operator: allows cin >> complexNumber
// User enters: real imaginary (e.g., "3 4" means 3+4i)
istream& operator>>(istream &in, Complex &c) {
    cout << "Enter real part: ";
    in >> c.real;
    cout << "Enter imaginary part: ";
    in >> c.imaginary;
    return in;
}

// ============================================================================
// OTHER METHODS
// ============================================================================

// Conjugate: returns a - bi (flips sign of imaginary part)
// Example: conjugate of (3+4i) is (3-4i)
// Used in division and magnitude calculations
Complex Complex::conjugate() const {
    return Complex(this->real, -this->imaginary);
}

// Magnitude (absolute value): returns √(a² + b²)
// This is the distance from origin in complex plane
// Example: magnitude of (3+4i) is √(9+16) = 5
double Complex::magnitude() const {
    return sqrt((real * real) + (imaginary * imaginary));
}

// Display: prints in nice format
void Complex::display() const {
    cout << real;
    if (imaginary >= 0) {
        cout << " + " << imaginary << "i";
    } else {
        cout << " - " << (-imaginary) << "i";
    }
}