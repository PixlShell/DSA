#include <stdio.h>
#include <limits.h>

#define MAX 100                                                     // Maximum grid size

int dirX[4] = {-1, 1, 0, 0};                                        // Row movement (up, down)
int dirY[4] = {0, 0, -1, 1};                                        // Column movement (left, right)

int isValid(int x, int y, int rows, int cols, int visited[MAX][MAX]) {
    return (x >= 0 && x < rows && y >= 0 && y < cols && !visited[x][y]);   // Check valid unvisited cell
}

int greedyPath(int grid[MAX][MAX], int rows, int cols, int sx, int sy, int dx, int dy) {
    int visited[MAX][MAX] = {0};                                    // Track visited cells
    int pathX[MAX * MAX], pathY[MAX * MAX];                         // Store path coordinates
    int step = 0;                                                   // Path step counter
    int totalCost = grid[sx][sy];                                   // Initial cell cost

    int x = sx, y = sy;                                             // Current position
    visited[x][y] = 1;                                              // Mark start as visited
    pathX[step] = x; pathY[step] = y; step++;                       // Record start cell

    while (!(x == dx && y == dy)) {                                 // Loop until destination reached
        int minCost = INT_MAX;                                      // Initialize with large value
        int nextX = -1, nextY = -1;                                 // Next move coordinates

        for (int i = 0; i < 4; i++) {                               // Explore four directions
            int nx = x + dirX[i];
            int ny = y + dirY[i];
            if (isValid(nx, ny, rows, cols, visited)) {              // Valid move check
                if (grid[nx][ny] < minCost) {                        // Choose lowest cost neighbor
                    minCost = grid[nx][ny];
                    nextX = nx;
                    nextY = ny;
                }
            }
        }

        if (nextX == -1) {                                          // No valid move (dead end)
            printf("\nNo further moves possible (dead end reached).\n");
            break;
        }

        x = nextX; y = nextY;                                       // Move to chosen cell
        visited[x][y] = 1;                                          // Mark as visited
        totalCost += grid[x][y];                                    // Update total cost
        pathX[step] = x; pathY[step] = y; step++;                   // Record new step
    }

    printf("\nGreedy Path:\n");
    for (int i = 0; i < step; i++) {                                // Print full path
        printf("(%d, %d)", pathX[i], pathY[i]);
        if (i != step - 1) printf(" -> ");
    }
    printf(" -> END\n");

    printf("Total Path Cost: %d\n", totalCost);                     // Print total cost
    return totalCost;
}

int main() {
    int rows, cols;                                                 // Grid dimensions
    int grid[MAX][MAX];                                             // Grid cost matrix
    int sx, sy, dx, dy;                                             // Start and destination coordinates

    printf("Enter grid size (rows cols): ");
    scanf("%d %d", &rows, &cols);                                   // Input grid size

    printf("Enter grid costs:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &grid[i][j]);                               // Input cell costs

    printf("Enter start cell (row col): ");
    scanf("%d %d", &sx, &sy);                                       // Input start cell

    printf("Enter destination cell (row col): ");
    scanf("%d %d", &dx, &dy);                                       // Input destination cell

    greedyPath(grid, rows, cols, sx, sy, dx, dy);                   // Execute greedy algorithm
    return 0;
}
