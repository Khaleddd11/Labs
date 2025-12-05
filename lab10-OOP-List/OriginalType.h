#ifndef __ORIGINAL_TYPE_H__
#define __ORIGINAL_TYPE_H__
#include <iostream>
#include <string>
using namespace std;

// base class for all our types - everything inherits from this
class OriginalType {
public:
    OriginalType(){};
    virtual ~OriginalType(){};
    virtual void print() = 0;  // each type needs to implement how it prints itself
    virtual string getType() = 0;  // returns what type it is
     ;
};

// holds integer values
class IntType : public OriginalType{
private:
    int val;
public:
    IntType(int val);
    void print() override {cout << val;}  // just print the number
    string getType() override {return "int";}
    int getValue() const { return val; }
};

// holds decimal/floating point values
class FloatType : public OriginalType{
private:
    float val;
public:
    FloatType(float val);
    void print() override {cout << val;}
    string getType() override {return "float";}
    float getValue() const { return val; } 
};

// holds single character
class CharType : public OriginalType{
private:
    char val;
public:
    CharType(char val);
    void print() override {cout << val;}
    string getType() override {return "char";}
    char getValue() const { return val; } 
    
};

// holds text/strings
class StringType : public OriginalType{
private:
    string val;
public:
    StringType(string val);
    void print() override {cout << val;}
    string getType() override {return "string";}
    string getValue() const { return val; }
};

// holds true/false boolean values
class BoolType : public OriginalType{
private:
    bool val;
public:
    BoolType(bool val);
    void print() override {cout << val;}  // prints 1 or 0
    string getType() override {return "bool";}
    bool getValue() const { return val; }
};

// this function figures out what type a string should be converted to
OriginalType* detectType(const string& input);

// overload so we can use cout directly with our types
ostream& operator<<(ostream& os, OriginalType& obj);

#endif