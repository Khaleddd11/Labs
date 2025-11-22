#include "magicsquare.h"
#include "terminal.h"
#include "keyboard.h"
#include <iostream>
#include <string>

// Cross-platform sleep function
#ifdef _WIN32
    #include <windows.h>
    void mySleep(int milliseconds) {
        Sleep(milliseconds);
    }
#else
    #include <unistd.h>
    void mySleep(int milliseconds) {
        usleep(milliseconds * 1000);
    }
#endif

using namespace std;

// ============================================================================
// Function: getNumberInput
// Purpose: Get a valid odd number from the user for magic square size
// Returns: 
//   - Positive number (3-15) if valid odd number entered
//   - -1 if invalid input (even number, letters, etc.)
//   - -2 if user wants to exit (pressed ESC or backspace on empty)
// ============================================================================
int getNumberInput() {
    clearScreen();
    
    // Display instructions to user
    printAt(10, 5, YELLOW, "Enter an ODD number (3, 5, 7, 9, etc.):");
    printAt(10, 7, WHITE, "Size: ");
    
    string input = "";      // Store user's typed characters
    int cursorX = 16;       // X position where we display input
    
    while (true) {
        // Display current input with cursor
        printAt(cursorX, 7, BRIGHT_CYAN, input + "_");
        
        int key = getKey();
        
        // If Enter is pressed
        if (key == KEY_ENTER && input.length() > 0) {
            // Check if all characters are digits
            bool isValid = true;
            for (size_t i = 0; i < input.length(); i++) {
                if (input[i] < '0' || input[i] > '9') {
                    isValid = false;
                    break;
                }
            }
            
            // If not valid (contains non-digits)
            if (!isValid) {
                printAt(10, 9, RED, "Error: Please enter only numbers!");
                printAt(10, 10, YELLOW, "Press any key to try again...");
                getKey();
                return -1;
            }
            
            // Convert string to int using stoi (simple!)
            int num = stoi(input);
            
            // Validate the number
            if (num < 3) {
                printAt(10, 9, RED, "Error: Number must be at least 3!");
                printAt(10, 10, YELLOW, "Press any key to try again...");
                getKey();
                return -1;
            }
            
            if (num > 15) {
                printAt(10, 9, RED, "Error: Number too large (max 15)!");
                printAt(10, 10, YELLOW, "Press any key to try again...");
                getKey();
                return -1;
            }
            
            if (num % 2 == 0) {
                printAt(10, 9, RED, "Error: Number must be ODD!");
                printAt(10, 10, YELLOW, "Press any key to try again...");
                getKey();
                return -1;
            }
            
            return num; // Valid number
        }
        
        // If Backspace is pressed
        if (key == KEY_BACKSPACE) {
            if (input.length() > 0) {
                input = input.substr(0, input.length() - 1);
                printAt(cursorX, 7, WHITE, "                ");
            } else {
                return -2; // Return -2 to go back to menu
            }
        }
        
        // If ESC is pressed
        if (key == KEY_ESC) {
            return -2; // Go back to menu
        }
        
        // If a digit is pressed
        if (key >= '0' && key <= '9') {
            if (input.length() < 2) { // Limit to 2 digits
                input += (char)key;
            }
        }
    }
}

// Function to create and display magic square with animation
void createMagicSquare(int n) {
    clearScreen();
    
    // Create 2D array for magic square
    int square[15][15] = {0}; // Max size 15x15, initialized to 0
    
    // Display title
    printAt(10, 2, YELLOW, "Magic Square of size " + to_string(n) + "x" + to_string(n));
    printAt(10, 3, CYAN, "Watch the numbers appear one by one...");
    
    // Calculate starting position for displaying
    int startX = 15;
    int startY = 5;
    
    // Starting position for algorithm (middle of first row)
    int row = 0;
    int col = n / 2;
    
    // Fill the magic square using Siamese method with animation
    for (int num = 1; num <= n * n; num++) {
        // Place number in square array
        square[row][col] = num;
        
        // Display the number immediately with animation
        string numStr = to_string(num);
        
        // Add spacing for alignment
        if (num < 10) numStr = " " + numStr;
        if (num < 100) numStr = " " + numStr;
        
        // Show the number in bright green as it appears
        printAt(startX + col * 5, startY + row * 2, BRIGHT_GREEN, numStr);
        
        // Pause to show animation (200ms delay)
        mySleep(200);
        
        // Change color to cyan after placing
        printAt(startX + col * 5, startY + row * 2, CYAN, numStr);
        
        // Calculate next position
        int newRow = (row - 1 + n) % n;  // Move up (with wrap-around)
        int newCol = (col + 1) % n;       // Move right (with wrap-around)
        
        // If position is already filled, move down instead
        if (square[newRow][newCol] != 0) {
            newRow = (row + 1) % n;
            newCol = col;
        }
        
        // Update position for next number
        row = newRow;
        col = newCol;
    }
    
    // Calculate magic constant 
    // M = n × (n² + 1) / 2
    int magicConstant = (n * (n * n + 1)) / 2;
    
    printAt(10, startY + n * 2 + 2, GREEN, "Magic Constant (sum of any row/column/diagonal): " + to_string(magicConstant));
 
    
    // Instructions
    printAt(10, startY + n * 2 + 5, WHITE, "Press BACKSPACE to return to menu");
    
    // Wait for backspace
    while (true) {
        int key = getKey();
        if (key == KEY_BACKSPACE) {
            break;
        }
    }
}