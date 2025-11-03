#include <stdio.h>

long long factorial(int n) {
    long long fact = 1;                                            // Initialize factorial
    for (int i = 1; i <= n; i++) fact *= i;                        // Compute n!
    return fact;
}

long long binomialCoeff(int n, int r) {
    if (r > n) return 0;                                           // Invalid case
    return factorial(n) / (factorial(r) * factorial(n - r));       // nCr formula
}

int main() {
    int n, r;                                                      // Total & chosen attributes
    printf("Enter total number of attributes (n): ");
    scanf("%d", &n);
    printf("Enter number of attributes to choose (r): ");
    scanf("%d", &r);

    long long result = binomialCoeff(n, r);                        // Compute binomial coefficient
    printf("Possible split combinations = %lld\n", result);         // Display result

    return 0;
}

