#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

// Template Stack class
// Can work with any type: int, double, string, Complex, etc.
// we just put the type in angle brackets: Stack<int>, Stack<string>
template <typename T>
class Stack {
private:
    T* data;          // pointer to array on heap
    int capacity;     // max size
    int top;          // index of top element (-1 = empty)
    
public:
    // Constructor: create empty stack with given size
    Stack(int size = 10);
    
    // Copy constructor: deep copy
    Stack(const Stack& other);
    
    // Destructor: free memory
    ~Stack();
    
    // Assignment operator: deep copy
    Stack& operator=(const Stack& other);
    
    // Push: add element to top
    void push(T value);
    
    // Pop: remove and return top element
    T pop();
    
    // Peek: look at top without removing
    T peek() const;
    
    // Check if empty
    bool isEmpty() const;
    
    // Check if full
    bool isFull() const;
    
    // Get current size
    int size() const;
    
    // Display all elements
    void display() const;
    
    // Clear stack
    void clear();
};

// For templates, we put implementation in same file!
// Or include the .cpp at end of .h
// This is because compiler needs to see the code when instantiating templates


// IMPLEMENTATION

// Constructor
template <typename T>
Stack<T>::Stack(int size) {
    capacity = size;
    top = -1;
    data = new T[capacity];
}

// Copy constructor - deep copy
template <typename T>
Stack<T>::Stack(const Stack& other) {
    capacity = other.capacity;
    top = other.top;
    data = new T[capacity];
    
    // copy all elements
    for (int i = 0; i <= top; i++) {
        data[i] = other.data[i];
    }
}

// Destructor
template <typename T>
Stack<T>::~Stack() {
    delete[] data;
}

// Assignment operator - deep copy
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
    // check self-assignment
    if (this == &other) {
        return *this;
    }
    
    // free old memory
    delete[] data;
    
    // copy from other
    capacity = other.capacity;
    top = other.top;
    data = new T[capacity];
    
    for (int i = 0; i <= top; i++) {
        data[i] = other.data[i];
    }
    
    return *this;
}

// Push element
template <typename T>
void Stack<T>::push(T value) {
    if (isFull()) {
        cout << "Stack overflow! Cannot push." << endl;
        return;
    }
    
    top++;
    data[top] = value;
}

// Pop element
template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        cout << "Stack underflow! Cannot pop." << endl;
        // return default value (0 for numbers, empty for strings)
        return T();
    }
    
    T value = data[top];
    top--;
    return value;
}

// Peek at top
template <typename T>
T Stack<T>::peek() const {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return T();
    }
    return data[top];
}

// Check if empty
template <typename T>
bool Stack<T>::isEmpty() const {
    return (top == -1);
}

// Check if full
template <typename T>
bool Stack<T>::isFull() const {
    return (top == capacity - 1);
}

// Get size
template <typename T>
int Stack<T>::size() const {
    return top + 1;
}

// Display all elements
template <typename T>
void Stack<T>::display() const {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }
    
    cout << "Stack (bottom to top): ";
    for (int i = 0; i <= top; i++) {
        cout << data[i];
        if (i < top) cout << " -> ";
    }
    cout << " [TOP]" << endl;
}

// Clear stack
template <typename T>
void Stack<T>::clear() {
    top = -1;
}

#endif