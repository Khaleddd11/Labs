#include "terminal.h"
#include "keyboard.h"
#include "editor.h"
#include <iostream>
#include <sstream>
#include <unistd.h>

using namespace std;

// Helper to convert int to string
string intToString(int n) {
    stringstream ss;
    ss << n;
    return ss.str();
}

// ============================================================================
// GET BUFFER SIZE
// Asks user how big the text buffer should be
// ============================================================================
int getBufferSize() {
    clearScreen();
    
    printAt(5, 3, BRIGHT_YELLOW, "===== NEW TEXT =====");
    printAt(5, 6, WHITE, "How many characters do you want to write?");
    printAt(5, 7, CYAN, "(Enter a number between 10 and 200)");
    printAt(5, 9, WHITE, "Size: ");
    
    string input = "";
    int cursorX = 11;
    
    while (true) {
        printAt(cursorX, 9, BRIGHT_CYAN, input + "_");
        printAt(cursorX + input.length() + 1, 9, WHITE, "    ");
        
        int key = getKey();
        
        // ENTER - done
        if (key == KEY_ENTER && input.length() > 0) {
            // Convert to number
            int size = 0;
            for (size_t i = 0; i < input.length(); i++) {
                size = size * 10 + (input[i] - '0');
            }
            
            // Validate
            if (size < 10) {
                printAt(5, 11, RED, "Too small! Minimum is 10.");
                printAt(5, 12, YELLOW, "Press any key...");
                getKey();
                input = "";
                printAt(5, 11, WHITE, "                              ");
                printAt(5, 12, WHITE, "                              ");
                continue;
            }
            if (size > 200) {
                printAt(5, 11, RED, "Too large! Maximum is 200.");
                printAt(5, 12, YELLOW, "Press any key...");
                getKey();
                input = "";
                printAt(5, 11, WHITE, "                              ");
                printAt(5, 12, WHITE, "                              ");
                continue;
            }
            
            return size;
        }
        
        // ESC - cancel
        if (key == KEY_ESC) {
            return -1;
        }
        
        // BACKSPACE
        if (key == KEY_BACKSPACE && input.length() > 0) {
            input = input.substr(0, input.length() - 1);
        }
        
        // Digits only
        if (key >= '0' && key <= '9') {
            if (input.length() < 3) {
                input += (char)key;
            }
        }
    }
}

// ============================================================================
// ASK SAVE
// Asks user if they want to save or cancel
// Returns: true if user wants to save, false if cancel
// ============================================================================
bool askSave() {
    printAt(5, 15, WHITE, "----------------------------------------");
    printAt(5, 17, YELLOW, "Do you want to save?");
    printAt(5, 19, WHITE, "1. Save to file");
    printAt(5, 20, WHITE, "2. Discard and cancel");
    printAt(5, 22, CYAN, "Choose (1/2): ");
    
    while (true) {
        int key = getKey();
        if (key == '1') {
            return true;
        }
        if (key == '2' || key == KEY_ESC) {
            return false;
        }
    }
}

// ============================================================================
// NEW TEXT HANDLER
// Creates editor, lets user type, then asks to save
// ============================================================================
void handleNew() {
    // Step 1: Ask for buffer size
    int size = getBufferSize();
    
    // User cancelled
    if (size < 0) {
        return;
    }
    
    // Step 2: Create editor on HEAP
    // This allocates memory using 'new'
    Editor *editor = createEditor(size);
    
    // Step 3: Let user edit
    editText(editor);
    
    // Step 4: Ask if user wants to save
    if (editor->length > 0) {
        if (askSave()) {
            saveToFile(editor);
        } else {
            printAt(5, 24, RED, "Discarded.");
            printAt(5, 26, WHITE, "Press any key...");
            getKey();
        }
    } else {
        printAt(5, 17, YELLOW, "Nothing to save (empty text).");
        printAt(5, 19, WHITE, "Press any key...");
        getKey();
    }
    
    // Step 5: FREE THE MEMORY!
    // Very important - prevents memory leaks
    destroyEditor(editor);
}

// ============================================================================
// SHOW MENU
// Displays the main menu with highlighted selection
// ============================================================================
void showMenu(int selected) {
    clearScreen();
    
    // Title
    printAt(25, 3, BRIGHT_YELLOW, "===== VI-LIKE TEXT EDITOR =====");
    
    int centerX = 35;
    int centerY = 8;
    
    // Option 0: New
    if (selected == 0) {
        printAt(centerX, centerY, BLUE, "New");
    } else {
        printAt(centerX, centerY, WHITE, "New");
    }
    
    // Option 1: Display
    if (selected == 1) {
        printAt(centerX, centerY + 2, BLUE, "Display");
    } else {
        printAt(centerX, centerY + 2, WHITE, "Display");
    }
    
    // Option 2: Exit
    if (selected == 2) {
        printAt(centerX, centerY + 4, BLUE, "Exit");
    } else {
        printAt(centerX, centerY + 4, WHITE, "Exit");
    }
    
    // Instructions
    printAt(25, centerY + 8, CYAN, "Use Arrow Keys to navigate");
    printAt(25, centerY + 9, CYAN, "Press ENTER to select");
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================
int main() {
    int selected = 0;
    bool running = true;
    
    while (running) {
        showMenu(selected);
        
        int key = getKey();
        
        // Navigation
        if (key == KEY_DOWN || key == KEY_RIGHT) {
            selected++;
            if (selected > 2) selected = 0;
        }
        else if (key == KEY_UP || key == KEY_LEFT) {
            selected--;
            if (selected < 0) selected = 2;
        }
        else if (key == KEY_HOME) {
            selected = 0;
        }
        else if (key == KEY_END) {
            selected = 2;
        }
        else if (key == KEY_ENTER) {
            if (selected == 0) {
                handleNew();       // New text
            }
            else if (selected == 1) {
                displayFile();     // Display file
            }
            else if (selected == 2) {
                running = false;   // Exit
            }
        }
        else if (key == KEY_ESC) {
            running = false;
        }
    }
    
    clearScreen();
    printAt(30, 12, GREEN, "Goodbye!");
    
    // Small delay
    usleep(1000000);
    
    clearScreen();
    return 0;
}