#include "MyString.h"
#include <iostream>

using namespace std;

int main() {
    cout << "========================================" << endl;
    cout << "   MY STRING CLASS" << endl;
    cout << "========================================" << endl;
    
    // ========================================================================
    // 1. CREATE STRINGS
    // ========================================================================
    cout << "\n--- Creating Strings ---" << endl;
    
    MyString s1;              // Empty string
    MyString s2("Hello");     // From C-string
    MyString s3("World");
    
    cout << "s1: \"" << s1 << "\"" << endl;
    cout << "s2: \"" << s2 << "\"" << endl;
    cout << "s3: \"" << s3 << "\"" << endl;
    
    // ========================================================================
    // 2. DEEP COPY (Copy Constructor)
    // ========================================================================
    cout << "\n--- Now i am testing Deep Copy (Copy Constructor) ---" << endl;
    MyString s4 = s2;  // Copy constructor
    
    cout << "s2: \"" << s2 << "\"" << endl;
    cout << "s4 (copy of s2): \"" << s4 << "\"" << endl;
    
    // Modify s4 to prove independence
    s4 = "Changed";
    cout << "\nAfter changing s4:" << endl;
    cout << "s2: \"" << s2 << "\" (unchanged)" << endl;
    cout << "s4: \"" << s4 << "\" (changed)" << endl;
    
    // ========================================================================
    // 3. ASSIGNMENT
    // ========================================================================
    cout << "\n--- Assignment Operator ---" << endl;
    MyString s5;
    s5 = s2;  // Assignment
    cout << "s5 = s2: \"" << s5 << "\"" << endl;
    
    s5 = "Direct";  // Assignment from C-string
    cout << "s5 = \"Direct\": \"" << s5 << "\"" << endl;
    
    // ========================================================================
    // 4. CONCATENATION
    // ========================================================================
    cout << "\n--- Concatenation ---" << endl;
    
    MyString s6 = s2 + s3;  // s2 + s3
    cout << s2 << " + " << s3 << " = \"" << s6 << "\"" << endl;
    
    MyString s7 = s2 + " C++";  // String + C-string
    cout << s2 << " + \" C++\" = \"" << s7 << "\"" << endl;
    
    // ========================================================================
    // 5. APPEND (+=)
    // ========================================================================
    cout << "\n--- Append Operator (+=) ---" << endl;
    MyString s8("Good");
    cout << "Before: s8 = \"" << s8 << "\"" << endl;
    
    s8 += " Morning";
    cout << "After s8 += \" Morning\": \"" << s8 << "\"" << endl;
    
    MyString s9(" Everyone");
    s8 += s9;
    cout << "After s8 += s9: \"" << s8 << "\"" << endl;

cout<< "\n-- testing increment operator --"<<endl;
    MyString inc1("Hello");
    cout << "Original: \"" << inc1 << "\"" << endl;
    
    ++inc1;
    cout << "After ++inc1: \"" << inc1 << "\"" << endl;

    cout << "\n-- tetsing decrmeent operator --" <<endl;
     MyString dec1("Test!");
    cout << "\nOriginal: \"" << dec1 << "\"" << endl;
    
    --dec1;
    cout << "After --dec1: \"" << dec1 << "\"" << endl;
    
    --dec1;
    cout << "After another --dec1: \"" << dec1 << "\"" << endl;

      cout << "testing multiplcation operator \"" << endl;
    
    MyString mult1("Ha");
    cout << "mult1: \"" << mult1 << "\"" << endl;
    
    MyString mult2 = mult1 * 3;
    cout << "mult1 * 3: \"" << mult2 << "\"" << endl;
    
   /* MyString mult3 = 5 * mult1;
    cout << "5 * mult1: \"" << mult3 << "\"" << endl;
    */
    MyString mult4("Go! ");
    cout << "\nmult4: \"" << mult4 << "\"" << endl;
    cout << "mult4 * 4: \"" << (mult4 * 4) << "\"" << endl;
    
    
    
    // ========================================================================
    // 6. COMPARISON
    // ========================================================================
    cout << "\n--- Comparison Operators ---" << endl;
    MyString a("Apple");
    MyString b("Banana");
    MyString c("Apple");
    
    cout << "a = \"" << a << "\"" << endl;
    cout << "b = \"" << b << "\"" << endl;
    cout << "c = \"" << c << "\"" << endl;
    
    cout << "a == c: " << (a == c ? "true" : "false") << endl;
    cout << "a != b: " << (a != b ? "true" : "false") << endl;
    cout << "a < b: " << (a < b ? "true" : "false") << endl;
    cout << "b > a: " << (b > a ? "true" : "false") << endl;
    
    // ========================================================================
    // 7. ARRAY ACCESS
    // ========================================================================
    cout << "\n--- Array Access Operator [] ---" << endl;
    MyString word("Hello");
    cout << "word = \"" << word << "\"" << endl;
    cout << "word[0] = '" << word[0] << "'" << endl;
    cout << "word[1] = '" << word[1] << "'" << endl;
    
    // Modify character
    word[0] = 'J';
    cout << "After word[0] = 'J': \"" << word << "\"" << endl;
    
    // ========================================================================
    // 8. LENGTH AND EMPTY
    // ========================================================================
    cout << "\n--- Length and Empty ---" << endl;
    MyString test1("Testing");
    MyString test2;
    
    cout << "test1 = \"" << test1 << "\", length = " << test1.length() << endl;
    cout << "test2 = \"" << test2 << "\", length = " << test2.length() << endl;
    cout << "test1.isEmpty(): " << (test1.isEmpty() ? "true" : "false") << endl;
    cout << "test2.isEmpty(): " << (test2.isEmpty() ? "true" : "false") << endl;
    
    // ========================================================================
    // 9. CASE CONVERSION
    // ========================================================================
    cout << "\n--- Case Conversion ---" << endl;
    MyString text("Hello World");
    cout << "Original: \"" << text << "\"" << endl;
    cout << "Uppercase: \"" << text.toUpper() << "\"" << endl;
    cout << "Lowercase: \"" << text.toLower() << "\"" << endl;
    cout << "Original (unchanged): \"" << text << "\"" << endl;
    
    // ========================================================================
    // 10. FIND SUBSTRING
    // ========================================================================
    cout << "\n--- Find Substring ---" << endl;
    MyString sentence("The quick brown fox");
    cout << "Sentence: \"" << sentence << "\"" << endl;
    
    int pos1 = sentence.find("quick");
    int pos2 = sentence.find("fox");
    int pos3 = sentence.find("cat");
    
    cout << "Position of 'quick': " << pos1 << endl;
    cout << "Position of 'fox': " << pos2 << endl;
    cout << "Position of 'cat': " << pos3 << " (not found)" << endl;
    
    // ========================================================================
    // 11. CLEAR
    // ========================================================================
    cout << "\n--- Clear String ---" << endl;
    MyString temp("Something");
    cout << "Before clear: \"" << temp << "\", length = " << temp.length() << endl;
    temp.clear();
    cout << "After clear: \"" << temp << "\", length = " << temp.length() << endl;
    
    // ========================================================================
    // 12. INPUT (optional - uncomment to test)
    // ========================================================================
    /*
    cout << "\n--- User Input ---" << endl;
    MyString userInput;
    cout << "Enter a word: ";
    cin >> userInput;
    cout << "You entered: \"" << userInput << "\"" << endl;
    */
    
    cout << "\n========================================" << endl;
    cout << "   this is the enddd" << endl;
    cout << "========================================" << endl;
    cout << "All memory will be freed" << endl;
    
    return 0;
    // Destructors called here
}