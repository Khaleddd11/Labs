#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using namespace std;

// ============================================================================
// Employee Structure
// Holds information about one employee
// ============================================================================
struct Employee {
    string name;      // Employee name
    int age;          // Employee age
    double salary;    // Employee salary
};

// ============================================================================
// Maximum number of employees we can store
// Using array, so we need to set a limit
// ============================================================================
const int MAX_EMPLOYEES = 100;

// ============================================================================
// Function declarations
// ============================================================================

// Add a new employee to the array
// Returns: true if added successfully, false if array is full
bool addEmployee(Employee employees[], int &count);

// Display all employees in the array
void displayAllEmployees(Employee employees[], int count);

#endif