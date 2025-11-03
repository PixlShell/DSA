#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846                               // Mathematical constant
#define TOLERANCE 0.1                                            // Position matching tolerance

typedef struct { double t1, t2, t3; } Config;                    // Joint angle configuration (θ1, θ2, θ3)

Config *configs;                                                 // Dynamic array to store valid configurations
int count = 0;                                                   // Count of valid configurations
int max_count = 1000;                                            // Maximum configurations allowed

void fk(double t1, double t2, double t3, double L1, double L2, double *x, double *y, double *z) {
    double r1 = t1 * PI / 180.0;                                 // Convert θ1 to radians
    double r2 = t2 * PI / 180.0;                                 // Convert θ2 to radians
    double r3 = t3 * PI / 180.0;                                 // Convert θ3 to radians

    double x2 = L1 * cos(r2) * cos(r1);                          // Position after first link
    double y2 = L1 * cos(r2) * sin(r1);
    double z2 = L1 * sin(r2);

    *x = x2 + L2 * cos(r2 + r3) * cos(r1);                       // Final end-effector X
    *y = y2 + L2 * cos(r2 + r3) * sin(r1);                       // Final end-effector Y
    *z = z2 + L2 * sin(r2 + r3);                                 // Final end-effector Z
}

int check_target(double x, double y, double z, double tx, double ty, double tz) {
    double dx = x - tx, dy = y - ty, dz = z - tz;                // Difference from target
    return sqrt(dx * dx + dy * dy + dz * dz) <= TOLERANCE;       // Within tolerance or not
}

void find_configs(int joint, double *angles, double tx, double ty, double tz,
                  double *max_angles, double L1, double L2) {
    if (joint == 3) {                                            // Base case: all joints set
        double x, y, z;
        fk(angles[0], angles[1], angles[2], L1, L2, &x, &y, &z); // Compute forward kinematics
        if (check_target(x, y, z, tx, ty, tz) && count < max_count) {
            configs[count].t1 = angles[0];                       // Store valid configuration
            configs[count].t2 = angles[1];
            configs[count].t3 = angles[2];
            count++;
        }
        return;
    }

    for (double angle = -max_angles[joint]; angle <= max_angles[joint]; angle += 1.0) {
        angles[joint] = angle;                                   // Set current joint angle
        find_configs(joint + 1, angles, tx, ty, tz, max_angles, L1, L2); // Recurse for next joint
    }
}

int main() {
    double tx, ty, tz;                                           // Target position
    double max_angles[3];                                        // Max joint angles
    double L1, L2;                                               // Link lengths

    printf("=== 3-DOF Robotic Arm ===\n");
    printf("Enter target (x y z): ");
    scanf("%lf %lf %lf", &tx, &ty, &tz);
    printf("Enter max angles (θ1 θ2 θ3): ");
    scanf("%lf %lf %lf", &max_angles[0], &max_angles[1], &max_angles[2]);
    printf("Enter link lengths (L1 L2): ");
    scanf("%lf %lf", &L1, &L2);

    configs = (Config *)malloc(max_count * sizeof(Config));       // Allocate memory
    double angles[3] = {0};                                      // Current joint angles

    printf("\nCalculating...\n");
    find_configs(0, angles, tx, ty, tz, max_angles, L1, L2);     // Start recursive search

    printf("\nTotal valid configurations: %d\n", count);
    if (count > 0) {
        printf("Valid configurations [θ1, θ2, θ3]:\n");
        for (int i = 0; i < count; i++)                          // Display all valid results
            printf("Config %d: [%.1f°, %.1f°, %.1f°]\n", i + 1,
                   configs[i].t1, configs[i].t2, configs[i].t3);
    } else printf("No valid configurations found.\n");

    free(configs);                                               // Free allocated memory
    return 0;
}
