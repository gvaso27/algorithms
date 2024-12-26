# Seeing the Boundary

## Time and Memory Constraints

- Time limit per test: 1 second
- Memory limit per test: 64 megabytes

## Problem Description

Farmer Don has a square field with the following characteristics:

- The field is N × N meters in size, where 2 ≤ N ≤ 500,000
- One fence corner is at the origin (0,0)
- The coordinate system is oriented so the sides of Farmer Don's fence are parallel to the X and Y axes

## Fence Details

- Fence posts appear at all four corners and at every meter along each side of the fence
- Total number of fence posts is 4 × N
- Posts are vertical and have no radius
- Farmer Don wants to determine how many fence posts he can watch when standing at a given location within his fence

## Field Characteristics

- The field contains R rocks (1 ≤ R ≤ 30,000)
- The rocks are large enough to obscure the view of some fence posts
- Each rock is a convex polygon with nonzero area
- Rock vertices are at integer coordinates
- Rocks must stand completely vertical
- Rocks do not overlap, touch other rocks, or touch the fence
- The fence does not stand within a rock or on a rock

## View Mechanics

- If a vertex of a rock lines up perfectly with a fence post from Farmer Don's location, he cannot see that fence post

## Input Format

1. First line: two space-separated integers N and R
2. Second line: two space-separated integers specifying Farmer Don's X and Y coordinates inside the fence
3. Remaining lines describe the R rocks:
   - Each rock's description begins with a line containing a single integer pi (3 ≤ pi ≤ 20), representing the number of vertices in the rock's base
   - Following pi lines contain space-separated pairs of integers representing X and Y coordinates of vertices
   - Vertices of a rock's base are distinct and given in counterclockwise order

## Output Format

- A single line containing one integer: the number of fence posts visible to Farmer Don

## Scoring

- Full points awarded for each test case with correct output file
- No partial credit given for any test case

## Example

### Input

```
100 1
60 50
5
70 40
75 40
80 40
80 50
70 60
```

### Output

```
319
```

### Note

The example shows a case where rock 1 has three collinear vertices: (70,40), (75,40), and (80,40).

The problem includes a diagram that illustrates the field layout with Farmer Don's position and the rock's location in the coordinate system.
