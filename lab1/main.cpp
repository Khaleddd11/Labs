#include "terminal.h"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    clearScreen();
    
    // Example usage
    printAt(10, 5, RED, "Hello from Red!");
    printAt(10, 7, GREEN, "Hello from Green!");
    printAt(10, 9, BLUE, "Hello from Blue!");
    printAt(10, 11, YELLOW, "Hello from Yellow!");
    printAt(10, 13, BRIGHT_CYAN, "Hello from Bright Cyan!");
    
    // Move cursor to bottom so it doesn't overlap
    moveCursor(0, 20);
    std::cout << std::endl;
    
    // Wait 5 seconds then clear screen
    std::this_thread::sleep_for(std::chrono::seconds(5));
    clearScreen();
    
    return 0;
}