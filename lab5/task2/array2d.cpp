#include <iostream>

using namespace std;

// ============================================================================
// Function: printArray2D
// Purpose: Print a 2D array using pointers
// Parameters:
//   - arr: pointer to first element of 2D array
//   - rows: number of rows
//   - cols: number of columns
// ============================================================================
void printArray2D(int *arr, int rows, int cols) {
    cout << "===== 2D ARRAY OUTPUT USING POINTERS =====" << endl;
    cout << endl;
    
    // Loop through each row
    for (int i = 0; i < rows; i++) {
        cout << "Row " << i << ": ";
        
        // Loop through each column
        for (int j = 0; j < cols; j++) {
            // ============================================================
            // POINTER ARITHMETIC EXPLANATION:
            // In a 2D array stored in memory, elements are in a single line:
            // arr[0][0], arr[0][1], arr[0][2], arr[1][0], arr[1][1], ...
            //
            // To find element at [i][j]:
            //   Position = (row * number_of_columns) + column
            //   Position = (i * cols) + j
            //
            // Then use pointer: *(arr + position)
            // ============================================================
            
            int position = (i * cols) + j;  // Calculate position in memory
            int value = *(arr + position);  // Get value using pointer
            
            cout << value << "\t";  // Print with tab spacing
        }
        cout << endl;  // New line after each row
    }
}

int main() {
    // Define number of rows and columns
    const int ROWS = 3;
    const int COLS = 4;
    
    // Create a 2D array
    int myArray[ROWS][COLS] = {
        {1,  2,  3,  4},    // Row 0
        {5,  6,  7,  8},    // Row 1
        {9, 10, 11, 12}     // Row 2
    };
    
    // Display original array info
    cout << "Array size: " << ROWS << " rows x " << COLS << " columns" << endl;
    cout << endl;
    
    // ============================================================
    // Pass array to function using pointer
    // &myArray[0][0] gives address of first element
    // This is the same as (int*)myArray
    // ============================================================
    printArray2D(&myArray[0][0], ROWS, COLS);
    
    cout << endl;
    
    // ============================================================
    // BONUS: Show how pointer arithmetic works
    // ============================================================
    cout << "===== POINTER ARITHMETIC DEMO =====" << endl;
    
    int *ptr = &myArray[0][0];  // Point to first element
    
    cout << "Address of first element: " << ptr << endl;
    cout << "Value at first element:   " << *ptr << endl;
    cout << endl;
    
    cout << "Accessing element [1][2] using pointer:" << endl;
    cout << "  Position = (1 * 4) + 2 = 6" << endl;
    cout << "  Value = *(ptr + 6) = " << *(ptr + 6) << endl;
    
    return 0;
}