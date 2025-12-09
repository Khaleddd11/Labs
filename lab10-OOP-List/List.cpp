#include "List.h"

// constructor - sets up empty list with given capacity
List::List(int capacity) {
    this->capacity = capacity;
    size = 0;
    data = new OriginalType*[capacity];  // allocate array
}

// destructor - need to clean up all objects we created
List::~List() {
    for(int i = 0; i < size; i++) delete data[i];  // delete each object
    delete[] data;  // delete the array itself
}

int List::getSize() { return size; }
int List::getCapacity() { return capacity; }
void List::updateSize(int s) { size = s; }
void List::updateCapacity(int c) { capacity = c; }

void List::resize() {
    int newCapacity = capacity * 2;
    OriginalType **temp = new OriginalType*[newCapacity];
    
    for(int i = 0; i < size; i++) {
        temp[i] = data[i];
    }
    
    delete[] data;
    data = temp;
    capacity = newCapacity;
}


// main add function - handles resizing when list gets full
void List::add(OriginalType *obj) {
    if(!obj) {  //  don't add null pointers
        cout << "Error: trying to add nullptr!" << endl;
        return;
    }
    
    if(size < capacity) {
        // we have space, just add it
        data[size++] = obj;
    } else {
        // list is full, need to expand it
        int newCapacity = capacity * 2;  // double the size
        OriginalType **temp = new OriginalType*[newCapacity];
        
        // copy all existing items to new array
        for(int i = 0; i < size; i++) temp[i] = data[i];
        
        delete[] data;  // free old array
        data = temp;  // point to new array
        capacity = newCapacity;
        
        data[size++] = obj;  // now add the new item
    }
}

// add from string - uses detectType to figure out what to create
 // Strings are special because they could represent:
    // - an integer ("123")
    // - a float ("3.14")
void List::add(string v){
    OriginalType *obj = detectType(v);
    this->add(obj);
}   

// these create the appropriate type object and add it
void List::add(int v) { add(new IntType(v)); }
void List::add(float v) { add(new FloatType(v)); }
void List::add(bool v) { add(new BoolType(v)); }
void List::add(char v) { add(new CharType(v)); }
void List::add(const char* v) { 
    string str(v);
    add(str);  // This will call add(string v) which calls detectType!
}

// get element at index - returns nullptr if index is invalid
OriginalType* List::get(int idx) {
    if(idx >= 0 && idx < size) return data[idx];
    return nullptr;  // out of bounds
}

// prints all elements with index and type info
void displayList(List& myList){
    for (int i = 0; i < myList.getSize(); i++) {
        cout << i << ": ";
        OriginalType* entry = myList.get(i);
        if (entry) {
            entry->print();  // display the value
            cout << " (" << entry->getType() << ")";  // print type in parentheses
        }
        cout << endl;
    }
}

// throws exception if index out of range
OriginalType& List::operator[](int idx){
    if(idx >= 0 && idx < size) return *data[idx];
    throw out_of_range("Index out of range");  // handle bad access
}