#include "editor.h"
#include "terminal.h"
#include "keyboard.h"
#include <iostream>
#include <fstream> // file read/write
#include <sstream>

using namespace std;

// ============================================================================
// Helper: Convert int to string
// Because printAt() expects a string
// ============================================================================
string numToStr(int num) {
    stringstream ss; // here we create a stringstrem object
    ss << num; //then we put the num inside the object 
    return ss.str(); //.str() extracts everything inside the stringstream as a string.
}

// ============================================================================
// Helper: Get string input from user (for filename)
// ============================================================================
string getInput(int x, int y, int maxLen) {
    string input = "";
    
    while (true) {
        // It prints what the user typed so far + _ cursor and wait for  a key 
        printAt(x, y, BRIGHT_CYAN, input + "_"); 
        // Clear any leftover characters on the right
        // This prevents old letters from staying visible when user deletes
        // 'x + input.length() + 1' moves the cursor past the "_"
        printAt(x + input.length() + 1, y, WHITE, "          ");
        
        int key = getKey();
        
        // ENTER - done
        if (key == KEY_ENTER && input.length() > 0) {
            return input;  // return the final string
        }
        
        // BACKSPACE - delete last char
        if (key == KEY_BACKSPACE && input.length() > 0) {
            input = input.substr(0, input.length() - 1);
        }
        
        // ESC - cancel
        if (key == KEY_ESC) {
            return "";
        }
        
        // Accept only allowed characters
        if ((key >= 'a' && key <= 'z') ||
            (key >= 'A' && key <= 'Z') ||
            (key >= '0' && key <= '9') ||
            key == '.' || key == '_' || key == '-') {
                // Limit input length to maxLen
            if ((int)input.length() < maxLen) {
                input += (char)key; // add new character to input
            }
        }
    }
}


// Helper: Get number input from user (for buffer size)
int getNumberInput(int x, int y) {
    string input = "";
    
    while (true) {
        printAt(x, y, BRIGHT_CYAN, input + "_");
        printAt(x + input.length() + 1, y, WHITE, "     ");
        
        int key = getKey();
        
        // ENTER - convert and return
        if (key == KEY_ENTER && input.length() > 0) {
            int num = 0; // Final converted number
            // Manual conversion from string → integer
            // Example: "123" → 123
            for (size_t i = 0; i < input.length(); i++) {
                // Multiply previous digits by 10 and add current digit
                num = num * 10 + (input[i] - '0');
            }
            return num;
        }
        
        // BACKSPACE
        if (key == KEY_BACKSPACE && input.length() > 0) {
            input = input.substr(0, input.length() - 1);
        }
        
        // ESC - cancel
        if (key == KEY_ESC) {
            return -1;
        }
        
        // Only digits
        if (key >= '0' && key <= '9') {
            if (input.length() < 4) {  // Max 9999
                input += (char)key;
            }
        }
    }
}

// ============================================================================
// CREATE EDITOR
// Allocates memory on the HEAP for the editor and its text buffer
// size is the maximum number of characters the editor can hold.
Editor* createEditor(int size) {
    // Step 1: Allocate Editor struct on HEAP
    // 'new' returns a pointer to heap memory
    Editor *editor = new Editor;
    
    // Step 2: Allocate text buffer on HEAP
    // This is where the actual text will be stored
    // We use size+1 to have room for null terminator
    editor->text = new char[size + 1];
    
    // Step 3: Initialize all values
    editor->size = size;      // Maximum characters allowed
    editor->length = 0;       // Currently empty (0 characters)
    editor->cursor = 0;  // position where the next character will appear (starts at 0).
    
    // Step 4: Fill buffer with null characters (empty)
    // Using pointer arithmetic to access each position
    for (int i = 0; i <= size; i++) {
        *(editor->text + i) = '\0'; 
    }
    
    return editor;  // Return pointer to the new editor
}

// ============================================================================
// DESTROY EDITOR
// Frees all HEAP memory to prevent memory leaks
// ============================================================================
void destroyEditor(Editor *editor) {
    // Check if editor exists
    if (editor == NULL) {
        return;
    }
    
    // Step 1: Free the text buffer first
    // Must delete[] because we used new[],
    if (editor->text != NULL) {
        delete[] editor->text;
    }
    
    // Step 2: Free the editor struct itself
    delete editor;
}

// ============================================================================
// DISPLAY EDITOR
// Shows the text buffer on screen with cursor position highlighted
// ============================================================================
void displayEditor(Editor *editor, int startY) {
    int startX = 5;
    
    // Draw border top
    printAt(startX, startY, WHITE, "+");
    for (int i = 0; i < editor->size + 2; i++) {
        printAt(startX + 1 + i, startY, WHITE, "-");
    }
    printAt(startX + editor->size + 3, startY, WHITE, "+");
    
    // Draw text area
    printAt(startX, startY + 1, WHITE, "| ");
    
    // Display each character using POINTER ARITHMETIC
    for (int i = 0; i < editor->size; i++) {
        // Get character at position i using pointer
        char ch = *(editor->text + i);  
        
        // Compare the current loop index 'i' with the stored cursor position.
        if (i == editor->cursor) {
            if (ch == '\0' || i >= editor->length) {
                /// Empty position (Cursor is at the end of the line) - show highlighted space.
                // Renders an underscore in bright green to indicate where the next character will go.
                printAt(startX + 2 + i, startY + 1, BRIGHT_GREEN, "_");
            } else {
                // Character at cursor position - highlight it.
                // Renders the character itself in bright green, indicating it's selected.
                string s(1, ch);
                printAt(startX + 2 + i, startY + 1, BRIGHT_GREEN, s);
            }
        } else {
            if (ch == '\0' || i >= editor->length) {
                // Empty position - show dot
                printAt(startX + 2 + i, startY + 1, BRIGHT_BLACK, ".");
            } else {
                // Normal character
                string s(1, ch);
                printAt(startX + 2 + i, startY + 1, CYAN, s);
            }
        }
    }
    
    printAt(startX + editor->size + 2, startY + 1, WHITE, " |");
    
    // Draw border bottom
    printAt(startX, startY + 2, WHITE, "+");
    for (int i = 0; i < editor->size + 2; i++) {
        printAt(startX + 1 + i, startY + 2, WHITE, "-");
    }
    printAt(startX + editor->size + 3, startY + 2, WHITE, "+");
    
    // Show info
    printAt(5, startY + 4, YELLOW, "Length: " + numToStr(editor->length) + "/" + numToStr(editor->size));
    printAt(5, startY + 5, YELLOW, "Cursor: " + numToStr(editor->cursor));
}

// ============================================================================
// EDIT TEXT
// Main editing loop - handles all keyboard input
// ============================================================================
void editText(Editor *editor) {
    clearScreen();
    
    printAt(5, 2, BRIGHT_YELLOW, "===== TEXT EDITOR =====");
    printAt(5, 4, WHITE, "Type to insert text. Use arrows to move cursor.");
    printAt(5, 5, WHITE, "Press ESC when done.");
    
    int editorY = 7;  // Where to draw the editor box
    
    while (true) {
        // Display current state
        displayEditor(editor, editorY);
        
        // Get key press
        int key = getKey();
        
        // ===== ESC - Exit editor =====
        if (key == KEY_ESC) {
            break;
        }
        
        // ===== LEFT ARROW - Move cursor left =====
        if (key == KEY_LEFT) {
            if (editor->cursor > 0) {
                editor->cursor--;
            }
        }
        
        // ===== RIGHT ARROW - Move cursor right =====
        if (key == KEY_RIGHT) {
            if (editor->cursor < editor->length) {
                editor->cursor++;
            }
        }
        
        // ===== HOME - Go to beginning =====
        if (key == KEY_HOME) {
            editor->cursor = 0;
        }
        
        // ===== END - Go to end of text =====
        if (key == KEY_END) {
            editor->cursor = editor->length;
        }
        
        // ===== BACKSPACE - Delete character before cursor =====
        if (key == KEY_BACKSPACE) {
            if (editor->cursor > 0 && editor->length > 0) {
                // Shift all characters after cursor one position left
                // Using POINTER ARITHMETIC
                for (int i = editor->cursor - 1; i < editor->length - 1; i++) {
                    // Copy character from position i+1 to position i
                    *(editor->text + i) = *(editor->text + i + 1);
                }
                
                // Clear the last character
                *(editor->text + editor->length - 1) = '\0';
                
                // Update length and cursor
                editor->length--;
                editor->cursor--;
            }
        }
        
        // DELETE KEY  i use  'd' for simplicity
        // Deletes character at cursor position
        
        // Insert at cursor
        // Check if it's a printable ASCII character (space to ~)
        if (key >= 32 && key <= 126) {
            // here we make sure we haven't filled the entire memory block yet.
            if (editor->length < editor->size) {
        // here we do the shhifting first 
        // This loop moves characters to the right to create a "gap" for the new one.
        // It starts at the very end of the string and works BACKWARDS to the cursor.
        // NOTE: If inserting at the end, (length == cursor), this loop does NOT run.
                for (int i = editor->length; i > editor->cursor; i--) {
                    // Copy the character from the left (i-1) to the current spot (i)
                    *(editor->text + i) = *(editor->text + i - 1);
                }
                
        // here we insert 
        // Write the new character into the gap we just created (or at the end).
        // 'text + cursor' points to the specific memory slot.
                *(editor->text + editor->cursor) = (char)key;
                
                // Update length and move cursor forward
                editor->length++;
                editor->cursor++;
            }
        }
    }
}

// Saves the text buffer to a file using fstream
bool saveToFile(Editor *editor) {
    clearScreen();
    
    printAt(5, 3, BRIGHT_YELLOW, "===== SAVE FILE =====");
    
    // Step 1: Ask for filename
    printAt(5, 6, WHITE, "Enter filename: ");
    string filename = getInput(21, 6, 20);
    
    if (filename == "") {
        printAt(5, 8, RED, "Cancelled.");
        printAt(5, 10, WHITE, "Press any key...");
        getKey();
        return false;
    }
    
    // Step 2: Check if file exists
// Use ifstream (Input File Stream) only to attempt opening the file for reading.
// If successful, the file exists.

// EXPLANATION OF .c_str():
        // 1. 'filename' is a std::string (a smart C++ object).
        // 2. 'open()' in older C++ versions expects a raw C-style string pointer (char*).
        // 3. .c_str() returns a read-only pointer to the underlying character array in memory.
        // It acts as a bridge: Smart Object -> Raw Memory Address.
    ifstream checkFile(filename.c_str());
    bool fileExists = checkFile.good();
    checkFile.close();
    
    // Step 3: If file exists, ask user what to do
    int writeMode = 0;  // 0 = overwrite, 1 = append
    
    if (fileExists) {
        printAt(5, 8, YELLOW, "File already exists!");
        printAt(5, 10, WHITE, "1. Overwrite");
        printAt(5, 11, WHITE, "2. Append");
        printAt(5, 12, WHITE, "3. Cancel");
        printAt(5, 14, CYAN, "Choose (1/2/3): ");
        
        while (true) {
            // Wait for valid user input
            int key = getKey();
            if (key == '1') {
                writeMode = 0; // Choose Overwrite mode
                break;
            } else if (key == '2') {
                writeMode = 1; // Choose Append mode
                break;
            } else if (key == '3' || key == KEY_ESC) {
                // Cancel operation and exit function
                printAt(5, 16, RED, "Cancelled.");
                printAt(5, 18, WHITE, "Press any key...");
                getKey();
                return false; // Function returns failure
            }
        }
    }
    
    // Step 4: Open file and write
    ofstream file; // Output File Stream (for writing)
    
    if (writeMode == 0) {
        // Overwrite mode - creates new or overwrites existing
        // Overwrite mode: file.open() default behavior is to TRUNCATE (erase) the file.
        file.open(filename.c_str());
    } else {
        // Append mode - add to end of file
        // Append mode: Use ios::app flag to position the cursor at the end of the file.
        // 1. 'ios' (Input Output Stream): The base class that holds file settings.
        // 2. '::' (Scope Resolution Operator): Tells the compiler "Look INSIDE the 
        //    ios class to find the definition of 'app'".
        // 3. 'app' (Append): A specific flag bit.
        file.open(filename.c_str(), ios::app);
    }
    
    // Check if file opened successfully
    if (!file.is_open()) {
        printAt(5, 16, RED, "Error: Could not open file!");
        printAt(5, 18, WHITE, "Press any key...");
        getKey();
        return false;
    }
    
    // Step 5: Write text to file using POINTER
    // Loop through each character in buffer
    for (int i = 0; i < editor->length; i++) {
        char ch = *(editor->text + i);  // Get char using pointer

        // Write the character to the output stream (file).
        file << ch;                      // Write to file
    }
    file << endl;  // Add newline at end so file ends properly.
    
    // Step 6: Close file
    file.close();
    
    // Success message
    printAt(5, 16, GREEN, "File saved successfully!");
    printAt(5, 17, CYAN, "Filename: " + filename);
    printAt(5, 19, WHITE, "Press any key...");
    getKey();
    
    return true;
}

// ============================================================================
// DISPLAY FILE
// Loads and displays contents of a file
// ============================================================================
void displayFile() {
    clearScreen();
    
    printAt(5, 3, BRIGHT_YELLOW, "===== DISPLAY FILE =====");
    
    // Ask for filename
    printAt(5, 6, WHITE, "Enter filename: ");
    string filename = getInput(21, 6, 20);
    
    if (filename == "") {
        printAt(5, 8, RED, "Cancelled.");
        printAt(5, 10, WHITE, "Press any key...");
        getKey();
        return;
    }
    
    // Try to open file
    ifstream file(filename.c_str());
    
    if (!file.is_open()) {
        printAt(5, 8, RED, "Error: File not found!");
        printAt(5, 10, WHITE, "Press any key...");
        getKey();
        return;
    }
    
    // Display file contents
    printAt(5, 8, CYAN, "Contents of: " + filename);
    printAt(5, 9, WHITE, "----------------------------------------");
    
    string line;
    int y = 10;
    
    while (getline(file, line)) {
        printAt(5, y, WHITE, line);
        y++;
        
        // Pagination if too many lines
        if (y > 20) {
            printAt(5, y, YELLOW, "Press any key for more...");
            getKey();
            clearScreen();
            printAt(5, 3, BRIGHT_YELLOW, "===== DISPLAY FILE (continued) =====");
            y = 5;
        }
    }
    
    file.close();
    
    printAt(5, y + 1, WHITE, "----------------------------------------");
    printAt(5, y + 2, GREEN, "End of file.");
    printAt(5, y + 4, WHITE, "Press any key...");
    getKey();
}