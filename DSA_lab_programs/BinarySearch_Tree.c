#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;                                       // Initialize search bounds
    while (low <= high) {
        int mid = (low + high) / 2;                                  // Compute mid index
        if (arr[mid] == key) return mid;                             // Exact match found
        else if (arr[mid] < key) low = mid + 1;                      // Search right half
        else high = mid - 1;                                         // Search left half
    }
    return -1;                                                       // No exact match
}

int findNearest(int arr[], int n, int key) {
    int low = 0, high = n - 1;                                       // Initialize bounds
    while (low <= high) {
        int mid = (low + high) / 2;                                  // Compute mid
        if (arr[mid] == key) return arr[mid];                        // Exact match
        else if (arr[mid] < key) low = mid + 1;                      // Move right
        else high = mid - 1;                                         // Move left
    }
    if (low >= n) return arr[n - 1];                                 // Key beyond max
    if (high < 0) return arr[0];                                     // Key below min
    int diffLow = abs(arr[low] - key);                               // Compare proximity
    int diffHigh = abs(arr[high] - key);
    return (diffLow < diffHigh) ? arr[low] : arr[high];              // Return nearest
}

int main() {
    int n, key;                                                      // Variables for size & key
    printf("Enter number of transactions: ");
    scanf("%d", &n);                                                 // Input size

    int arr[n];                                                      // Array of transactions
    printf("Enter transaction times (sorted): ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);                // Input sorted list

    printf("Enter transaction time to search: ");
    scanf("%d", &key);                                               // Input key

    int index = binarySearch(arr, n, key);                           // Perform binary search
    if (index != -1)
        printf("Transaction found at index %d\n", index);            // Exact match
    else {
        int nearest = findNearest(arr, n, key);                      // Find nearest match
        printf("No exact match found. Nearest transaction is at %d\n", nearest);
    }
    return 0;
}
