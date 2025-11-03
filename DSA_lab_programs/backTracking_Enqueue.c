#include <stdio.h>
#include <string.h>

#define MAX_TASKS 10                                            // Maximum number of tasks
#define MAX_ROBOTS 5                                            // Maximum number of robots
#define MAX_SOLUTIONS 5                                        // Maximum solutions to find

typedef struct {
    int location;                                              // Task location
    int startTime;                                             // Task start time
    int duration;                                              // Task duration
} Task;

typedef struct {
    int location;                                              // Robot current location
    int availableTime;                                         // Robot available time
} Robot;

int N, R;                                                     // Number of tasks and robots
Task tasks[MAX_TASKS];                                        // Array of tasks
Robot robots[MAX_ROBOTS];                                     // Array of robots
int assignment[MAX_TASKS];                                     // Current assignment of tasks to robots
int totalSolutions = 0;                                       // Count of valid assignments

int isValid(int t, int r) {                                   // Check if task t can be assigned to robot r
    if (robots[r].availableTime > tasks[t].startTime) return 0; // Robot busy at task start
    return 1;
}

void assignTasks(int t) {
    if (totalSolutions >= MAX_SOLUTIONS) return;              // Stop if max solutions reached
    if (t == N) {                                             // All tasks assigned
        totalSolutions++;                                      // Count solution
        printf("Assignment %d:\n", totalSolutions);            // Print solution
        for (int i = 0; i < N; i++)
            printf("Task %d -> Robot %d\n", i, assignment[i]); // Show task->robot mapping
        printf("\n");
        return;
    }

    for (int r = 0; r < R; r++) {
        if (isValid(t, r)) {                                   // Check if robot can take task
            assignment[t] = r;                                  // Assign task
            int prevTime = robots[r].availableTime;             // Save previous available time
            int prevLoc = robots[r].location;                   // Save previous location
            robots[r].availableTime = tasks[t].startTime + tasks[t].duration; // Update available time
            robots[r].location = tasks[t].location;             // Update location

            assignTasks(t + 1);                                 // Recurse for next task

            robots[r].availableTime = prevTime;                 // Backtrack time
            robots[r].location = prevLoc;                       // Backtrack location
        }
    }
}

int main() {
    printf("Enter number of tasks and robots: ");
    scanf("%d %d", &N, &R);                                   // Input counts

    printf("Enter tasks (location startTime duration):\n");
    for (int i = 0; i < N; i++)
        scanf("%d %d %d", &tasks[i].location, &tasks[i].startTime, &tasks[i].duration); // Input tasks

    printf("Enter robots (location availableTime):\n");
    for (int i = 0; i < R; i++)
        scanf("%d %d", &robots[i].location, &robots[i].availableTime); // Input robots

    assignTasks(0);                                            // Start backtracking

    printf("Total valid assignments found: %d\n", totalSolutions); // Print total solutions

    return 0;
}
