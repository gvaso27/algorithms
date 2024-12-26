# Problem Description

You are given a sequence of N bits, indexed from 1 to N, all initialized to 0. You can perform two types of operations on this sequence:

1. **Invert Operation (denoted by 0)**: You are provided with two indices, and you need to invert all bits between these indices (inclusive). Inversion means changing the bit value to its opposite: if a bit is 0, it becomes 1, and if it is 1, it becomes 0.
2. **Count Operation (denoted by 1)**: You are provided with two indices, and you need to count how many bits in that range (inclusive) have a value of 1.

The operations are defined as follows:

- The first operation type (0) is for inverting bits.
- The second operation type (1) is for counting the number of bits with a value of 1.

You will need to handle multiple operations efficiently on the sequence of bits.

## Input

- The first line contains two integers N (1 < N ≤ 100000) and K (1 < K ≤ 100000) — the number of bits and the number of operations, respectively.
- Each of the next K lines contains three integers. The first indicates the operation type, which can only be 0 or 1. The second and third numbers denote the indices of the range on which to perform the operation.

## Output

- For each operation of the second type, output a single integer on a separate line — the count of 1s in the specified range.

## Example

**Input:**

```
7 4
0 2 4
0 3 6
1 1 3
1 5 7
```

**Output:**

```
1
2
```

### Note

After the first operation, the state of the bits will be: `0111000`. After the second operation, we get `0100110`. Therefore, after the third operation, we should output 1, and after the fourth — 2.
