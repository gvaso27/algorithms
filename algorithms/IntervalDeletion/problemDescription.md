#### Description:

You are given **N** segments (intervals) on a number line, where each segment is defined by two integers representing its left and right endpoints. Each segment covers a range of unit intervals on the number line. The goal is to remove **K** segments in such a way that the remaining segments cover the maximum possible number of unit intervals.

#### Input:

* The first line contains two integers: **N** (the number of segments) and **K** (the number of segments to be removed), where 1≤K≤N≤100,000 and the coordinates are in the range of (0 to 10)^9.
* The next **N** lines each contain two integers, representing the left and right endpoints of the segment.

#### Output:

* Print a single integer: the maximum number of unit intervals covered by the remaining segments after removing **K** of them.

#### Example:

**Input:**

3 2
1 8
7 15
2 14

**Output:**

12

### Explanation:

In this problem, we are given intervals on a number line, and we need to remove a certain number of them while maximizing the coverage of the remaining intervals. The solution involves sorting the segments and then using a dynamic programming approach to efficiently calculate the maximum coverage, ensuring that overlapping and redundant intervals are properly handled.

The strategy involves:

1. Sorting the intervals based on their left endpoint.
2. Selecting segments to maximize coverage, skipping over those that contribute less.
3. Using dynamic programming to explore possible ways to remove exactly **K** segments.
