┌─────────────────────────────────┐
│      main.cpp (Application)     │  ←  code
├─────────────────────────────────┤
│     terminal.h (Interface)      │  ← Public API
├─────────────────────────────────┤
│  terminal.cpp (Implementation)  │  ← OS-specific logic
├─────────────────────────────────┤
│   Windows API  |  ANSI Codes    │  ← Platform layer
└─────────────────────────────────┘

Design Patterns Used
1. Façade Pattern
The library hides complex OS-specific details behind simple functions:

printAt(x, y, color, text) is easy to use
Internally handles different APIs for Windows vs Linux

2. Strategy Pattern (via Preprocessor)
Different implementations for the same interface based on OS:
#ifdef OS_WINDOWS
    // Windows implementation
#endif

#ifdef OS_LINUX  
    // Linux implementation
#endif

3. Compile-Time Polymorphism
The preprocessor selects the correct code at compile time, not runtime:

No performance overhead
No virtual functions needed
Binary only contains code for target OS


File Responsibilities
terminal.h (Interface Layer)
#ifndef TERMINAL_H  // Header guard prevents double inclusion
#define TERMINAL_H

enum Color { ... };  // Public color constants

// Function declarations (interface contract)
void printAt(int x, int y, Color color, const std::string& text);
Purpose:

Defines the public API (what users can call)
No implementation details
Platform-agnostic interface


terminal.cpp (Implementation Layer)
#include "terminal.h"

#ifdef _WIN32
    #define OS_WINDOWS
    #include <windows.h>
#else
    #define OS_LINUX
#endif