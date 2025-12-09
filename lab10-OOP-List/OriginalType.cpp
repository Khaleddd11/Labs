#include "OriginalType.h"
#include <cctype>

// constructors - just store the value passed in
IntType::IntType(int v) : val(v) {}
FloatType::FloatType(float v) : val(v) {}
CharType::CharType(char v) : val(v) {}
StringType::StringType(string v) : val(v) {}
BoolType::BoolType(bool v) : val(v) {}

// tries to figure out what type the string represents

// here are an exact tarcing :
/*
Example 1: Input is "42"

Not empty ✓
Not "true" or "false" ✓
Length is 2, not a single char ✓
Loop through "42":

'4' is a digit → canBeInt stays true
'2' is a digit → canBeInt stays true
No dots → dotCount = 0


Try parsing as int:

stoi("42") succeeds → returns 42
idx = 2 (consumed whole string)
Returns new IntType(42) ✓



Example 2: Input is "3.14"

Not empty ✓
Not "true" or "false" ✓
Length is 4, not single char ✓
Loop through "3.14":

'3' is a digit
'.' found → dotCount = 1, canBeFloat = true
'1' is a digit
'4' is a digit


Try parsing as int:

dotCount = 1, so skip this


Try parsing as float:

stof("3.14") succeeds → returns 3.14
Returns new FloatType(3.14) ✓



Example 3: Input is "hello"

Not empty ✓
Not "true" or "false" ✓
Length is 5, not single char ✓
Loop through "hello":

'h' is NOT a digit → canBeInt = false, break


Skip int parsing (canBeInt is false)
Skip float parsing (canBeInt is false)
Returns new StringType("hello") ✓

Example 4: Input is "a"

Not empty ✓
Not "true" or "false" ✓
Length is 1 AND 'a' is not a digit

Returns new CharType('a') ✓
*/
OriginalType* detectType(const string& input){
    // handle empty string
    if(input.empty()) return new StringType(input);
    
    // check boolean first 
    if(input == "true") return new BoolType(true);
    if(input == "false") return new BoolType(false);
    
    // check if it's a single character (not a digit)
    if(input.length() == 1 && !isdigit(input[0]) && input[0] != '-') {
        return new CharType(input[0]);
    }
    
    // try to parse as integer first
    bool isInt = true;
    bool isFloat = true;
    int dotCount = 0;
    
    for(size_t i = 0; i < input.length(); i++) {
        char c = input[i];
        if(c == '.' && dotCount == 0) {
            dotCount++;
            isFloat = true;
            isInt = false;  // can't be int if has decimal point
        } else if(c == '-' && i == 0) {
            continue;  // negative sign at start is ok
        } else if(!isdigit(c)) {
            isInt = false;
            isFloat = false;
            break;
        }
    }
    
    // try integer if no dots
    if(isInt && dotCount == 0) {
        try {
            size_t idx; //unsigned integer type
            int intVal = stoi(input, &idx);
            if(idx == input.length()) {
                return new IntType(intVal);
            }
        } catch(...) {
            isInt = false;
        }
    }
    
    // try float if has dot
    if(isFloat && dotCount > 0) {
        try {
            size_t idx;
            float floatVal = stof(input, &idx);
            if(idx == input.length()) {
                return new FloatType(floatVal);
            }
        } catch(...) {
            isFloat = false;
        }
    }
    
    // default to string if nothing else worked
    return new StringType(input);
}

    // operator overload - lets us do cout << myType easily
    ostream& operator<<(ostream& os, OriginalType& obj) {
        obj.print();
        return os;
    }