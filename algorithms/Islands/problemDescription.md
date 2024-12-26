# Problem: C. Islands

## Problem Statement

You are visiting a park which has **N islands**. From each island ii, exactly one bridge was constructed. The length of that bridge is denoted by LiL\_i. The total number of bridges in the park is NN. Although each bridge was built from one island to another, now every bridge can be traversed in both directions. Also, for each pair of islands, there is a unique ferry that travels back and forth between them.

Since you like walking better than riding ferries, you want to maximize the sum of the lengths of the bridges you cross, subject to the constraints below:

1. You can start your visit at an island of your choice.
2. You may not visit any island more than once.
3. At any time you may move from your current island SS to another island DD that you have not visited before. You can go from SS to DD either by:
   * **Walking**: Only possible if there is a bridge between the two islands. With this option, the length of the bridge is added to the total distance you have walked.
   * **Ferry**: You can choose this option only if DD is not reachable from SS using any combination of bridges and/or previously used ferries. (When checking whether it is reachable or not, you consider all paths, including paths passing through islands that you have already visited.)

Note that you do not have to visit all the islands, and it may be impossible to cross all the bridges.

Write a program that, given the NN bridges along with their lengths, computes the **maximum distance you can walk** over the bridges obeying the rules described above.

---

## Input

Your program must read from the standard input the following data:

1. The first line contains the integer NN(2≤N≤1,000,000)(2 \\leq N \\leq 1,000,000), the number of islands in the park. Islands are numbered from 1 to NN, inclusive.
2. Each of the next NN lines describes a bridge. The ii-th of these lines describes the bridge constructed from island ii using two integers separated by a single space. The first integer represents the island at the other endpoint of the bridge, and the second integer represents the length LiL\_i(1≤Li≤100,000,000)(1 \\leq L\_i \\leq 100,000,000) of the bridge. You may assume that for each bridge, its endpoints are always on two different islands.

---

## Output

Your program must write to the standard output a single line containing one integer, the **maximum possible walking distance**.

---

## Example

### Input:

```
7
3 8
7 2
4 2
1 4
1 9
3 4
2 3
```

### Output:

```
24
```

### Explanation:

The N=7N = 7 bridges in the sample are:

* (1-3) with length 8
* (2-7) with length 2
* (3-4) with length 4
* (4-1) with length 1
* (5-1) with length 9
* (6-3) with length 4
* (7-2) with length 3

One way to achieve maximum walking distance follows:

1. Start on island 5.
2. Walk the bridge of length 9 to reach island 1.
3. Walk the bridge of length 8 to reach island 3.
4. Walk the bridge of length 4 to reach island 6.
5. Take the ferry from island 6 to island 7.
6. Walk the bridge of length 3 to reach island 2.

By the end, you are on island 2, and your total walking distance is 9+8+4+3=249 + 8 + 4 + 3 = 24.
