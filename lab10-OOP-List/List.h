#ifndef __LIST_H__
#define __LIST_H__
#include "OriginalType.h"
#include <iostream>
using namespace std;

// dynamic list that can hold any OriginalType objects
class List {
private:
    OriginalType **data;  // array of pointers to our type objects
    int capacity;  // how many slots we have allocated
    int size;  // how many slots are actually being used
     void resize(); 
public:
    List(int capacity = 8);  // default capacity is 8 if not specified
    ~List();
    
    // main add method - takes a pointer to OriginalType
    void add(OriginalType *obj);
    
    void add(int v);
    void add(float v);
    void add(char v);
    void add(bool v);
    void add(const char* v);
    void add(string v);
    
    // retrieve element at index
    OriginalType* get(int idx);
    
    // array subscript operator for easier access
    OriginalType& operator[](int idx);
    
    // getters and setters
    int getSize();
    int getCapacity();
    void updateSize(int size);
    void updateCapacity(int capacity);
};

//function to print everything in the list
void displayList(List&);

#endif