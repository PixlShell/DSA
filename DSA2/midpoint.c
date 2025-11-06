// Problem 9: Structure Return Function
// Concepts: Returning struct from a function

#include <stdio.h>                                           // For input/output functions

struct Point {           
    float x, y;                                              // Coordinates of a point
};

struct Point getMidPoint(struct Point a, struct Point b) {   // Function to calculate midpoint
    struct Point mid;                                        // Temporary structure variable
    mid.x = (a.x + b.x) / 2;                                 // Midpoint X-coordinate
    mid.y = (a.y + b.y) / 2;                                 // Midpoint Y-coordinate
    return mid;                                               // Return midpoint structure
}

int main() {
    struct Point p1, p2, mid;                                // Declare structure variables
    printf("Enter coordinates of first point (x1 y1): ");    
    scanf("%f %f", &p1.x, &p1.y);                            // Input first point
    printf("Enter coordinates of second point (x2 y2): ");   
    scanf("%f %f", &p2.x, &p2.y);                            // Input second point

    mid = getMidPoint(p1, p2);                               // Call function to find midpoint

    printf("Midpoint: (%.2f, %.2f)\n", mid.x, mid.y);        // Display midpoint
    return 0;                                                 // End of program
}
