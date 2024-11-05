## Problem Description

During autumn, birds migrate to warmer countries. Before crossing the Black Sea, they rest on a power transmission line, which can be represented as N (1≤N≤500000) consecutive positions numbered from 1 to N. Initially, all positions are empty. Throughout the day, M (1≤M≤300000) events occur on the transmission line.

Each event is one of two types:

1. A flock of p birds (1 <= p <= N) arrives. They want to land on a continuous block of p positions. If multiple such blocks exist, the birds choose the block that starts with the smallest position number. If no such block exists, the birds continue flying without rest.
2. Given two numbers a and b (1 <= a,b <= N), all birds in the range [a,a+b-1] leave the transmission line, and those positions become available.

## Input

* The first line contains two integers N and M.
* The next M lines each describe an event:
  * Format "1 p": indicates a flock of p birds has arrived
  * Format "2 a b": indicates positions in range [a,a+b-1] have been freed

## Output

* For each type 1 event, output a single line containing:
  * The smallest position number of the block where the birds landed
  * OR 0 if the flock couldn't find enough free consecutive positions and flew away

## Constraints

* 1 ≤ N ≤ 500,000
* 1 ≤ M ≤ 300,000
* For type 1 events: 1 ≤ p ≤ N
* For type 2 events: 1 ≤ a,b ≤ N

## Example

### Input

<span><span>10 4
</span></span><span>1 6
</span><span>2 2 3
</span><span>1 5
</span><span>1 2</span></code></div></div></div></pre>

### Output

<span><span>1
</span></span><span>0
</span><span>2</span></code></div></div></div></pre>

### Explanation

1. Initially, there are 10 empty positions.
2. First event: A flock of 6 birds arrives and occupies positions 1-6.
3. Second event: Positions 2-4 are freed.
4. Third event: A flock of 5 birds arrives but can't find enough consecutive free positions, so they fly away (output 0).
5. Fourth event: A flock of 2 birds arrives and occupies positions 2-3.

## Solution Notes

The problem can be efficiently solved using a segment tree data structure that maintains:

* Maximum continuous free space in each segment
* Maximum free space from the left end (prefix)
* Maximum free space from the right end (suffix)
* Lazy propagation for range updates

This allows for O(log N) complexity for both finding the first suitable position for a flock and updating ranges when birds leave.
