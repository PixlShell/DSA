/*
Bellman-Ford Algorithm: AI Path Planning with Obstacles

Aim: To implement the Bellman-Ford algorithm for finding the shortest path from a single source to a destination on a graph representing a grid with obstacles and varying costs.
Problem Statement:
A robot must navigate from a start point to an endpoint on a graph where nodes represent cells and edges represent possible moves. Some cells are obstacles (infinite cost). The graph may have negative cost edges (e.g., "boost" pads that reduce total time). Use the Bellman-Ford algorithm to find the shortest path, detecting if any negative cycles exist that would make the path undefined.
Input:
•	A graph representation (adjacency list or matrix) of the grid, including edge weights (costs). Obstacles are represented as nodes with no outgoing edges or edges with infinite cost.
•	Source node and destination node.
Output:
•	The shortest path from the source to the destination as a sequence of nodes.
•	The total cost of the shortest path.
•	If a negative cycle is detected: "Negative cycle detected. No shortest path exists."

*/
