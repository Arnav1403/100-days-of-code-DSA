#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    // Input array
    int max = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        // Find maximum element
        if (arr[i] > max)
            max = arr[i];
    }

    // Frequency array
    int count[max + 1];

    // Initialize frequency array with 0
    for (int i = 0; i <= max; i++)
        count[i] = 0;

    // Count frequency of each element
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Compute prefix sums
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Build output array (stable)
    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", output[i]);
    }

    return 0;
}
