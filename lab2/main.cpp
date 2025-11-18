#include "terminal.h"
#include "keyboard.h"
#include <iostream>


/*
* ===================== MAIN MENU SYSTEM =====================
* This program creates a simple text-based UI menu using:
* - Cursor movement and colored text (terminal.h)
* - Instant keyboard input (keyboard.h)
* The user can navigate using Up/Down arrows and select an option.
* Each screen waits for BACKSPACE to return to the main menu.
*/


// Draw the main menu with the currently selected item highlighted
void showMenu(int selected) {
    clearScreen(); // Clear old frame before drawing
    
    // Calculate middle of screen (assume 80x25 terminal)
    int centerX = 35;
    int centerY = 10;
    
    // Display menu options
    // Draw "New"
    if (selected == 0) {
        printAt(centerX, centerY, BLUE, "New"); // Highlighted
    } else {
        printAt(centerX, centerY, WHITE, "New");
    }
    // Draw "Display"
    if (selected == 1) {
        printAt(centerX, centerY + 2, BLUE, "Display");
    } else {
        printAt(centerX, centerY + 2, WHITE, "Display");
    }
    // Draw "Exit"
    if (selected == 2) {
        printAt(centerX, centerY + 4, BLUE, "Exit");
    } else {
        printAt(centerX, centerY + 4, WHITE, "Exit");
    }
}


// Screen shown when the user selects "New"
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