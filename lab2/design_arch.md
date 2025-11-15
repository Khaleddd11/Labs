# Menu System - Design & Architecture Documentation

## Overview
This is a **cross-platform terminal-based menu system** that works on both Windows and Linux. It provides colored text display, cursor positioning, and keyboard input handling using OS-specific APIs.

---

## Architecture Diagram

```
┌─────────────────────────────────────────┐
│           main.cpp                      │
│        (Application Logic)              │
│  - Menu navigation                      │
│  - Screen transitions                   │
│  - User interaction flow                │
└──────────────┬──────────────────────────┘
               │
       ┌───────┴────────┐
       │                │
┌──────▼──────┐  ┌──────▼──────┐
│ terminal.h  │  │ keyboard.h  │
│ terminal.cpp│  │ keyboard.cpp│
│             │  │             │
│ - Colors    │  │ - Key input │
│ - Cursor    │  │ - Extended  │
│ - Clear     │  │   keys      │
└──────┬──────┘  └──────┬──────┘
       │                │
┌──────▼────────────────▼──────┐
│    Preprocessor Checks        │
│      #ifdef _WIN32            │
└──────┬────────────────┬───────┘
       │                │
┌──────▼──────┐  ┌──────▼──────┐
│  Windows    │  │   Linux     │
│             │  │             │
│ windows.h   │  │ termios.h   │
│ conio.h     │  │ ANSI codes  │
└─────────────┘  └─────────────┘
```

---

## File Structure

### **1. terminal.h** (Interface)
**Purpose:** Defines the public API for terminal operations

**Contains:**
- `Color` enum (16 colors: BLACK to BRIGHT_WHITE)
- Function declarations:
  - `void clearScreen()`
  - `void moveCursor(int x, int y)`
  - `void setColor(Color color)`
  - `void printAt(int x, int y, Color color, string text)`

**Design Pattern:** **Header Guard** (`#ifndef TERMINAL_H`)
- Prevents multiple inclusions
- Ensures definitions are only loaded once

---

### **2. terminal.cpp** (Implementation)
**Purpose:** Implements terminal operations for both Windows and Linux

#### **OS Detection:**
```cpp
#ifdef _WIN32
    #define OS_WINDOWS
    #include <windows.h>
#else
    #define OS_LINUX
#endif
```

#### **Windows Implementation:**
- Uses **Windows Console API**
- `GetStdHandle(STD_OUTPUT_HANDLE)` - Gets console handle
- `SetConsoleTextAttribute()` - Sets color
- `SetConsoleCursorPosition()` - Moves cursor
- `system("cls")` - Clears screen

#### **Linux Implementation:**
- Uses **ANSI Escape Codes**
- `\033[Y;XH` - Move cursor to position (Y, X)
- `\033[0;31m` - Set color (31 = red)
- `\033[2J\033[H` - Clear screen and home cursor

**Design Pattern:** **Strategy Pattern via Preprocessor**
- Same function names, different implementations
- Compiler selects correct version at compile-time
- Zero runtime overhead

---

### **3. keyboard.h** (Interface)
**Purpose:** Defines keyboard constants and input function

**Contains:**
- Key code constants:
  ```cpp
  #define KEY_UP 72
  #define KEY_DOWN 80
  #define KEY_ENTER 13
  #define KEY_ESC 27
  #define KEY_BACKSPACE 8
  // etc...
  ```
- Function: `int getKey()`

**Why unified codes?**
- Different OS send different codes for arrow keys
- We normalize them to one set of codes
- Makes application code platform-independent

---

### **4. keyboard.cpp** (Implementation)
**Purpose:** Handles keyboard input on both platforms

#### **Windows Implementation:**
```cpp
int getKey() {
    int ch = _getch();  // Read one byte (no echo, no buffer)
    
    // Extended keys send 2 bytes:
    // Byte 1: 0 or 224 (signals extended key)
    // Byte 2: actual key code
    if (ch == 0 || ch == 224) {
        ch = _getch();  // Read second byte
    }
    return ch;
}
```

**How Windows encodes arrow keys:**
1. First byte: `0` or `224` (prefix)
2. Second byte: actual code (72=UP, 80=DOWN, etc.)

#### **Linux Implementation:**
```cpp
int getKey() {
    // Disable line buffering and echo
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    ch = getchar();
    
    // Extended keys send 3 bytes:
    // Byte 1: 27 (ESC)
    // Byte 2: 91 ('[')
    // Byte 3: actual code
    if (ch == 27) {
        ch = getchar();
        if (ch == 91) {
            ch = getchar();
            // Convert Linux codes to our standard codes
            if (ch == 65) ch = KEY_UP;    // 'A' -> 72
            else if (ch == 66) ch = KEY_DOWN;  // 'B' -> 80
            // etc...
        }
    }
    
    // Restore terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
```

**How Linux encodes arrow keys:**
1. First byte: `27` (ESC character)
2. Second byte: `91` (the '[' character)
3. Third byte: actual code (65=UP, 66=DOWN as letters A, B)

**Key normalization:**
- Linux sends 65 for UP arrow → We convert to 72
- Linux sends 127 for Backspace → We convert to 8
- Result: Application sees same codes on both platforms

---

### **5. main.cpp** (Application)
**Purpose:** Menu logic and user interaction

#### **Core Components:**

**1. Menu Display:**
```cpp
void showMenu(int selected) {
    clearScreen();
    
    // Show options centered on screen
    if (selected == 0) {
        printAt(35, 10, BLUE, "New");  // Highlighted
    } else {
        printAt(35, 10, WHITE, "New"); // Normal
    }
    // ... repeat for Display and Exit
}
```

**2. Navigation Logic:**
```cpp
int selected = 0;  // Current menu position (0-2)

if (key == KEY_DOWN) {
    selected++;
    if (selected > 2) selected = 0;  // Wrap to top
}
else if (key == KEY_UP) {
    selected--;
    if (selected < 0) selected = 2;  // Wrap to bottom
}
```

**3. Selection Handling:**
```cpp
if (key == KEY_ENTER) {
    if (selected == 0) newScreen();
    else if (selected == 1) displayScreen();
    else if (selected == 2) running = false;  // Exit
}
```

**4. Sub-screens:**
```cpp
void newScreen() {
    clearScreen();
    printAt(10, 5, GREEN, "You are in NEW section");
    
    // Wait for backspace to return
    while (true) {
        if (getKey() == KEY_BACKSPACE) break;
    }
}
```

---

## Design Principles

### **1. Separation of Concerns**
- **Terminal module:** Display and colors
- **Keyboard module:** Input handling
- **Main module:** Business logic
- Each module has one responsibility

### **2. Platform Abstraction**
```cpp
// Application code (platform-independent):
printAt(10, 5, RED, "Hello");

// Internally becomes:
// Windows: SetConsoleCursorPosition() + SetConsoleTextAttribute()
// Linux:   printf("\033[6;11H\033[0;31mHello")
```

### **3. Compile-Time Selection**
- Preprocessor chooses correct code **before compilation**
- Final binary contains only one platform's code
- No runtime if/else checks
- Optimal performance

### **4. Interface Consistency**
- Same function names on all platforms
- Same parameters
- Same behavior
- Application doesn't know/care about OS

---

## Key Concepts Explained

### **Why 2 bytes on Windows, 3 on Linux?**

**Windows:** Uses **scan codes**
- Regular keys: 1 byte (e.g., 'a' = 97)
- Extended keys: 2 bytes (prefix + code)
- Example: Arrow Up = `0, 72` or `224, 72`

**Linux:** Uses **ANSI escape sequences**
- Regular keys: 1 byte
- Extended keys: 3 bytes (ESC + [ + letter)
- Example: Arrow Up = `27, 91, 65` (ESC + [ + A)

### **Why normalize key codes?**
Without normalization:
```cpp
// Bad: Platform-specific code in main
if (key == 65 || key == 72) { /* arrow up */ }
```

With normalization:
```cpp
// Good: Clean, readable code
if (key == KEY_UP) { /* arrow up */ }
```

### **Terminal Modes (Linux)**
```cpp
newt.c_lflag &= ~(ICANON | ECHO);
```
- `ICANON` off: Read characters immediately (no Enter needed)
- `ECHO` off: Don't print typed characters
- Must restore settings after reading!

---

## Data Flow Example

**User presses Arrow Down:**

1. **Keyboard layer:**
   - Windows: `_getch()` returns `224`, then `80`
   - Linux: `getchar()` returns `27`, `91`, `66`
   - Both normalize to `KEY_DOWN` (80)

2. **Application layer:**
   ```cpp
   if (key == KEY_DOWN) {
       selected++;  // Move to next option
   }
   ```

3. **Terminal layer:**
   ```cpp
   showMenu(selected);
   // Redraw with new selection highlighted
   ```

4. **OS layer:**
   - Windows: Calls `SetConsoleTextAttribute(h, BLUE)`
   - Linux: Prints `"\033[1;34m"` (blue color code)

---

## Advantages of This Design

✅ **Cross-platform** - Same code works everywhere  
✅ **Efficient** - No runtime overhead  
✅ **Maintainable** - Clean separation of concerns  
✅ **Extensible** - Easy to add new functions  
✅ **Type-safe** - Enum for colors, constants for keys  
✅ **No dependencies** - Uses only standard libraries  
✅ **Simple** - Basic if statements, no complex logic  

---

## How to Extend

### Add a new color:
```cpp
// In terminal.h:
enum Color {
    // ... existing colors
    ORANGE = 16  // Add new color
};
```

### Add a new key:
```cpp
// In keyboard.h:
#define KEY_F1 59

// In keyboard.cpp (Linux section):
else if (ch == 80) ch = KEY_F1;  // Convert Linux F1 code
```

### Add a new menu option:
```cpp
// In main.cpp:
void settingsScreen() {
    clearScreen();
    printAt(10, 5, CYAN, "Settings");
    while (getKey() != KEY_BACKSPACE);
}

// Add to menu display and selection logic
```

---

## Common Pitfalls

❌ **Forgetting to restore terminal settings (Linux)**
- Always restore after `tcsetattr()`

❌ **Mixing buffered/unbuffered input**
- Don't use `cin` and `getKey()` together

❌ **Hardcoding positions**
- Use variables for screen dimensions

❌ **Not handling wrap-around**
- Menu navigation should loop (top↔bottom)

---

## Compilation

**Windows:**
```bash
g++ main.cpp terminal.cpp keyboard.cpp -o menu.exe
```

**Linux:**
```bash
g++ main.cpp terminal.cpp keyboard.cpp -o menu
```

The compiler automatically:
1. Detects the OS via `_WIN32` macro
2. Includes correct headers
3. Compiles only relevant code blocks
4. Links OS-specific libraries

---

## Summary

This menu system demonstrates:
- **Modular design** (separate files for each concern)
- **Platform abstraction** (same interface, different implementation)
- **Compile-time polymorphism** (preprocessor selection)
- **Clean architecture** (layers with clear responsibilities)

The result is maintainable, efficient, cross-platform code that's easy to understand and extend.