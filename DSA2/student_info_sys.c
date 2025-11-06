// Problem 8: Student Information System
// Concepts: Structs, pointers to structs, dynamic allocation, filtering

#include <stdio.h>       
#include <stdlib.h>    

typedef struct {         
    char name[30];                                    // Student name
    int roll;                                         // Roll number
    float gpa;                                        // GPA of student
} Student;

void inputStudents(Student *s, int n) {                 // Function to input student details
    for (int i = 0; i < n; i++) {                       
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");                               
        scanf("%s", s[i].name);                         // Input name
        printf("Roll: ");                               
        scanf("%d", &s[i].roll);                        // Input roll number
        printf("GPA: ");                                
        scanf("%f", &s[i].gpa);                         // Input GPA
    }
}

void printHighGPA(Student *s, int n) {                  // Function to print students with GPA > 8.0
    printf("\nHigh GPA Students (GPA > 8.0):\n");
    for (int i = 0; i < n; i++) {                       
        if (s[i].gpa > 8.0)                            
            printf("%s (%.2f)\n", s[i].name, s[i].gpa); // Display name & GPA
    }
}

Student getTopper(Student *s, int n) {                  // Function to find topper student
    Student top = s[0];                                 // Assume first as topper
    for (int i = 1; i < n; i++) {                       
        if (s[i].gpa > top.gpa)                        
            top = s[i];                                 // Update topper
    }
    return top;                                         // Return topper
}

int main() {
    int n;                                              // Number of students
    printf("Enter number of students: ");               
    scanf("%d", &n);                                    // Input number of students

    Student *students = (Student*)malloc(n * sizeof(Student));  // Allocate memory
    if (!students) {                                    // Check allocation
        printf("Memory allocation failed!\n");
        return 1;
    }

    inputStudents(students, n);                         // Get student details
    printHighGPA(students, n);                          // Print high GPA students

    Student topper = getTopper(students, n);             // Find topper
    printf("\nTopper: %s with GPA %.2f\n", topper.name, topper.gpa);

    free(students);                                     // Free allocated memory
    return 0;                                           // End of program
}
