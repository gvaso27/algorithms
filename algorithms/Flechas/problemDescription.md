### Problem Description:

You are given a grid of size `n x n` where each cell contains one of the following characters:

* `'L'`: Represents a left-facing arrow.
* `'U'`: Represents an upward-facing arrow.
* `'R'`: Represents a right-facing arrow.
* `'D'`: Represents a downward-facing arrow.
* `'E'`: Represents an empty cell.

The goal is to determine if it's possible to clear all arrows from the grid following a specific set of rules. An arrow is cleared when it reaches the edge of the grid or if another arrow clears it by moving into the same row or column. Once an arrow is cleared, it turns into an empty cell (`'E'`), and this may trigger other arrows to move and clear.

### Rules for Clearing Arrows:

1. **Left arrows ('L')** can move leftwards until they either hit an edge or encounter a non-empty cell.
2. **Right arrows ('R')** can move rightwards, subject to the same conditions.
3. **Up arrows ('U')** move upwards, while **Down arrows ('D')** move downwards, both following the same rules for movement and clearing.
4. The process starts by clearing any arrows that are on the grid edges and can move towards an empty cell or edge.

### Input:

* The first line contains an integer `T`, the number of test cases.
* For each test case:
  * An integer `n` is provided, representing the grid size (`n x n`).
  * The next `n` lines contain a string of length `n` representing the grid configuration.

### Output:

* For each test case, output either `"POSIBLE"` if it is possible to clear all arrows from the grid, or `"IMPOSIBLE"` if it's not possible.

### Example:

#### Input:

2
3
LRD
UDU
LRD
4
LURE
URDL
RDLU
EULD

#### Output:

IMPOSIBLE
POSIBLE

### Explanation:

* In the first test case, not all arrows can be cleared following the rules, so the output is "IMPOSIBLE."
* In the second test case, it is possible to clear all arrows, so the output is "POSIBLE."

The algorithm works by simulating the process of clearing arrows, starting from the edges and progressively updating the grid until no further changes can be made. If all cells can be turned into empty cells, the result is "POSIBLE." Otherwise, the result is "IMPOSIBLE."
