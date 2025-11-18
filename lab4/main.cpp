#include <iostream>
using namespace std;


// source: https://stackoverflow.com/questions/33849637/convert-a-single-character-to-lowercase-in-c-tolower-is-returning-an-integer

//Generally speaking to convert an uppercase character to a lowercase, 
//you only need to add 32 to the uppercase character 
//as this number is the ASCII code difference between lowercase and uppercase characters,
// e.g., 'a'-'A'=97-67=32.


void tocapital_str(char str[]) {
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
        i++;
    }
}

void tolower_str(char str[]) {
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
        i++;
    }
}



int str_len(char arr[]) {
    int length = 0; // i will store the result here
    while (arr[length] != '\0') {
        length++;
    }
    return length;
}

void str_concat(char str1[], char str2[], int size1_str) {
    int str1_length = str_len(str1);
    int str2_length = str_len(str2);

    int empty_space_str1 = size1_str - str1_length - 1; //  here i added-1 for null terminator


if (empty_space_str1 < str2_length) {
        cout << "Error: Not enough space to concatenate! Need " 
             << str2_length << " chars, but only have " 
             << empty_space_str1 << "." << endl;
        return;
}

    // Append str2 to str1
    int i = str1_length;
    for (int j = 0; j < str2_length; j++) {
        str1[i++] = str2[j];
    }

    str1[i] = '\0';
}



void str_cpy(char dest[], char src[]) {
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
}



int str_cmp(char str1[], char str2[]) {
    // we get firstt the lengths
    int len1 = str_len(str1);
    int len2 = str_len(str2);

    // then we compare sizes f
    if (len1 > len2) {
        return 1;
    }
    if (len2 > len1) {
        return -1;
    }

    // if sizes are equal, we then compare characters one by one
    int i = 0;
    while (str1[i] != '\0') {
        if (str1[i] > str2[i]) {
            return 5; // First char is bigger in ASCII
        }
        else if (str1[i] < str2[i]) {
            return -5; // Second char is bigger in ASCII
        }
        i++;
    }

    // if we finish the loop, they are identical
    return 0;
}



int main() {

    // Testing str_len
    cout << "===== Testing str_len =====\n";
    char test1[] = "C++ is the best course";
    cout << "Length: " << str_len(test1) << "\n\n";


    
    // Test str_cmp
    cout << "===== Testing str_cmp =====\n";
    
    // Case 1: Size Difference
    char longStr[] = "Hello World"; 
    char shortStr[] = "Hello";
    cout << "Hello World vs Hello: " << str_cmp(longStr, shortStr) << endl;

    // Case 2: Size Difference
    char longStr2[] = "Hello "; 
    char shortStr2[] = "Hello World";
    cout << "Hello vs Hello World: " << str_cmp(longStr2, shortStr2) << endl;
    
    // Case 3: Equal Size, Different Char
    char a[] = "ABC";
    char b[] = "ABD";
    cout << "ABC vs ABD : " << str_cmp(a, b) << endl; // C is smaller than D

    // Case 4: Equal Size, Different Char
    char c[] = "ABD";
    char d[] = "ABC";
    cout << "ABD vs ABC : " << str_cmp(c, d) << endl; // C is smaller than D

    // Case 5: Equal Size, Equal Char
    cout << "ABC vs ABC: " << str_cmp(a, a) << "\n\n";


    // Test tolower_str
    cout << "===== Testing tolower_str =====\n";
    char lowerTest[] = "HeLLo KHALed";
    cout << "Before: " << lowerTest << endl;
    tolower_str(lowerTest);
    cout << "After : " << lowerTest << "\n\n";

    // Test tocapital_str
    cout << "===== Testing tocapital_str =====\n";
    char upperTest[] = "hello khALed!";
    cout << "Before: " << upperTest << endl;
    tocapital_str(upperTest);
    cout << "After : " << upperTest << "\n\n";

    // Test str_concat
    cout << "===== Testing str_concat =====\n";
    char s1[] = "Khaled";
    char s2[] = "Cherif";
    cout << "Before: " << s1 << endl;
    str_concat(s1, s2, 20);
    cout << "After : " << s1 << "\n\n";

    // Test str_cpy
    cout << "===== Testing str_cpy =====\n";
    char src[] = "Copy this text";
    char dest[50];
    str_cpy(dest, src);
    cout << "Source: " << src << endl;
    cout << "Dest  : " << dest << endl << endl;

    return 0;
}
