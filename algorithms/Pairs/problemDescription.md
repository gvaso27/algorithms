# Problem: Pairs

## Problem Statement

You are given two sequences \( A \) and \( B \). The first sequence consists of \( N \) integers, and the second sequence consists of \( M \) integers. You need to choose an \( X \)-element subset from the first sequence and an \( X \)-element subset from the second sequence. Both subsets must be sorted.

Count the number of ways to choose the subsets such that every element of the sorted subset from \( A \) is greater than the corresponding element of the sorted subset from \( B \). Two subsets are considered different if they are chosen from different indices, even if the elements are the same.

## Input Format

- The first line contains three integers: \( N \), \( M \), and \( X \) (1 < N <= 1000, 1 < M <= 1000, 1 <= X <= 10, and X <= min(N, M)).
- The second line contains \( N \) integers: the elements of sequence \( A \).
- The third line contains \( M \) integers: the elements of sequence \( B \).

## Output Format

Output a single integer — the number of valid ways to choose subsets, modulo 1,000,000,009.

## Example

### Input

```
4 5 2
3 7 7 8
1 4 6 8 11
```

### Output

```
15
```

### Explanation

The valid pairs of subsets are:

1. \( A \): \( \{3, 7\} \) (first 7), \( B \): \( \{1, 4\} \)
2. \( A \): \( \{3, 7\} \) (second 7), \( B \): \( \{1, 4\} \)
3. \( A \): \( \{3, 7\} \) (first 7), \( B \): \( \{1, 6\} \)
4. \( A \): \( \{3, 7\} \) (second 7), \( B \): \( \{1, 6\} \)
5. \( A \): \( \{3, 8\} \), \( B \): \( \{1, 4\} \)
6. \( A \): \( \{3, 8\} \), \( B \): \( \{1, 6\} \)
7. \( A \): \( \{7, 7\} \), \( B \): \( \{1, 4\} \)
8. \( A \): \( \{7, 7\} \), \( B \): \( \{1, 6\} \)
9. \( A \): \( \{7, 7\} \), \( B \): \( \{4, 6\} \)
10. \( A \): \( \{7, 8\} \) (first 7), \( B \): \( \{1, 4\} \)
11. \( A \): \( \{7, 8\} \) (second 7), \( B \): \( \{1, 4\} \)
12. \( A \): \( \{7, 8\} \) (first 7), \( B \): \( \{1, 6\} \)
13. \( A \): \( \{7, 8\} \) (second 7), \( B \): \( \{1, 6\} \)
14. \( A \): \( \{7, 8\} \) (first 7), \( B \): \( \{4, 6\} \)
15. \( A \): \( \{7, 8\} \) (second 7), \( B \): \( \{4, 6\} \)

## Constraints

- 1 < N <= 1000
- 1 < M <= 1000
- 1 <= X <= 10
- X <= min(N, M)

## Notes

- Modulo 1,000,000,009 should be applied to the result.
- Sorting and proper handling of indices are essential to ensure correctness.
