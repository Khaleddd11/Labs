#include "magicsquare.h"
#include "terminal.h"
#include <iostream>

// Include OS-specific headers at the top
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

using namespace std;

int main() {
    bool running = true;
    
    while (running) {
        // Get number from user
        int n = getNumberInput();
        
        // If valid number, create magic square
        if (n > 0) {
            createMagicSquare(n);
        }
        
        // If user pressed ESC or backspace on empty input (-2), exit
        if (n == -2) {
            running = false;
        }
        
        // If error (-1), loop continues and asks again
    }
    
    // Goodbye message
    clearScreen();
    printAt(35, 12, GREEN, "Goodbye!");
    
    // Cross-platform sleep
    #ifdef _WIN32
        Sleep(1000);
    #else
        sleep(1);
    #endif
    
    clearScreen();
    return 0;
}