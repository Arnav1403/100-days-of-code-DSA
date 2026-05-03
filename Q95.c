#include <stdio.h>

// Insertion sort for each bucket
void insertionSort(float bucket[], int n) {
    for (int i = 1; i < n; i++) {
        float key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }

        bucket[j + 1] = key;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];

    // Input array
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    // Create n buckets
    float buckets[n][n];
    int bucketCount[n];

    // Initialize bucket counts
    for (int i = 0; i < n; i++) {
        bucketCount[i] = 0;
    }

    // Put elements into buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] * n;   // Bucket index
        buckets[index][bucketCount[index]++] = arr[i];
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i], bucketCount[i]);
    }

    // Concatenate all buckets into original array
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}
