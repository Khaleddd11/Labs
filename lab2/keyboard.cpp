#include "keyboard.h"
#include <stdio.h>

#ifdef _WIN32
    #include <conio.h>
    
    int getKey() {
        int ch = _getch();
        
        // Check if it's an extended key (2 bytes on Windows)
        if (ch == 0 || ch == 224) {
            ch = _getch(); // Get the second byte
        }
        
        return ch;
    }
    
#else
    #include <termios.h>
    #include <unistd.h>
    
    int getKey() {
        struct termios oldt, newt;
        int ch;
        
        // Disable buffering and echo
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        
        ch = getchar();
        
        // Check if it's an escape sequence (3 bytes on Linux)
        if (ch == 27) {
            ch = getchar();
            if (ch == 91) { // '[' character
                ch = getchar();
                // Convert Linux codes to match Windows codes
                if (ch == 65) ch = KEY_UP;      // Arrow up
                else if (ch == 66) ch = KEY_DOWN;   // Arrow down
                else if (ch == 67) ch = KEY_RIGHT;  // Arrow right
                else if (ch == 68) ch = KEY_LEFT;   // Arrow left
                else if (ch == 72) ch = KEY_HOME;   // Home
                else if (ch == 70) ch = KEY_END;    // End
            } else {
                ch = KEY_ESC; // Just ESC key
            }
        } else if (ch == 127) {
            ch = KEY_BACKSPACE; // Linux uses 127 for backspace
        } else if (ch == 10) {
            ch = KEY_ENTER; // Linux uses 10 for enter
        }
        
        // Restore terminal settings
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        
        return ch;
    }
    
#endif