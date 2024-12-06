# Problem: Restaurant

## Problem Statement

Buba's restaurant has become very popular, and every day N customers visit it in the same order. The restaurant serves M dishes, numbered from 1 to M. Each customer i orders exactly one dish P_i (1 <= P_i <= M).

After serving K different dishes in a group, it takes K * K time to clean the restaurant. To minimize the total cleaning time, Buba groups customers while maintaining their original order. After each group's departure, Buba cleans the restaurant and brings in the next group.

Calculate the minimum total cleaning time required to serve all customers and clean the restaurant.

## Input Format

- The first line contains two integers: N and M (1 <= N <= 40,000, 1 <= M <= N).
- The next N lines contain one integer each, representing P_i, the dish ordered by the i-th customer.

## Output Format

Output a single integer — the minimum total cleaning time.

## Example

### Input

```
13 4
1
2
1
3
2
2
3
4
3
4
3
1
4
```

### Output

```
11
```

### Explanation

The groups of customers based on the optimal solution are as follows:

- The first four groups contain one customer each.
- The fifth group contains 2 customers.
- The sixth group contains 5 customers, who order dishes {3, 4, 3, 4, 3}. Cleaning after this group takes 4 units of time because K = 4.
- The last two groups contain one customer each.

The total cleaning time is 11.

## Constraints

- 1 <= N <= 40,000
- 1 <= M <= N
- 1 <= P_i <= M

## Notes

- Grouping customers optimally minimizes the total cleaning time.
- Use efficient algorithms to handle the constraints on N.
