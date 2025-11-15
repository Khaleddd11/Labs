#include "terminal.h"
#include "keyboard.h"
#include <iostream>

void showMenu(int selected) {
    clearScreen();
    
    // Calculate middle of screen (assume 80x25 terminal)
    int centerX = 35;
    int centerY = 10;
    
    // Display menu options
    if (selected == 0) {
        printAt(centerX, centerY, BLUE, "New");
    } else {
        printAt(centerX, centerY, WHITE, "New");
    }
    
    if (selected == 1) {
        printAt(centerX, centerY + 2, BLUE, "Display");
    } else {
        printAt(centerX, centerY + 2, WHITE, "Display");
    }
    
    if (selected == 2) {
        printAt(centerX, centerY + 4, BLUE, "Exit");
    } else {
        printAt(centerX, centerY + 4, WHITE, "Exit");
    }
}

void newScreen() {
    clearScreen();
    printAt(10, 5, GREEN, "You are in NEW section");
    printAt(10, 7, YELLOW, "Press BACKSPACE to go back to menu");
    
    while (true) {
        int key = getKey();
        if (key == KEY_BACKSPACE) {
            break;
        }
    }
}

void displayScreen() {
    clearScreen();
    printAt(10, 5, GREEN, "You are in DISPLAY section");
    printAt(10, 7, YELLOW, "Press BACKSPACE to go back to menu");
    
    while (true) {
        int key = getKey();
        if (key == KEY_BACKSPACE) {
            break;
        }
    }
}

int main() {
    int selected = 0; // 0 = New, 1 = Display, 2 = Exit
    bool running = true;
    
    while (running) {
        showMenu(selected);
        
        int key = getKey();
        
        if (key == KEY_DOWN) {
            selected++;
            if (selected > 2) {
                selected = 0; // Wrap around to top
            }
        }
        else if (key == KEY_UP) {
            selected--;
            if (selected < 0) {
                selected = 2; // Wrap around to bottom
            }
        }
        else if (key == KEY_HOME) {
            selected = 0; // Go to first option
        }
        else if (key == KEY_END) {
            selected = 2; // Go to last option
        }
        else if (key == KEY_ENTER) {
            if (selected == 0) {
                newScreen();
            }
            else if (selected == 1) {
                displayScreen();
            }
            else if (selected == 2) {
                running = false; // Exit program
            }
        }
        else if (key == KEY_ESC) {
            running = false; // Exit on ESC
        }
    }
    
    clearScreen();
    return 0;
}