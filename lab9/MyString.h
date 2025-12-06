#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
using namespace std;

// ============================================================================
// MyString Class
// A simple string class implementation using dynamic memory
// Demonstrates: pointers, HEAP memory, deep copy, operator overloading

// ============================================================================
class MyString {
private:
    // Private member variables
    char *str;      // Pointer to character array on HEAP
    int len;        // Length of string (not including null terminator)
    
public:
    // ========================================================================
    // CONSTRUCTORS AND DESTRUCTOR
    // ========================================================================
    
    // Default constructor: creates empty string ""
    MyString();
    
    // Parameterized constructor:
    // Example: MyString s("Hello");
    MyString(const char *s);
    
    // Copy constructor: creates DEEP COPY of another MyString
    MyString(const MyString &other);
    
    // Destructor: frees memory
    ~MyString();
    
    // ========================================================================
    // ASSIGNMENT OPERATOR
    // ========================================================================
    
    // Copy assignment: s1 = s2
    MyString& operator=(const MyString &other);
    
    // Assign from C-string: s1 = "Hello"
    MyString& operator=(const char *s);
    
    // ========================================================================
    // STRING CONCATENATION
    // ========================================================================
    
    // Concatenation: s1 + s2 returns new string
    MyString operator+(const MyString &other) const;
    
    // Concatenation with C-string: s1 + "world"
    MyString operator+(const char *s) const;
    
    // Append: s1 += s2 (modifies s1)
    MyString& operator+=(const MyString &other);
    
    // Append C-string: s1 += "world"
    MyString& operator+=(const char *s);

    // Prefix increment: ++ (adds space at end)
    MyString& operator++();

    //remove last char
    MyString& operator--();

    // repeat string
    MyString& operator*(int x);

    //friend function for repeating string
    friend MyString operator*(int x, MyString);
    
    // ========================================================================
    // COMPARISON OPERATORS
    // ========================================================================
    
    // Equal: s1 == s2
    bool operator==(const MyString &other) const;
    
    // Not equal: s1 != s2
    bool operator!=(const MyString &other) const;
    
    // Less than: s1 < s2 (lexicographic comparison)
    bool operator<(const MyString &other) const;
    
    // Greater than: s1 > s2
    bool operator>(const MyString &other) const;

    //check if empty or not 
    bool operator!() const;

    //check if a string is less than or equal another string
    bool operator<=(const MyString &other)const;

    // Check if string is greater than or equal to another string
    bool operator>=(const MyString &other) const; 

    // finds 
    bool include(const char *c)const;
    
    // ========================================================================
    // ARRAY ACCESS OPERATOR
    // ========================================================================
    
    // Access character at index: s[i]
    char& operator[](int index);
    
    // Const version for reading
    const char& operator[](int index) const;
    
    // ========================================================================
    // STREAM OPERATORS
    // ========================================================================
    
    // Output: cout << s
    friend ostream& operator<<(ostream &out, const MyString &s);
    
    // Input: cin >> s (reads one word)
    friend istream& operator>>(istream &in, MyString &s);
    
    // ========================================================================
    // UTILITY METHODS
    // ========================================================================
    
    // Get length of string
    int length() const;
    
    // Check if string is empty
    bool isEmpty() const;
    
    // Convert to C-string (returns pointer)
    const char* c_str() const;
    
    // Convert to uppercase
    MyString toUpper() const;
    
    // Convert to lowercase
    MyString toLower() const;
    
    // Find substring (returns index, -1 if not found)
    int find(const char *substr) const;
    
    // Clear the string (make it empty)
    void clear();
    
    // Display the string
    void display() const;
};
#endif // MYSTRING_H