#include <stdio.h>
#include <stdlib.h>

// Structure to store value and original index
typedef struct {
    int value;
    int index;
} Pair;

// Merge function
void merge(Pair arr[], Pair temp[], int left, int mid, int right, int count[]) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[j].value < arr[i].value) {
            temp[k++] = arr[j++];
            rightCount++; // one smaller element found on right
        } else {
            count[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    // Remaining left elements
    while (i <= mid) {
        count[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    // Remaining right elements
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy back
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

// Merge sort
void mergeSort(Pair arr[], Pair temp[], int left, int right, int count[]) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, temp, left, mid, count);
        mergeSort(arr, temp, mid + 1, right, count);
        merge(arr, temp, left, mid, right, count);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Pair arr[n], temp[n];
    int count[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
        arr[i].index = i;
        count[i] = 0;
    }

    mergeSort(arr, temp, 0, n - 1, count);

    // Print counts
    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}
