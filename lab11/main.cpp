#include "Stack.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
        // 1. INTEGER STACK
    cout << "\n--- Integer Stack ---" << endl;
    
    Stack<int> intStack(5);  // stack of integers, capacity 5
    
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    intStack.display();
    
    cout << "Top element: " << intStack.peek() << endl;
    cout << "Size: " << intStack.size() << endl;
    
    int popped = intStack.pop();
    cout << "Popped: " << popped << endl;
    intStack.display();
    
    // ========================================================================
    // 2. DOUBLE STACK
    // ========================================================================
    cout << "\n--- Double Stack ---" << endl;
    
    Stack<double> doubleStack(5);  // stack of doubles
    
    doubleStack.push(3.14);
    doubleStack.push(2.71);
    doubleStack.push(1.41);
    doubleStack.display();
    
    double val = doubleStack.pop();
    cout << "Popped: " << val << endl;
    doubleStack.display();
    
    // ========================================================================
    // 3. STRING STACK
    // ========================================================================
    cout << "\n--- String Stack ---" << endl;
    
    Stack<string> stringStack(5);  // stack of strings
    
    stringStack.push("Hello");
    stringStack.push("World");
    stringStack.push("C++");
    stringStack.display();
    
    string word = stringStack.pop();
    cout << "Popped: " << word << endl;
    stringStack.display();
    
    // ========================================================================
    // 4. DEEP COPY TEST
    // ========================================================================
    cout << "\n--- Testing Deep Copy ---" << endl;
    
    Stack<int> s1(5);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    
    cout << "Original s1: ";
    s1.display();
    
    // copy constructor
    Stack<int> s2 = s1;
    cout << "Copied s2: ";
    s2.display();
    
    // modify s2
    s2.push(99);
    cout << "\nAfter pushing 99 to s2:" << endl;
    cout << "s1: ";
    s1.display();
    cout << "s2: ";
    s2.display();
    cout << "They are independent!" << endl;
    
    // ========================================================================
    // 5. ASSIGNMENT OPERATOR
    // ========================================================================
    cout << "\n--- Testing Assignment Operator ---" << endl;
    
    Stack<int> s3(5);
    s3.push(100);
    s3.push(200);
    
    cout << "Before assignment:" << endl;
    cout << "s3: ";
    s3.display();
    cout << "s1: ";
    s1.display();
    
    s3 = s1;  // assignment
    
    cout << "\nAfter s3 = s1:" << endl;
    cout << "s3: ";
    s3.display();
    cout << "s1: ";
    s1.display();
    
    // ========================================================================
    // 6. OVERFLOW AND UNDERFLOW
    // ========================================================================
    cout << "\n--- Testing Overflow ---" << endl;
    Stack<int> smallStack(3);
    smallStack.push(1);
    smallStack.push(2);
    smallStack.push(3);
    smallStack.push(4);  // overflow
    
    cout << "\n--- Testing Underflow ---" << endl;
    Stack<int> emptyStack(3);
    emptyStack.pop();  // underflow
    
    // ========================================================================
    // 7. CLEAR
    // ========================================================================
    cout << "\n--- Testing Clear ---" << endl;
    s1.display();
    s1.clear();
    cout << "After clear: ";
    s1.display();
    
    // ========================================================================
    // 8. CHARACTER STACK (bonus)
    // ========================================================================
    cout << "\n--- Character Stack ---" << endl;
    
    Stack<char> charStack(10);
    
    string text = "HELLO";
    cout << "Pushing characters from: " << text << endl;
    for (int i = 0; i < text.length(); i++) {
        charStack.push(text[i]);
    }
    
    charStack.display();
    
    cout << "Popping in reverse: ";
    while (!charStack.isEmpty()) {
        cout << charStack.pop();
    }
    cout << endl;
    
    cout << "\n=====================================" << endl;
    cout << "  End of Demo" << endl;
    cout << "=====================================" << endl;
    
    return 0;
}