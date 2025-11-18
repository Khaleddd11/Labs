#ifndef MAGICSQUARE_H
#define MAGICSQUARE_H

// Function to get number input from user
// Returns: positive number if valid, -1 if error, -2 if back to menu
int getNumberInput();

// Function to create and display magic square with animation
// Parameter: n - size of magic square (must be odd)
void createMagicSquare(int n);

#endif