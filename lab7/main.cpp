#include "Complex.h"
#include <iostream>

using namespace std;

int main() {
    cout << "======================================" << endl;
    cout << "   COMPLEX NUMBER CLASS DEMO" << endl;
    cout << "======================================" << endl << endl;
    
    // ========================================================================
    // 1. CREATE COMPLEX NUMBERS
    // ========================================================================
    cout << "--- Creating Complex Numbers ---" << endl;
    
    Complex c1(3, 4);      // 3 + 4i
    Complex c2(1, 2);      // 1 + 2i
    Complex c3;            // 0 + 0i (default constructor)
    
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c3 = " << c3 << endl << endl;
    
    // ========================================================================
    // 2. ADDITION
    // ========================================================================
    cout << "--- Addition ---" << endl;
    Complex sum = c1 + c2;  // Uses operator+
    cout << c1 << " + " << c2 << " = " << sum << endl << endl;
    
    // ========================================================================
    // 3. SUBTRACTION
    // ========================================================================
    cout << "--- Subtraction ---" << endl;
    Complex diff = c1 - c2;  // Uses operator-
    cout << c1 << " - " << c2 << " = " << diff << endl << endl;
    
    // ========================================================================
    // 4. MULTIPLICATION
    // ========================================================================
    cout << "--- Multiplication ---" << endl;
    Complex product = c1 * c2;  // Uses operator*
    cout << c1 << " * " << c2 << " = " << product << endl << endl;
    
    // ========================================================================
    // 5. DIVISION
    // ========================================================================
    cout << "--- Division ---" << endl;
    Complex quotient = c1 / c2;  // Uses operator/
    cout << c1 << " / " << c2 << " = " << quotient << endl << endl;
    

// Test compound assignment operators
cout << "\n--- Compound Assignment Operators ---" << endl;
Complex c5(5, 3);
Complex c6(2, 1);

cout << "c5 = " << c5 << endl;
cout << "c6 = " << c6 << endl;

c5 += c6;
cout << "After c5 += c6: " << c5 << endl;

c5 -= c6;
cout << "After c5 -= c6: " << c5 << endl;

c5 /= c6;
cout << "After c5 /= c6: " << c5 << endl;

// Test increment/decrement
cout << "\n--- Increment and Decrement ---" << endl;
Complex c7(3, 4);

cout << "c7 = " << c7 << endl;
cout << "++c7 = " << ++c7 << endl;
cout << "c7 after prefix++: " << c7 << endl;

cout << "\nc7++ = " << c7++ << endl;
cout << "c7 after postfix++: " << c7 << endl;

cout << "\n--c7 = " << --c7 << endl;
cout << "c7 after prefix--: " << c7 << endl;

cout << "\nc7-- = " << c7-- << endl;
cout << "c7 after postfix--: " << c7 << endl;

    // ========================================================================
    // 6. COMPARISON
    // ========================================================================
    cout << "--- Comparison ---" << endl;
    Complex c4(3, 4);  // Same as c1
    
    if (c1 == c4) {  // Uses operator==
        cout << c1 << " is EQUAL to " << c4 << endl;
    }
    
    if (c1 != c2) {  // Uses operator!=
        cout << c1 << " is NOT EQUAL to " << c2 << endl;
    }
    cout << endl;
cout<<"--- Testing operator[] ---"<<endl;
    Complex cc(9,12);
    cout<<cc[0]<<endl;
    cout<<cc[1]<<endl;
    cout<<cc[4]<<endl;
    
    // ========================================================================
    // 7. CONJUGATE
    // ========================================================================
    cout << "--- Conjugate ---" << endl;
    Complex conj = c1.conjugate();
    cout << "Conjugate of " << c1 << " is " << conj << endl << endl;
    
    // ========================================================================
    // 8. MAGNITUDE
    // ========================================================================
    cout << "--- Magnitude ---" << endl;
    double mag = c1.magnitude();
    cout << "Magnitude of " << c1 << " is " << mag << endl << endl;
    
    // ========================================================================
    // 9. GETTERS AND SETTERS
    // ========================================================================
    cout << "--- Getters and Setters ---" << endl;
    cout << "Real part of c1: " << c1.getReal() << endl;
    cout << "Imaginary part of c1: " << c1.getImaginary() << endl;
    
    c3.setReal(5);
    c3.setImaginary(6);
    cout << "After setting c3 to (5, 6): " << c3 << endl << endl;
    
    // ========================================================================
    // 10. USER INPUT (optional - uncomment to try)
    // ========================================================================
    /*
    cout << "--- User Input ---" << endl;
    Complex userComplex;
    cout << "Enter a complex number:" << endl;
    cin >> userComplex;  // Uses operator>>
    cout << "You entered: " << userComplex << endl << endl;
    */
    
    // ========================================================================
    // 11. CHAINING OPERATIONS
    // ========================================================================
    cout << "--- Chaining Operations ---" << endl;
    Complex result = (c1 + c2) * c4 - c2;
    cout << "(c1 + c2) * c4 - c2 = " << result << endl << endl;
    
    cout << "======================================" << endl;
    cout << "   END OF DEMO" << endl;
    cout << "======================================" << endl;
    
    return 0;
}