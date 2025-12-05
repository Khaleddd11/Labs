#include "List.h"
#include <iostream>
using namespace std;

int main() {
    cout << "=== Testing Dynamic Type List ==" << endl << endl;
    
    // create a list with default capacity
    List myList;
    
    // test 1: adding different types directly
    cout << "Test 1: Adding different primitive types" << endl;
    myList.add(42);              // int
    myList.add(3.14f);           // float
    myList.add('A');             // char
    myList.add(true);            // bool
    myList.add("Hello World");   // string (const char*)
    
    cout << "List size: " << myList.getSize() << endl;
    cout << "List capacity: " << myList.getCapacity() << endl;
    displayList(myList);
    cout << endl;
    
    // test 2: adding using string detection
    cout << "Test 2: Adding items using detectType from strings" << endl;
    List autoList;
    autoList.add("100");         // should detect as int
    autoList.add("2.718");       // should detect as float
    autoList.add("true");        // should detect as bool
    autoList.add("false");       // should detect as bool
    autoList.add("x");           // should detect as char
    autoList.add("This is text"); // should detect as string
    autoList.add("-50");         // should detect as negative int
    autoList.add("3.14159");     // should detect as float
    
    displayList(autoList);
    cout << endl;
    
    // test 3: accessing elements using get()
    cout << "Test 3: Accessing elements with geft()" << endl;
    OriginalType* item = myList.get(0);
    if(item) {
        cout << "Item at index 0: ";
        item->print();
        cout << " (type: " << item->getType() << ")" << endl;
    }
    
    // test accessing out of bounds
    OriginalType* nullItem = myList.get(100);
    if(nullItem == nullptr) {
        cout << "Index 100 is out of bounds (correctly returns nullptr)" << endl;
    }
    cout << endl;
    
    // test 4: accessing with [] operator
    cout << "Test 4: Accessing with [] operator" << endl;
    cout << "myList[2]: ";
    myList[2].print();
    cout << " (type: " << myList[2].getType() << ")" << endl;
    
    // test exception handling
    try {
        cout << "Trying to access myList[999]..." << endl;
        myList[999].print();
    } catch(const out_of_range& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    cout << endl;
    
    // test 5: testing resize functionality
    cout << "Test 5: Testing automatic resize" << endl;
    List smallList(2);  // start with small capacity
    cout << "Initial capacity: " << smallList.getCapacity() << endl;
    
    smallList.add(1);
    smallList.add(2);
    cout << "After adding 2 items - Size: " << smallList.getSize() 
         << ", Capacity: " << smallList.getCapacity() << endl;
    
    smallList.add(3);  // this should trigger resize
    cout << "After adding 3rd item - Size: " << smallList.getSize() 
         << ", Capacity: " << smallList.getCapacity() << endl;
    
    smallList.add(4);
    smallList.add(5);  // should trigger another resize
    cout << "After adding 5 items - Size: " << smallList.getSize() 
         << ", Capacity: " << smallList.getCapacity() << endl;
    cout << endl;
    
    
    // test 8: testing getValue methods
    cout << "Test 8: Getting actual values from type objects" << endl;
    List valueList;
    valueList.add(99);
    valueList.add(1.5f);
    valueList.add('Z');
    valueList.add(false);
    
    // cast to specific type to use getValue
    IntType* intPtr = dynamic_cast<IntType*>(valueList.get(0));
    if(intPtr) {
        cout << "Integer value: " << intPtr->getValue() << endl;
    }
    
    FloatType* floatPtr = dynamic_cast<FloatType*>(valueList.get(1));
    if(floatPtr) {
        cout << "Float value: " << floatPtr->getValue() << endl;
    }
    
    CharType* charPtr = dynamic_cast<CharType*>(valueList.get(2));
    if(charPtr) {
        cout << "Char value: " << charPtr->getValue() << endl;
    }
    
    BoolType* boolPtr = dynamic_cast<BoolType*>(valueList.get(3));
    if(boolPtr) {
        cout << "Bool value: " << (boolPtr->getValue() ? "true" : "false") << endl;
    }
    cout << endl;
    
    // test 9: edge cases for detectType
    cout << "Test 9: Edge cases for type detection" << endl;
    List edgeList;
    edgeList.add("");           // empty string
    edgeList.add("0");          // zero as int
    edgeList.add("-0");         // negative zero
    edgeList.add("0.0");        // zero as float
    edgeList.add(" ");          // space (should be char)
    edgeList.add("123abc");     // mixed (should be string)
    edgeList.add("12.34.56");   // multiple dots (should be string)
    
    cout << "Edge cases:" << endl;
    displayList(edgeList);
    cout << endl;
    
    // test 10: stress test with many elements
    cout << "Test 10:  test with 100 elements" << endl;
    List bigList;
    for(int i = 0; i < 100; i++) {
        bigList.add(i);
    }
    cout << "Added 100 integers" << endl;
    cout << "Size: " << bigList.getSize() << endl;
    cout << "Capacity: " << bigList.getCapacity() << endl;
    cout << "First element: ";
    bigList.get(0)->print();
    cout << endl;
    cout << "Last element: ";
    bigList.get(99)->print();
    cout << endl;
    cout << "Middle element (50): ";
    bigList.get(50)->print();
    cout << endl;
    cout << endl;
    

    // nhere all Lists will be automatically destroyed 
    // their destructors will clean up all allocated memory
    
    return 0;
}