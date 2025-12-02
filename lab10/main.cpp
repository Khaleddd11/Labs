#include "PyList.h"
#include <iostream>

using namespace std;

int main() {
    cout << "=====================================" << endl;
    cout << "  List in C++" << endl;
    cout << "=====================================" << endl;
    
    // create empty list (starts with capacity 2, grows automatically)
    PyList myList;
    
    cout << "\n--- Adding different types ---" << endl;
    
    // add different types - no need to specify type!
    myList.append(42);           // int
    myList.append(3.14);         // double
    myList.append("hello");      // string
    myList.append(100);          // int
    myList.append(2.5);          // double
    
    cout << "List after adding elements: ";
    myList.display();
    
    cout << "Length: " << myList.length() << endl;
    
    // access elements and convert back to original type
    cout << "\n--- Accessing elements ---" << endl;
    
    // get as int
    int num = myList[0];
    cout << "myList[0] as int: " << num << endl;
    
    // get as double
    double pi = myList[1];
    cout << "myList[1] as double: " << pi << endl;
    
    // get as string
    string text = myList[2];
    cout << "myList[2] as string: " << text << endl;
    
    // can also just print directly
    cout << "myList[3]: " << myList[3] << endl;
    cout << "myList[4]: " << myList[4] << endl;
    
    // do math with retrieved values
    cout << "\n--- Using retrieved values ---" << endl;
    int x = myList[0];
    int y = myList[3];
    cout << "myList[0] + myList[3] = " << x << " + " << y << " = " << (x + y) << endl;
    
    double a = myList[1];
    double b = myList[4];
    cout << "myList[1] * myList[4] = " << a << " * " << b << " = " << (a * b) << endl;
    
    // test dynamic resizing
    cout << "\n--- Testing dynamic resizing ---" << endl;
    cout << "Adding more elements..." << endl;
    
    for (int i = 0; i < 10; i++) {
        myList.append(i * 10);
    }
    
    cout << "List after adding 10 more: ";
    myList.display();
    cout << "Length: " << myList.length() << endl;
    
    // test insert
    cout << "\n--- Testing insert ---" << endl;
    myList.insert(2, 999);
    cout << "After inserting 999 at index 2: ";
    myList.display();
    
    // test remove
    cout << "\n--- Testing remove ---" << endl;
    myList.remove(2);
    cout << "After removing index 2: ";
    myList.display();
    
    // test copy
    cout << "\n--- Testing deep copy ---" << endl;
    PyList list2 = myList;
    cout << "Original: ";
    myList.display();
    cout << "Copy: ";
    list2.display();
    
    // modify copy to prove they're independent
    list2.append("MODIFIED");
    cout << "\nAfter modifying copy:" << endl;
    cout << "Original: ";
    myList.display();
    cout << "Copy: ";
    list2.display();
    
    // mixed usage example
    cout << "\n--- testing with real examplee ---" << endl;
    PyList studentData;
    
    studentData.append("khaled");     // name
    studentData.append(20);          // age
    studentData.append(3.8);         // gpa
    studentData.append("CS");        // major
    
    cout << "Student Record: ";
    studentData.display();
    
    // retrieve and use
    string name = studentData[0];
    int age = studentData[1];
    double gpa = studentData[2];
    string major = studentData[3];
    
    cout << "\nStudent Info:" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << " years old" << endl;
    cout << "GPA: " << gpa << endl;
    cout << "Major: " << major << endl;
    
    // test clear
    cout << "\n--- Testing clear ---" << endl;
    studentData.clear();
    cout << "After clear: ";
    studentData.display();
    cout << "Is empty? " << (studentData.isEmpty() ? "Yes" : "No") << endl;
    
    cout << "\n=====================================" << endl;
    cout << "  Enddd" << endl;
    cout << "=====================================" << endl;
    
    return 0;
}