/*
. Backtracking Techniques: AI Task Planning for Robots

Aim: To design and implement a backtracking algorithm for AI planning, enabling robots to find a conflict-free assignment of tasks.
Problem Statement:
Multiple robots need to be assigned to tasks without conflicts (e.g., two robots cannot be in the same place at the same time). Using backtracking, explore all possible valid assignments of tasks to robots. A solution is valid only if no conflicts exist for any robot during its task execution.
Input:
•	A list of tasks, each with a required location, time, and duration.
•	A list of robots, each with a start location and availability.
Output:
•	The number of valid, conflict-free assignments.
•	A list of all valid assignments, where each assignment shows which robot performs which task and in what order.

*/
