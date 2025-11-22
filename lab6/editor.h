#ifndef EDITOR_H
#define EDITOR_H

#include <string>

using namespace std;

// ============================================================================
// Editor Structure
// Holds all information about the text being edited
// ============================================================================
struct Editor {
    char *text;      // Pointer to text buffer in HEAP memory
    int size;        // Maximum size of buffer (user defined)
    int length;      // Current length of text (how many chars written)
    int cursor;      // Current cursor position (0 to length)
};

// ============================================================================
// Function Declarations
// ============================================================================

// Create a new editor with given buffer size
// Allocates memory on HEAP using 'new'
// Returns: pointer to Editor struct
Editor* createEditor(int size);

// Free the editor memory (both text buffer and struct)
// IMPORTANT: Always call this when done to avoid memory leaks!
void destroyEditor(Editor *editor);

// Main editing function - lets user type and edit text
// Handles arrow keys, backspace, typing, etc.
void editText(Editor *editor);

// Display the editor buffer on screen with cursor
void displayEditor(Editor *editor, int startY);

// Save text to a file
// Returns: true if saved successfully, false otherwise
bool saveToFile(Editor *editor);

// Load and display a file on screen
void displayFile();

#endif