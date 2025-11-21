#ifndef SWAP_H
#define SWAP_H

// ============================================================================
// Swap using XOR
// How it works:
//   XOR has a special property: a ^ a = 0 and a ^ 0 = a
//   Step 1: a = a ^ b  (a now holds combined info of both)
//   Step 2: b = a ^ b  (extracts original a, puts in b)
//   Step 3: a = a ^ b  (extracts original b, puts in a)
// Note: Works only with integers, no extra memory needed!
// ============================================================================
void swapXOR(int &a, int &b);

// ============================================================================
// Swap using Addition and Subtraction
// How it works:
//   Step 1: a = a + b  (a now holds sum of both)
//   Step 2: b = a - b  (subtracts original b, leaves original a)
//   Step 3: a = a - b  (subtracts original a, leaves original b)
// Note: Be careful with very large numbers (overflow possible)
// ============================================================================
void swapAddSub(int &a, int &b);

#endif