#include "keyboard.h"
#include <stdio.h>

#ifdef _WIN32
    #include <conio.h>
    
    int getKey() {
        // If the key is "extended", Windows sends 2 bytes.
        // First byte is 0 or 224, second byte is the real code.
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
        
         /*
         * ====== IMPORTANT EXPLANATION ======
         * By default, Linux terminal is in "canonical mode":
         *   - It waits until ENTER is pressed before sending input.
         *   - It echoes (prints) what the user types.
         *
         * To read keys like arrows, ESC, Home, End, etc., we must:
         *   1. Turn OFF canonical mode  → get input instantly
         *   2. Turn OFF echo            → don't print typed keys
         *
         * The following code temporarily switches the terminal
         * to a RAW-like mode.
         */
        // 1. Read and store current terminal settings
        tcgetattr(STDIN_FILENO, &oldt);
         // 2. Copy old settings → so we can safely modify them
        newt = oldt;
         // 3. Disable canonical mode and echo:
        //    ICANON → line buffering (wait for Enter)
        //    ECHO   → prints typed characters
        newt.c_lflag &= ~(ICANON | ECHO);

          // 4. Apply the new settings immediately
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        // 5. Read ONE character immediately (no Enter required)
        ch = getchar();
        
        // Check if it's an escape sequence (3 bytes on Linux)
        /*
         * Arrow keys and special keys in Linux send ESCAPE SEQUENCES:
         *     ESC [ A  → Up
         *     ESC [ B  → Down
         *     ESC [ C  → Right
         *     ESC [ D  → Left
         *
         * So we check if the first character is ESC (27),
         * then read the following bytes to identify the key.
         */
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
        
         // 6. Restore terminal to the ORIGINAL settings
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        
        return ch;
    }
    
#endif