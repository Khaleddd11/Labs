#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

// ============================================================================
// Complex Class
// Represents a complex number: a + bi
// Where:
//   - a is the real part
//   - b is the imaginary part
//   - i is the imaginary unit (√-1)
// 
// Example: 3 + 4i means real=3, imaginary=4
// ============================================================================
class Complex {
private:
    // Private member variables (data)
    double real;       // Real part (a)
    double imaginary;  // Imaginary part (b)

public:
    // ========================================================================
    // CONSTRUCTORS
    // ========================================================================
    
    // Default constructor: creates 0 + 0i
    Complex();
    
    // Parameterized constructor: creates a + bi
    Complex(double r, double i);
    
    // ========================================================================
    // GETTERS (to read private data)
    // ========================================================================
    
    double getReal() const;
    double getImaginary() const;
    
    // ========================================================================
    // SETTERS (to modify private data)
    // ========================================================================
    
    void setReal(double r);
    void setImaginary(double i);
    
    // ========================================================================
    // ARITHMETIC OPERATOR OVERLOADING
    // Allows us to use +, -, *, / with Complex objects
    // ========================================================================
    
    // Addition: (a+bi) + (c+di) = (a+c) + (b+d)i
    Complex operator+(const Complex &other) const;
    
    // Subtraction: (a+bi) - (c+di) = (a-c) + (b-d)i
    Complex operator-(const Complex &other) const;
    
    // Multiplication: (a+bi) * (c+di) = (ac-bd) + (ad+bc)i
    Complex operator*(const Complex &other) const;
    
    // Division: (a+bi) / (c+di) = [(ac+bd) + (bc-ad)i] / (c²+d²)
    Complex operator/(const Complex &other) const;
    
    // ========================================================================
    // COMPARISON OPERATOR OVERLOADING
    // ========================================================================
    
    // Equal: checks if two complex numbers are equal
    bool operator==(const Complex &other) const;
    
    // Not equal
    bool operator!=(const Complex &other) const;
    
    // ========================================================================
    // STREAM OPERATOR OVERLOADING (for cout and cin)
    // Must be friend functions because they use cout/cin on the left side
    // ========================================================================
    
    // Output: allows cout << complexNumber
    // Displays as: a + bi or a - bi
    friend ostream& operator<<(ostream &out, const Complex &c);
    
    // Input: allows cin >> complexNumber
    // User enters: real imaginary (e.g., "3 4" for 3+4i)
    friend istream& operator>>(istream &in, Complex &c);
    
    // ========================================================================
    // OTHER USEFUL METHODS
    // ========================================================================
    
    // Conjugate: returns a - bi (flips sign of imaginary part)
    Complex conjugate() const;
    
    // Magnitude (absolute value): returns √(a² + b²)
    double magnitude() const;
    
    // Display in nice format
    void display() const;
};

#endif // COMPLEX_H