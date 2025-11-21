#include "terminal.h"
#include "keyboard.h"
#include "employee.h"
#include <iostream>

// Include OS-specific headers at the top
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

using namespace std;

// ============================================================================
// Function: showMenu
// Purpose: Display the menu with highlighted selection
// ============================================================================
void showMenu(int selected) {
    clearScreen();
    
    // Title
    printAt(30, 4, BRIGHT_YELLOW, "EMPLOYEE MANAGEMENT SYSTEM");
    
    // Menu position
    int centerX = 35;
    int centerY = 9;
    
    // Option 0: New Employee
    if (selected == 0) {
        printAt(centerX, centerY, BLUE, "New Employee");
    } else {
        printAt(centerX, centerY, WHITE, "New Employee");
    }
    
    // Option 1: Display All
    if (selected == 1) {
        printAt(centerX, centerY + 2, BLUE, "Display All");
    } else {
        printAt(centerX, centerY + 2, WHITE, "Display All");
    }
    
    // Option 2: Exit
    if (selected == 2) {
        printAt(centerX, centerY + 4, BLUE, "Exit");
    } else {
        printAt(centerX, centerY + 4, WHITE, "Exit");
    }
    
    // Instructions
    printAt(25, centerY + 8, CYAN, "Use Arrow Keys (UP/DOWN/LEFT/RIGHT)");
    printAt(25, centerY + 9, CYAN, "Press ENTER to select");
}

// ============================================================================
// Main function
// ============================================================================
int main() {
    // Employee array and count
    Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;
    
    int selected = 0;  // Currently selected menu option
    bool running = true;
    
    while (running) {
        showMenu(selected);
        
        int key = getKey();
        
        // ===== NAVIGATION =====
        // DOWN or RIGHT: Move to next option
        if (key == KEY_DOWN || key == KEY_RIGHT) {
            selected++;
            if (selected > 2) {
                selected = 0;  // Wrap to top
            }
        }
        // UP or LEFT: Move to previous option
        else if (key == KEY_UP || key == KEY_LEFT) {
            selected--;
            if (selected < 0) {
                selected = 2;  // Wrap to bottom
            }
        }
        // HOME: Jump to first option
        else if (key == KEY_HOME) {
            selected = 0;
        }
        // END: Jump to last option
        else if (key == KEY_END) {
            selected = 2;
        }
        // ENTER: Select current option
        else if (key == KEY_ENTER) {
            if (selected == 0) {
                // New Employee
                addEmployee(employees, employeeCount);
            }
            else if (selected == 1) {
                // Display All
                displayAllEmployees(employees, employeeCount);
            }
            else if (selected == 2) {
                // Exit
                running = false;
            }
        }
        // ESC: Exit program
        else if (key == KEY_ESC) {
            running = false;
        }
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