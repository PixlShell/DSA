/*
Recursion: Robotic Arm Trajectory Calculator

Aim: To understand and implement a recursive backtracking algorithm to explore all possible joint configurations for a robotic arm to reach a target position.
Problem Statement:
A 6-Degree-of-Freedom (6-DOF) robotic arm must calculate all possible joint angle combinations to reach a target coordinate (x, y, z). Each joint has a maximum angle limit and moves in fixed angular increments. The program must recursively explore all valid paths (configurations) without exceeding the joint limits.
Input:
•	Target coordinates: (x, y, z)
•	Maximum angle for each of the 6 joints.
•	Angular increment step size.
Output:
•	The total number of valid configurations found.
•	An array (or list) containing each valid set of 6 joint angles.

*/
