#ifndef TERMINAL_H
#define TERMINAL_H

#include <string>

// Color codes
enum Color {
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    YELLOW = 6,
    WHITE = 7,
    BRIGHT_BLACK = 8,
    BRIGHT_BLUE = 9,
    BRIGHT_GREEN = 10,
    BRIGHT_CYAN = 11,
    BRIGHT_RED = 12,
    BRIGHT_MAGENTA = 13,
    BRIGHT_YELLOW = 14,
    BRIGHT_WHITE = 15
};

void setColor(Color color);
void moveCursor(int x, int y);
void clearScreen();
void resetColor();
void printAt(int x, int y, Color color, const std::string& text);

#endif