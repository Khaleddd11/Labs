#include "terminal.h"
#include <iostream>

// Detect OS
#ifdef _WIN32
    #define OS_WINDOWS
    #include <windows.h>
#else
    #define OS_LINUX
    #include <unistd.h>
#endif

#ifdef OS_WINDOWS
void setColor(Color color) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
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
   // ANSI base color index (30–37) → black to white
    int ansiColor = 30 + (color % 8);
    if (color >= 8) {
        std::cout << "\033[1;" << ansiColor << "m"; //bright
    } else {
        std::cout << "\033[0;" << ansiColor << "m"; //normal
    }
}

void moveCursor(int x, int y) {
    // +1 because terminal starts printing from 1 not 0 
     // \033[ ROW ; COLUMN H
    // \033 = ESC → tells terminal "special command coming"
    // H means move cursor to this position
    std::cout << "\033[" << (y + 1) << ";" << (x + 1) << "H";
}

void clearScreen() {
       // \033[2J  → clear entire screen
    // \033[H   → move cursor to top-left (0,0)
    std::cout << "\033[2J\033[H";
}
#endif

void resetColor() {
#ifdef OS_WINDOWS
    setColor(WHITE);
#else
    std::cout << "\033[0m";
#endif
}

void printAt(int x, int y, Color color, const std::string& text) {
    moveCursor(x, y);
    setColor(color);
    std::cout << text;
    resetColor();
    std::cout.flush();
}