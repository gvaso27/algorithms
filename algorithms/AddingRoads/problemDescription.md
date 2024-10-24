### Problem Description: Adding Roads

Farmer John has purchased new farms and wants to connect them with roads in such a way that it is possible to travel from any farm to any other farm using some sequence of roads. Currently, some farms are already connected by existing roads. Each of the **N** farms (1 ≤ N ≤ 1,000) is represented on a plan with coordinates (**X\_i**, **Y\_i**) (0 ≤ X\_i ≤ 1,000,000; 0 ≤ Y\_i ≤ 1,000,000). The task is to determine the minimum total length of new roads that must be built so that all farms are connected.

### Input:

* The first line contains two integers: **N**, the number of farms, and **M**, the number of existing roads.
* The next **N** lines contain the coordinates of the farms. Each line contains two integers **X\_i** and **Y\_i** representing the coordinates of the i-th farm.
* The next **M** lines describe the existing roads, where each line contains two integers **i** and **j**, indicating that there is already a road connecting farm **i** and farm **j**.

### Output:

* Output a single number: the minimum total length of the roads that need to be built so that all farms are connected. The result should be printed without rounding, with two decimal places.

### Example:

#### Input:

4 1
1 1
3 1
2 3
4 3
1 4

#### Output:

4.00

### Explanation:

There are four farms at coordinates (1, 1), (3, 1), (2, 3), and (4, 3). A road already exists between farm 1 and farm 4. The best way to connect all the farms is to build roads between farm 1 and farm 2 (distance 2.00) and between farm 3 and farm 4 (distance 2.00). The total length of the new roads is 4.00 units.

### Objective:

Implement an algorithm to find the minimum total length of new roads required to connect all the farms.
