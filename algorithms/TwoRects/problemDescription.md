### Problem Description: Two Rectangles

You are given **N** distinct points on a two-dimensional plane (3 ≤ N ≤ 50,000). Your task is to enclose all the points using two non-overlapping rectangles such that the sum of the areas of the two rectangles is minimized. The sides of the rectangles must be parallel to the x and y axes. The rectangles cannot overlap or touch, though it is allowed for points to lie on the boundaries of the rectangles. One of the rectangles can have an area of zero (i.e., have zero width and/or height).

### Input:

* The first line contains an integer **N**, the number of points.
* The next **N** lines contain two integers each: the coordinates of each point. The coordinates are positive integers ranging from 1 to 1,000,000,000.

### Output:

* Output a single integer: the difference between the area required to cover all the points with a single rectangle and the minimum sum of the areas of two rectangles that can enclose all the points.

### Example:

#### Input:

5
3 3
3 5
5 3
5 5
10 11

#### Output:

52

### Explanation:

To enclose all the points in a single rectangle, the lower-left corner of the rectangle would be at (3, 3), and the upper-right corner would be at (10, 11), resulting in an area of (10 - 3) \* (11 - 3) = 56.

If you use two rectangles, you can cover the first four points with a rectangle of area 2 \* 2 = 4, and the last point with a rectangle of zero area. Thus, the total area required for the two rectangles is 4. The difference between the single rectangle's area and the sum of the two rectangles' areas is 56 - 4 = 52.

### Objective:

Implement an algorithm to find the minimum possible sum of the areas of two rectangles that cover all the points and then compute the difference between that and the area of the single rectangle that covers all the points.
