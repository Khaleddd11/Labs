#include "employee.h"
#include "terminal.h"
#include "keyboard.h"
#include <iostream>
#include <sstream>

using namespace std;

// Helper function to convert int to string
string intToStr(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

// Helper function to convert double to string
string doubleToStr(double num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

// ============================================================================
// Function: getStringInput
// Purpose: Get a string input from user (for name)
// ============================================================================
string getStringInput(int x, int y) {
    string input = "";
    
    while (true) {
        // Display current input with cursor
        printAt(x, y, BRIGHT_CYAN, input + "_  ");
        
        int key = getKey();
        
        // Enter key - done
        if (key == KEY_ENTER && input.length() > 0) {
            return input;
        }
        
        // Backspace - delete last character
        if (key == KEY_BACKSPACE && input.length() > 0) {
            input = input.substr(0, input.length() - 1);
        }
        
        // ESC - cancel
        if (key == KEY_ESC) {
            return "";  // Empty string means cancelled
        }
        
        // Letters and space
        if ((key >= 'a' && key <= 'z') || 
            (key >= 'A' && key <= 'Z') || 
            key == ' ') {
            if (input.length() < 30) {  // Limit name length
                input += (char)key;
            }
        }
    }
}

// ============================================================================
// Function: getNumberInput
// Purpose: Get a number input from user (for age or salary)
// ============================================================================
string getNumInput(int x, int y, bool allowDecimal) {
    string input = "";
    bool hasDecimal = false;
    
    while (true) {
        // Display current input with cursor
        printAt(x, y, BRIGHT_CYAN, input + "_  ");
        
        int key = getKey();
        
        // Enter key - done
        if (key == KEY_ENTER && input.length() > 0) {
            return input;
        }
        
        // Backspace - delete last character
        if (key == KEY_BACKSPACE && input.length() > 0) {
            if (input[input.length() - 1] == '.') {
                hasDecimal = false;
            }
            input = input.substr(0, input.length() - 1);
        }
        
        // ESC - cancel
        if (key == KEY_ESC) {
            return "";
        }
        
        // Digits
        if (key >= '0' && key <= '9') {
            if (input.length() < 10) {
                input += (char)key;
            }
        }
        
        // Decimal point (only for salary)
        if (key == '.' && allowDecimal && !hasDecimal) {
            input += '.';
            hasDecimal = true;
        }
    }
}

// ============================================================================
// Function: addEmployee
// Purpose: Add a new employee to the array
// ============================================================================
bool addEmployee(Employee employees[], int &count) {
    clearScreen();
    
    // Check if array is full
    if (count >= MAX_EMPLOYEES) {
        printAt(10, 10, RED, "Error: Maximum employees reached!");
        printAt(10, 12, YELLOW, "Press any key to continue...");
        getKey();
        return false;
    }
    
    printAt(10, 3, BRIGHT_YELLOW, "===== ADD NEW EMPLOYEE =====");
    
    // Get name
    printAt(10, 6, WHITE, "Enter Name: ");
    string name = getStringInput(22, 6);
    if (name == "") return false;  // User cancelled
    
    // Get age
    printAt(10, 8, WHITE, "Enter Age: ");
    string ageStr = getNumInput(21, 8, false);  // No decimal for age
    if (ageStr == "") return false;
    int age = stoi(ageStr);  // Converts string to int

    // Get salary
    printAt(10, 10, WHITE, "Enter Salary: ");
    string salaryStr = getNumInput(24, 10, true);  // Allow decimal
    if (salaryStr == "") return false;
    double salary = stod(salaryStr);  // Simple! Converts string to double
    
    // Store employee
    employees[count].name = name;
    employees[count].age = age;
    employees[count].salary = salary;
    count++;
    
    // Success message
    printAt(10, 13, GREEN, "Employee added successfully!");
    printAt(10, 14, CYAN, "Total employees: " + intToStr(count));
    printAt(10, 16, WHITE, "Press any key to continue...");
    getKey();
    
    return true;
}

// ============================================================================
// Function: displayAllEmployees
// Purpose: Display all employees in the array
// ============================================================================
void displayAllEmployees(Employee employees[], int count) {
    clearScreen();
    
    printAt(10, 2, BRIGHT_YELLOW, "===== ALL EMPLOYEES =====");
    
    // Check if no employees
    if (count == 0) {
        printAt(10, 5, RED, "No employees to display!");
        printAt(10, 7, WHITE, "Press any key to continue...");
        getKey();
        return;
    }
    
    // Display header
    printAt(10, 4, CYAN, "Total: " + intToStr(count) + " employee(s)");
    printAt(10, 6, WHITE, "--------------------------------------------");
    
    // Display each employee
    int y = 7;
    for (int i = 0; i < count; i++) {
        printAt(10, y, BRIGHT_GREEN, intToStr(i + 1) + ". " + employees[i].name);
        printAt(15, y + 1, WHITE, "Age: " + intToStr(employees[i].age));
        printAt(15, y + 2, WHITE, "Salary: $" + doubleToStr(employees[i].salary));
        y += 4;
        
    }
    
    printAt(10, y + 1, WHITE, "--------------------------------------------");
    printAt(10, y + 2, WHITE, "Press any key to continue...");
    getKey();
}