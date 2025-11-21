#include <iostream>
#include "swap.h"

using namespace std;

int main() {
    int x, y;
    
    // ===== XOR SWAP DEMO =====
    cout << "===== SWAP WITH XOR =====" << endl;
    x = 10;
    y = 25;
    cout << "Before: x = " << x << ", y = " << y << endl;
    
    swapXOR(x, y);
    
    cout << "After:  x = " << x << ", y = " << y << endl;
    cout << endl;
    
    // ===== ADDITION/SUBTRACTION SWAP DEMO =====
    cout << "===== SWAP WITH ADD/SUB =====" << endl;
    x = 100;
    y = 50;
    cout << "Before: x = " << x << ", y = " << y << endl;
    
    swapAddSub(x, y);
    
    cout << "After:  x = " << x << ", y = " << y << endl;
    
    return 0;
}