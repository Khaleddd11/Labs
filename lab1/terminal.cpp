#include "terminal.h"
#include <iostream>

// Detect OS
#ifdef _WIN32  // If compiling on Windows
    #define OS_WINDOWS
    #include <windows.h>
#else
    #define OS_LINUX
    #include <unistd.h>
#endif

#ifdef OS_WINDOWS
void setColor(Color color) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);   // Get terminal handle
    SetConsoleTextAttribute(h, color);
}

void moveCursor(int x, int y) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(h, pos);
}

void clearScreen() {
    system("cls");
}
#endif

#ifdef OS_LINUX
void setColor(Color color) {
    // ANSI color codes for Linux
      // Convert Color enum to standard ANSI color code
    int ansiColor = 30 + (color % 8);
     // If color ≥ 8, it's a "bright" color → use bold style
    if (color >= 8) {
        std::cout << "\033[1;" << ansiColor << "m"; // bright color
    } else {
        std::cout << "\033[0;" << ansiColor << "m"; // normal color
    }
}


// Move terminal cursor to position (x, y)
// ANSI escape sequences are 1-based, so add +1
void moveCursor(int x, int y) {
    std::cout << "\033[" << (y + 1) << ";" << (x + 1) << "H";
}

// Clear screen and move cursor to top-left (0,0)
void clearScreen() {
    std::cout << "\033[2J\033[H";
}
#endif

void resetColor() {
#ifdef OS_WINDOWS
    setColor(WHITE); // Reset to white on Windows
#else
    std::cout << "\033[0m"; // ANSI reset code for Linux
#endif
}

void printAt(int x, int y, Color color, const std::string& text) {
    moveCursor(x, y);             // Move cursor to desired location
    setColor(color);              // Set text color
    std::cout << text;            // Print the actual text
    resetColor();                 // Reset to default color
    std::cout.flush();            // Force output to appear immediately