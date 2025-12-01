#ifndef STRINGUTILS_H
#define STRINGUTILS_H

// Lab 4 string functions
int str_len(const char arr[]);
void str_cpy(char dest[], const char src[]);
int str_cmp(const char str1[], const char str2[]);
void str_concat(char str1[], const char str2[], int size1_str);
void tocapital_str(char str[]);
void tolower_str(char str[]);
int str_find(const char str[], const char substr[]);

#endif