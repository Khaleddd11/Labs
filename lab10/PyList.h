#ifndef PYLIST_H
#define PYLIST_H

#include <iostream>
#include <string>
using namespace std;

// My idea: store everything as strings internally
// then convert when needed using casting operators
// this way i can store any type without templates or unions

class PyList {
private:
    string *data;      // array of strings (stored on heap)
    int size;          // how many elements currently stored
    int capacity;      // total space available
    
    // helper to resize when we run out of space
    void resize();
    
public:
    // constructors
    PyList();                    // empty list
    PyList(int cap);             // list with initial capacity
    PyList(const PyList &other); // copy constructor (deep copy)
    ~PyList();                   // destructor
    
    // assignment
    PyList& operator=(const PyList &other);
    
    // add elements (automatically converts to string)
    void append(int value);
    void append(double value);
    void append(const string &value);
    void append(const char *value);
    
    // access elements - returns a helper class that can convert back
    class Element {
    private:
        string value;
        
    public:
        Element(const string &val) : value(val) {}
        
        // casting operators - convert back to original type
        operator int() const;
        operator double() const;
        operator string() const;
        
        // for printing
        friend ostream& operator<<(ostream &out, const Element &e);
    };
    
    // array access
    Element operator[](int index) const;
    
    // utility
    int length() const;
    bool isEmpty() const;
    void clear();
    void display() const;
    
    // remove element
    void remove(int index);
    
    // insert at specific position
    void insert(int index, int value);
    void insert(int index, double value);
    void insert(int index, const string &value);
};

#endif