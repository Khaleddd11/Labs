#include "stringutils.h"
// i copied these functions from lab4/main.cpp here to be used in MyString.cpp 

// Get length of C-string
int str_len(const char arr[]) {
    int length = 0;
    while (arr[length] != '\0') {
        length++;
    }
    return length;
}

// Copy string
void str_cpy(char dest[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Compare strings
int str_cmp(const char str1[], const char str2[]) {
    int len1 = str_len(str1);
    int len2 = str_len(str2);

    if (len1 > len2) return 1;
    if (len2 > len1) return -1;

    int i = 0;
    while (str1[i] != '\0') {
        if (str1[i] > str2[i]) return 5;
        else if (str1[i] < str2[i]) return -5;
        i++;
    }
    return 0;
}

// Concatenate strings
void str_concat(char str1[], const char str2[], int size1_str) {
    int str1_length = str_len(str1);
    int str2_length = str_len(str2);

    int i = str1_length;
    for (int j = 0; j < str2_length; j++) {
        str1[i++] = str2[j];
    }
    str1[i] = '\0';
}

// Convert to uppercase
void tocapital_str(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
        i++;
    }
}

// Convert to lowercase
void tolower_str(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
        i++;
    }
}

// Find substring
int str_find(const char str[], const char substr[]) {
    int strLen = str_len(str);
    int subLen = str_len(substr);
    
    if (subLen > strLen) return -1;
    
    for (int i = 0; i <= strLen - subLen; i++) {
        bool match = true;
        for (int j = 0; j < subLen; j++) {
            if (str[i + j] != substr[j]) {
                match = false;
                break;
            }
        }
        if (match) return i;
    }
    return -1;
}