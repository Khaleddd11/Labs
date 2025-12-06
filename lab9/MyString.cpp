#include "MyString.h"
#include "stringutils.h"  // Our implemented Lab 4 functions 

using namespace std;

// ============================================================================
// CONSTRUCTORS AND DESTRUCTOR
// ============================================================================

// Default constructor: creates empty string
MyString::MyString() {
    len = 0;
    str = new char[1];  // Allocate space for null terminator
    str[0] = '\0';      // Empty string
    
    cout << "[Constructor] Empty string created" << endl;
}

// Parameterized constructor: creates string from C-string
MyString::MyString(const char *s) {
    if (s == nullptr) {
        // If null pointer passed, create empty string
        len = 0;
        str = new char[1];
        str[0] = '\0';
    } else {
        // Calculate length
        len = str_len(s);
        
        // Allocate memory (length + 1 for null terminator)
        str = new char[len + 1];
        
        // Copy characters
        str_cpy(str, s);
    }
    
    cout << "[Constructor] String created: \"" << str << "\"" << endl;
}

// Copy constructor: creates DEEP COPY
MyString::MyString(const MyString &other) {
    len = other.len;
    
    // Allocate NEW memory (deep copy)
    str = new char[len + 1];
    
    // Copy all characters
    str_cpy(str, other.str);
    
    cout << "[Copy Constructor] Deep copy created: \"" << str << "\"" << endl;
}

// Destructor: free memory
MyString::~MyString() {
    delete[] str;
    cout << "[Destructor] String destroyed" << endl;
}

// ============================================================================
// ASSIGNMENT OPERATORS
// ============================================================================

// Assignment from MyString: s1 = s2
MyString& MyString::operator=(const MyString &other) {
    // Check for self-assignment
    if (this == &other) {
        return *this;
    }
    
    // Free old memory
    delete[] str;
    
    // Copy length
    len = other.len;
    
    // Allocate new memory
    str = new char[len + 1];
    
    // Copy characters
    str_cpy(str, other.str);
    
    cout << "[Assignment] Assigned: \"" << str << "\"" << endl;
    
    return *this;
}

// Assignment from C-string: s1 = "Hello"
MyString& MyString::operator=(const char *s) {
    // Free old memory
    delete[] str;
    
    if (s == nullptr) {
        len = 0;
        str = new char[1];
        str[0] = '\0';
    } else {
        len = str_len(s);
        str = new char[len + 1];
        str_cpy(str, s);
    }
    
    cout << "[Assignment] Assigned from C-string: \"" << str << "\"" << endl;
    
    return *this;
}

// ============================================================================
// STRING CONCATENATION
// ============================================================================

// Concatenation: s1 + s2 (returns new string)
MyString MyString::operator+(const MyString &other) const {
    // Calculate total length
    int newLen = len + other.len;
    
    // Create temporary array
    char *temp = new char[newLen + 1];
    
    // Copy first string
    str_cpy(temp, str);
    
    // Concatenate second string
    str_concat(temp, other.str, newLen + 1);
    
    // Create new MyString
    MyString result(temp);
    
    // Free temporary memory
    delete[] temp;
    
    return result;
}

// Concatenation with C-string: s1 + "world"
MyString MyString::operator+(const char *s) const {
    if (s == nullptr) {
        return *this;
    }
    
    int sLen = str_len(s);
    int newLen = len + sLen;
    
    char *temp = new char[newLen + 1];
    str_cpy(temp, str);
    str_concat(temp, s, newLen + 1);
    
    MyString result(temp);
    delete[] temp;
    
    return result;
}

// Append: s1 += s2 (modifies s1)
MyString& MyString::operator+=(const MyString &other) {
    int newLen = len + other.len;
    char *temp = new char[newLen + 1];
    
    str_cpy(temp, str);
    str_concat(temp, other.str, newLen + 1);
    
    delete[] str;
    len = newLen;
    str = temp;
    
    return *this;
}

// Append C-string: s1 += "world"
MyString& MyString::operator+=(const char *s) {
    if (s == nullptr) {
        return *this;
    }
    
    int sLen = str_len(s);
    int newLen = len + sLen;
    char *temp = new char[newLen + 1];
    
    str_cpy(temp, str);
    str_concat(temp, s, newLen + 1);
    
    delete[] str;
    len = newLen;
    str = temp;
    
    return *this;
}

// Prefix increment: ++ (adds space at end)
MyString& MyString::operator++() {
     char *newString = new char[len+2];
     for ( int i =0; i<len;i++){
        newString[i]=str[i];
     }

     // add sapce at the end of index
     newString[len] = ' ';
     newString[len+1]= '\0'; 
     //  Delete the old memory to prevent leaks
    delete[] str;

    //  Update the pointer and length
    str = newString;
    len++;

    // Return reference to self
    return *this; 
}

//remove last char
MyString& MyString::operator--() { 
    if (len == 0) {
        return *this; 
    }
    // new size will be decraese by 1, however we initialaized with =len because
    // null terminator will take last elmeent
    char *newString= new char[len];
    // i want here to stop before last one so i can insert null terminator
    for (int i =0 ; i< len-1;i++){
        newString[i]=str[i];
    }
    newString[len-1]='\0';
    delete []str;
    str = newString;
    len--;  

    return *this;

}

//repeat string
MyString& MyString::operator*(int x){
    char *newString = new char[(len * x)+1];
    for( int i=0,j=0; i<len * x;i++,j++){
        if(j>=len){
        j=0;
        newString[i]=str[j];
        }
        else{
            newString[i]=str[j];

        } 
    }
    newString[len*x]='\0';
    delete[] str;
    str= newString;
    len = len * x;
    return *this;

}

//friend function for repeating string
MyString operator*(int x, MyString s){

    return s * x;

}




// ============================================================================
// COMPARISON OPERATORS
// ============================================================================

// Equal: s1 == s2
bool MyString::operator==(const MyString &other) const {
    return (str_cmp(str, other.str) == 0);
}

// Not equal: s1 != s2
bool MyString::operator!=(const MyString &other) const {
    return !(*this == other);
}

// Less than: s1 < s2 (lexicographic)
bool MyString::operator<(const MyString &other) const {
    return (str_cmp(str, other.str) < 0);
}

// Greater than: s1 > s2
bool MyString::operator>(const MyString &other) const {
    return (str_cmp(str, other.str) > 0);
}

// ============================================================================
// ARRAY ACCESS OPERATOR
// ============================================================================

// Access character: s[i]
char& MyString::operator[](int index) {
    if (index < 0 || index >= len) {
        cout << "Error: Index out of bounds!" << endl;
        return str[0];  // Return first char as fallback
    }
    return str[index];
}

// Const version
const char& MyString::operator[](int index) const {
    if (index < 0 || index >= len) {
        cout << "Error: Index out of bounds!" << endl;
        return str[0];
    }
    return str[index];
}

// ============================================================================
// STREAM OPERATORS
// ============================================================================

// Output: cout << s
ostream& operator<<(ostream &out, const MyString &s) {
    out << s.str;
    return out;
}

// Input: cin >> s (reads one word)
istream& operator>>(istream &in, MyString &s) {
    char buffer[1000];  // Temporary buffer
    in >> buffer;
    
    // Use assignment operator
    s = buffer;
    
    return in;
}

// ============================================================================
// UTILITY METHODS
// ============================================================================

// Get length
int MyString::length() const {
    return len;
}

// Check if empty
bool MyString::isEmpty() const {
    return (len == 0);
}

// Get C-string
const char* MyString::c_str() const {
    return str;
}

// Convert to uppercase
MyString MyString::toUpper() const {
    char *temp = new char[len + 1];
    
    for (int i = 0; i < len; i++) {
        temp[i] = toupper(str[i]);
    }
    temp[len] = '\0';
    
    MyString result(temp);
    delete[] temp;
    
    return result;
}

// Convert to lowercase
MyString MyString::toLower() const {
    char *temp = new char[len + 1];
    
    for (int i = 0; i < len; i++) {
        temp[i] = tolower(str[i]);
    }
    temp[len] = '\0';
    
    MyString result(temp);
    delete[] temp;
    
    return result;
}

// Find substring (returns index or -1)
int MyString::find(const char *substr) const {
    if (substr == nullptr) {
        return -1;
    }
    
    return str_find(str, substr);  // Using our custom function
}


// Clear string
void MyString::clear() {
    delete[] str;
    len = 0;
    str = new char[1];
    str[0] = '\0';
}

// Display
void MyString::display() const {
    cout << str;
}