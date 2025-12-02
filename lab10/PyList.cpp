#include "PyList.h"
#include <sstream>

// default constructor - start with capacity of 2
PyList::PyList() {
    capacity = 2;
    size = 0;
    data = new string[capacity];
}

// constructor with initial capacity
PyList::PyList(int cap) {
    capacity = cap;
    size = 0;
    data = new string[capacity];
}

// copy constructor - need deep copy!
PyList::PyList(const PyList &other) {
    size = other.size;
    capacity = other.capacity;
    data = new string[capacity];
    
    // copy all elements
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

// destructor - free memory
PyList::~PyList() {
    delete[] data;
}

// assignment operator
PyList& PyList::operator=(const PyList &other) {
    if (this == &other) return *this;
    
    delete[] data;
    
    size = other.size;
    capacity = other.capacity;
    data = new string[capacity];
    
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
    
    return *this;
}

// resize when array is full
// doubles the capacity each time
void PyList::resize() {
    capacity *= 2;
    string *newData = new string[capacity];
    
    // copy old data
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    
    delete[] data;
    data = newData;
}

// append int - convert to string and store
void PyList::append(int value) {
    if (size >= capacity) {
        resize();
    }
    
    // convert int to string using stringstream
    stringstream ss;
    ss << value;
    data[size] = ss.str();
    size++;
}

// append double - convert to string
void PyList::append(double value) {
    if (size >= capacity) {
        resize();
    }
    
    stringstream ss;
    ss << value;
    data[size] = ss.str();
    size++;
}

// append string - just store directly
void PyList::append(const string &value) {
    if (size >= capacity) {
        resize();
    }
    
    data[size] = value;
    size++;
}

// append C-string
void PyList::append(const char *value) {
    if (size >= capacity) {
        resize();
    }
    
    data[size] = string(value);
    size++;
}

// array access - returns Element that can be cast
PyList::Element PyList::operator[](int index) const {
    //1. BOUNDS CHECKING
    if (index < 0 || index >= size) {
        cout << "Index out of bounds!" << endl;
        // If the user asks for index 100 but we only have 5 items,
        // we return an empty Element to prevent a crash.
        return Element("");
    }
    // 2. THE WRAPPER
    // data[index] is the raw string (e.g., "3.14")
    // Element(...) calls the constructor of the Element class.
    // We hand the string to the Element and return the Element.
    return Element(data[index]);
}

// get length
int PyList::length() const {
    return size;
}

// check if empty
bool PyList::isEmpty() const {
    return size == 0;
}

// clear all elements
void PyList::clear() {
    size = 0;
}

// display all elements
void PyList::display() const {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// remove element at index
void PyList::remove(int index) {
    if (index < 0 || index >= size) {
        cout << "Index out of bounds!" << endl;
        return;
    }
    
    // shift all elements left
    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    size--;
}

// insert at specific position
void PyList::insert(int index, int value) {
    if (index < 0 || index > size) {
        cout << "Index out of bounds!" << endl;
        return;
    }
    
    if (size >= capacity) {
        resize();
    }
    
    // shift elements right
    for (int i = size; i > index; i--) {
        data[i] = data[i - 1];
    }
    
    // convert and insert
    stringstream ss;
    ss << value;
    data[index] = ss.str();
    size++;
}

void PyList::insert(int index, double value) {
    if (index < 0 || index > size) {
        cout << "Index out of bounds!" << endl;
        return;
    }
    
    if (size >= capacity) {
        resize();
    }
    
    for (int i = size; i > index; i--) {
        data[i] = data[i - 1];
    }
    
    stringstream ss;
    ss << value;
    data[index] = ss.str();
    size++;
}

void PyList::insert(int index, const string &value) {
    if (index < 0 || index > size) {
        cout << "Index out of bounds!" << endl;
        return;
    }
    
    if (size >= capacity) {
        resize();
    }
    
    for (int i = size; i > index; i--) {
        data[i] = data[i - 1];
    }
    
    data[index] = value;
    size++;
}

// ============================================================================
// Element class methods - for type conversion
// ============================================================================

// convert back to int
PyList::Element::operator int() const {
    // use stringstream to convert string to int
    stringstream ss(value);
    int result;
    ss >> result;
    return result;
}

// convert back to double
PyList::Element::operator double() const {
    stringstream ss(value);
    double result;
    ss >> result;
    return result;
}

// convert back to string
PyList::Element::operator string() const {
    return value;
}

// for printing Element
ostream& operator<<(ostream &out, const PyList::Element &e) {
    out << e.value;
    return out;
}