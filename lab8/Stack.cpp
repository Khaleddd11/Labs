#include "Stack.h"
#include <iostream>

using namespace std;

// ============================================================================
// CONSTRUCTORS AND DESTRUCTOR
// ============================================================================

// Default constructor: creates stack with capacity 10
Stack::Stack() {
    capacity = 10;
    arr = new int[capacity];  // Allocate memory on HEAP
    top = -1;                  // Empty stack (no elements)
    
    cout << "[Constructor] Stack created with capacity " << capacity << endl;
}

// Parameterized constructor: creates stack with given capacity
Stack::Stack(int size) {
    capacity = size;
    arr = new int[capacity];  // Allocate memory on HEAP
    top = -1;                  // Empty stack
    
    cout << "[Constructor] Stack created with capacity " << capacity << endl;
}

// Copy constructor: creates DEEP COPY of another stack
// DEEP COPY means we create a NEW array and copy all values
// This prevents two stacks from sharing the same memory
Stack::Stack(const Stack &other) {
    // Copy capacity and top
    capacity = other.capacity;
    top = other.top;
    
    // Allocate NEW memory (this is the "deep" part)
    arr = new int[capacity];
    
    // Copy all elements from other stack to this stack
    for (int i = 0; i <= top; i++) {
        arr[i] = other.arr[i];
    }
    
    cout << "[Copy Constructor] Deep copy created" << endl;
}

// Destructor: frees the memory when stack is destroyeddddd
Stack::~Stack() {
    delete[] arr;  // Free the HEAP memory
    cout << "[Destructor] Stack destroyed, memory freed" << endl;
}

// ASSIGNMENT OPERATOR (for deep copy)

// Copy assignment operator: allows stack1 = stack2
// Also does DEEP COPY to avoid memory sharing problems
Stack& Stack::operator=(const Stack &other) {
    // Check for self-assignment (stack1 = stack1)
    if (this == &other) {
        return *this;  // Do nothing
    }
    
    // Step 1: Free old memory
    delete[] arr;
    
    // Step 2: Copy size information
    capacity = other.capacity;
    top = other.top;
    
    // Step 3: Allocate NEW memory
    arr = new int[capacity];
    
    // Step 4: Copy all elements
    for (int i = 0; i <= top; i++) {
        arr[i] = other.arr[i];
    }
    
    cout << "[Assignment Operator] Deep copy assigned" << endl;
    
    return *this;  // Return reference to this object
}

// ============================================================================
// STACK OPERATIONS
// ============================================================================

// Push: add element to top of stack
bool Stack::push(int value) {
    // Check if stack is full
    if (isFull()) {
        cout << "Stack Overflow! Cannot push " << value << endl;
        return false;
    }
    
    // Increment top and add element
    top++;
    arr[top] = value;
    
    cout << "Pushed: " << value << endl;
    return true;
}

// Pop: remove and return top element
int Stack::pop() {
    // Check if stack is empty
    if (isEmpty()) {
        cout << "Stack Underflow! Cannot pop from empty stack" << endl;
        return -1;
    }
    
    // Get top element and decrement top
    int value = arr[top];
    top--;
    
    cout << "Popped: " << value << endl;
    return value;
}

// Peek: look at top element without removing
int Stack::peek() const {
    // Check if stack is empty
    if (isEmpty()) {
        cout << "Stack is empty! Nothing to peek" << endl;
        return -1;
    }
    
    return arr[top];
}

// UTILITY METHODS

// Check if stack is empty
bool Stack::isEmpty() const {
    return (top == -1);
}

// Check if stack is full
bool Stack::isFull() const {
    return (top == capacity - 1);
}

// Get current number of elements
int Stack::size() const {
    return (top + 1);
}

// Get maximum capacity
int Stack::getCapacity() const {
    return capacity;
}

// Display all elements from bottom to top
void Stack::display() const {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }
    
    cout << "Stack contents (bottom to top): ";
    for (int i = 0; i <= top; i++) {
        cout << arr[i];
        if (i < top) {
            cout << " -> ";
        }
    }
    cout << " [TOP]" << endl;
}

// Clear the stack (remove all elements)
void Stack::clear() {
    top = -1;  // Reset top to -1 (empty)
    cout << "Stack cleared" << endl;
}