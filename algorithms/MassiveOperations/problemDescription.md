#### Description:

You are given an array of **N** non-negative integers. Your program should handle **Q** operations of three types:

1. Add a given value to all elements in a specified subarray.
2. Find the minimum element within a specified subarray.
3. Calculate the sum of elements within a specified subarray.

#### Input:

* The first line contains two integers: **N** (number of elements in the array) and **Q** (number of operations), where 1≤N≤200,000 and 1≤Q≤100,000.
* The second line contains **N** non-negative integers representing the array, where each element does not exceed 100,000.
* Each of the next **Q** lines represents an operation:

  * **M A B**: Find the minimum element in the subarray from index **A** to **B** (inclusive).
  * **P A B C**: Add the integer **C** to all elements in the subarray from index **A** to **B** (inclusive).
  * **S A B**: Find the sum of elements in the subarray from index **A** to **B** (inclusive).

#### Output:

* For each **M** or **S** operation, output the corresponding result in a new line.

#### Example:

**Input:**

4 5
3 1 2 4
M 3 4
S 1 3
P 2 3 1
M 3 4
S 1 3

**Output:**

2
6
3
8

### Explanation:

1. The initial array is: `[3, 1, 2, 4]`
2. First operation **M 3 4**: Find the minimum between elements 3 and 4 → the result is `2`.
3. Second operation **S 1 3**: Find the sum of elements from index 1 to 3 → the sum is `3 + 1 + 2 = 6`.
4. Third operation **P 2 3 1**: Add `1` to elements from index 2 to 3 → the array becomes `[3, 2, 3, 4]`.
5. Fourth operation **M 3 4**: Find the minimum between elements 3 and 4 → the result is `3`.
6. Fifth operation **S 1 3**: Find the sum of elements from index 1 to 3 → the sum is `3 + 2 + 3 = 8`.

The solution uses a segment tree with lazy propagation to handle the operations efficiently for large input sizes.
