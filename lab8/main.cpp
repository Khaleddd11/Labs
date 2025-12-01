#include "Stack.h"
#include <iostream>

using namespace std;

// ============================================================================
// My own notes on shallow and deep copy: 
// Function to demonstrate shallow vs deep copy problem
// ============================================================================
void demonstrateShallowVsDeep() {
    cout << "\n========================================" << endl;
    cout << "  SHALLOW COPY vs DEEP COPY" << endl;
    cout << "========================================" << endl;
    
    cout << "\nWhat's the problem with SHALLOW COPY?" << endl;
    cout << "- If we just copy the pointer, both stacks point to SAME memory" << endl;
    cout << "- Changing one stack affects the other!" << endl;
    cout << "- When one is destroyed, the other has invalid pointer (CRASH!)" << endl;
    
    cout << "\nWhat's DEEP COPY?" << endl;
    cout << "- We create NEW memory and copy all values" << endl;
    cout << "- Each stack has its OWN independent memory" << endl;
    cout << "- Changes don't affect each other" << endl;
    cout << "- Safe destruction - no crashes!" << endl;
}

int main() {
    cout << "========================================" << endl;
    cout << "   STACK CLASS WITH DEEP COPY DEMO" << endl;
    cout << "========================================" << endl;
    
    // ========================================================================
    // 1. CREATE AND USE A STACK
    // ========================================================================
    cout << "\n--- Creating Stack s1 with capacity 5 ---" << endl;
    Stack s1(5);
    
    cout << "\n--- Pushing elements onto s1 ---" << endl;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.display();
    
    // ========================================================================
    // 2. CHECK STACK STATUS
    // ========================================================================
    cout << "\n--- Stack Status ---" << endl;
    cout << "Size: " << s1.size() << endl;
    cout << "Capacity: " << s1.getCapacity() << endl;
    cout << "Is Empty? " << (s1.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is Full? " << (s1.isFull() ? "Yes" : "No") << endl;
    
    // ========================================================================
    // 3. PEEK AND POP
    // ========================================================================
    cout << "\n--- Peek and Pop ---" << endl;
    cout << "Top element (peek): " << s1.peek() << endl;
    s1.pop();
    s1.display();
    
    // ========================================================================
    // 4. DEEP COPY USING COPY CONSTRUCTOR
    // ========================================================================
    cout << "\n--- Testing DEEP COPY (Copy Constructor) ---" << endl;
    cout << "Creating s2 as a copy of s1..." << endl;
    Stack s2 = s1;  // This calls copy constructor
    
    cout << "\nOriginal s1: ";
    s1.display();
    cout << "Copied s2: ";
    s2.display();
    
    // Modify s2 to prove they're independent
    cout << "\n--- Pushing 99 onto s2 only ---" << endl;
    s2.push(99);
    
    cout << "s1 after modifying s2: ";
    s1.display();
    cout << "s2 after modification: ";
    s2.display();
    cout << "\nNotice: s1 is UNCHANGED! This proves DEEP COPY works!" << endl;
    
    // ========================================================================
    // 5. DEEP COPY USING ASSIGNMENT OPERATOR
    // ========================================================================
    cout << "\n--- Testing DEEP COPY (Assignment Operator) ---" << endl;
    Stack s3(5);
    s3.push(100);
    s3.push(200);
    
    cout << "Before assignment:" << endl;
    cout << "s3: ";
    s3.display();
    cout << "s1: ";
    s1.display();
    
    cout << "\nAssigning s1 to s3 (s3 = s1)..." << endl;
    s3 = s1;  // This calls assignment operator
    
    cout << "After assignment:" << endl;
    cout << "s3: ";
    s3.display();
    cout << "s1: ";
    s1.display();
    
    // Modify s3 to prove independence
    cout << "\n--- Pushing 777 onto s3 only ---" << endl;
    s3.push(777);
    
    cout << "s1: ";
    s1.display();
    cout << "s3: ";
    s3.display();
    cout << "\nAgain, s1 is unchagned so  Deep copy works!" << endl;
    
    // ========================================================================
    // 6. TEST STACK OVERFLOW AND UNDERFLOW
    // ========================================================================
    cout << "\n--- Testing Stack Overflow ---" << endl;
    Stack s4(3);  // Small stack
    s4.push(1);
    s4.push(2);
    s4.push(3);
    s4.push(4);  // This should fail (overflow)
    
    cout << "\n--- Testing Stack Underflow ---" << endl;
    Stack s5(3);
    s5.pop();  // This should fail (underflow - empty stack)
    
    // ========================================================================
    // 7. CLEAR STACK
    // ========================================================================
    cout << "\n--- Testing Clear ---" << endl;
    s1.display();
    s1.clear();
    cout << "After clear: ";
    s1.display();
    
    // ========================================================================
    // EXPLAIN DEEP COPY CONCEPT
    // ========================================================================
    demonstrateShallowVsDeep();
    
    cout << "\n========================================" << endl;
    cout << "   END" << endl;
    cout << "Each stack's memory will be freed " << endl;
    
    return 0;
    // Destructors will be called here automatically for s1, s2, s3, s4, s5
}