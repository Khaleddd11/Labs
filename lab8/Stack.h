#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

// Stack Class
// A simple stack data structure (LIFO - Last In First Out)
// Like a stack of plates: you add on top and remove from top
// 
// Uses dynamic memory allocation (HEAP) with pointers
class Stack {
private:
    // Private member variables
    int *arr;       // Pointer to dynamic array (on HEAP)
    int top;        // Index of top element (-1 means empty)
    int capacity;   // Maximum size of stack
    
public:

    // CONSTRUCTORS AND DESTRUCTOR
    
    // Default constructor: creates empty stack with default size (10)
    Stack();
    
    // Parameterized constructor: creates empty stack with given size
    Stack(int size);
    
    // Copy constructor: creates DEEP COPY of another stack
    // This is important! Without it, we'd have shallow copy problems
    Stack(const Stack &other);
    
    // Destructor: frees memory when stack is destroyed
    // VERY IMPORTANT to prevent memory leaks!
    ~Stack();
    
    // ========================================================================
    // ASSIGNMENT OPERATOR (for deep copy)
    // ========================================================================
    
    // Copy assignment operator: stack1 = stack2
    // Also creates DEEP COPY to avoid sharing memory
    Stack& operator=(const Stack &other);
    
    // ========================================================================
    // STACK OPERATIONS
    // ========================================================================
    
    // Push: add element to top of stack
    // Returns: true if successful, false if stack is full
    bool push(int value);
    
    // Pop: remove and return top element
    // Returns: the popped value, or -1 if stack is empty
    int pop();
    
    // Peek: look at top element without removing it
    // Returns: top value, or -1 if empty
    int peek() const;
    
    // ========================================================================
    // UTILITY METHODS
    // ========================================================================
    
    // Check if stack is empty
    bool isEmpty() const;
    
    // Check if stack is full
    bool isFull() const;
    
    // Get current number of elements
    int size() const;
    
    // Get maximum capacity
    int getCapacity() const;
    
    // Display all elements (bottom to top)
    void display() const;
    
    // Clear the stack (remove all elements)
    void clear();
};

#endif