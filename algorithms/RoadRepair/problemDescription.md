### Problem Description: Road Repair

Johnny travels daily from Pasture 1 to Pasture **N** using the farm's bidirectional roads. The farm has **M** roads, and each road connects two pastures and requires a certain amount of time to traverse. Due to the state of the roads, Johnny wants to modernize up to **K** roads, reducing the travel time of those roads to zero. Your task is to help Johnny find the shortest possible travel time from Pasture 1 to Pasture **N**, after modernizing at most **K** roads.

### Input:

* The first line contains three integers: **N**, the number of pastures (1 ≤ N ≤ 10,000), **M**, the number of bidirectional roads (1 ≤ M ≤ 50,000), and **K**, the number of roads that can be modernized (1 ≤ K ≤ 20).
* The next **M** lines describe the roads. Each line contains three integers: **P1**, **P2** (1 ≤ P1, P2 ≤ N), the two pastures connected by this road, and **T**, the travel time for this road (1 ≤ T ≤ 1,000,000).

### Output:

* Output the minimum possible travel time from Pasture 1 to Pasture **N**, after modernizing at most **K** roads.

### Example:

#### Input:

4 4 1
1 2 10
2 4 10
1 3 1
3 4 100

#### Output:

1

### Explanation:

Johnny can modernize the road from Pasture 3 to Pasture 4, reducing its travel time from 100 to 0. This results in the shortest path: 1 → 3 → 4, with a total travel time of 1.

### Objective:

Your goal is to implement an algorithm that finds the minimum travel time from Pasture 1 to Pasture **N**, considering the option to modernize up to **K** roads.
