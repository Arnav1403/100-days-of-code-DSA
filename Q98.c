#include <stdio.h>
#include <stdlib.h>

// Structure for interval
typedef struct {
    int start, end;
} Interval;

// Compare function for sorting by start time
int compare(const void *a, const void *b) {
    Interval *i1 = (Interval *)a;
    Interval *i2 = (Interval *)b;
    return i1->start - i2->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];

    // Input intervals
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // Sort intervals by start time
    qsort(arr, n, sizeof(Interval), compare);

    Interval result[n];
    int index = 0;

    // First interval goes into result
    result[index] = arr[0];

    for (int i = 1; i < n; i++) {
        // If overlapping, merge
        if (arr[i].start <= result[index].end) {
            if (arr[i].end > result[index].end)
                result[index].end = arr[i].end;
        } else {
            // No overlap, move to next interval
            index++;
            result[index] = arr[i];
        }
    }

    // Print merged intervals
    for (int i = 0; i <= index; i++) {
        printf("%d %d\n", result[i].start, result[i].end);
    }

    return 0;
}
