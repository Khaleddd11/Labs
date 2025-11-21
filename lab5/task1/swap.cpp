#include "swap.h"

// ============================================================================
// Swap using XOR (exclusive OR)
// ============================================================================
void swapXOR(int &a, int &b) {
    // Example: a = 5 (binary: 0101), b = 3 (binary: 0011)
    
    a = a ^ b;  // a = 0101 ^ 0011 = 0110 (6)
    // Now: a = 6, b = 3
    
    b = a ^ b;  // b = 0110 ^ 0011 = 0101 (5) ← original a!
    // Now: a = 6, b = 5
    
    a = a ^ b;  // a = 0110 ^ 0101 = 0011 (3) ← original b!
    // Now: a = 3, b = 5 ← SWAPPED!
}

// ============================================================================
// Swap using Addition and Subtraction
// ============================================================================
void swapAddSub(int &a, int &b) {
    // Example: a = 5, b = 3
    
    a = a + b;  // a = 5 + 3 = 8 (holds sum)
    // Now: a = 8, b = 3
    
    b = a - b;  // b = 8 - 3 = 5 ← original a!
    // Now: a = 8, b = 5
    
    a = a - b;  // a = 8 - 5 = 3 ← original b!
    // Now: a = 3, b = 5 ← SWAPPED!
}