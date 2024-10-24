### Problem Description: Sum of Primes

Given a positive integer NN**N** (where 2<N<50000), you need to determine the number of ways to express N as the sum of two or more prime numbers. SUM(9) = 4 because:

* 9=2+2+2+3
* 9=2+2+5
* 9=2+7
* 9=3+3+3

P is the smallest prime that is greater than N.

### Input:

* A single integer **N**.

### Output:

* A single integer representing SUM(N) % P.

### Example:

#### Input:

9

#### Output:

4

### Explanation:

In the given example, you can express the number 9 in four distinct ways using the sums of prime numbers. The smallest prime number greater than 9 is 11. The output is the result of SUM(9)mod  11\\text{SUM}(9) \\mod 11**SUM**(**9**)**mod**11, which is 4.

### Implementation:

The provided C++ code implements the above logic using dynamic programming to calculate SUM(N)\\text{SUM}(N)**SUM**(**N**) and also finds the smallest prime PP**P** greater than NN**N**.

Here's a brief overview of the algorithm:

1. **Sieve of Eratosthenes** is used to find all prime numbers up to NN**N**.
2. A dynamic programming approach is used to count the number of ways to form NN**N** using the identified prime numbers.
3. The code then identifies the smallest prime number greater than NN**N** and calculates the remainder of SUM(N)\\text{SUM}(N)**SUM**(**N**) when divided by this prime.

### Note:

Make sure to run the code in an environment that supports C++ compilation, as it includes specific input/output operations suitable for competitive programming contexts.
