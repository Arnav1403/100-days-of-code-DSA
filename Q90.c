#include <stdio.h>

// Check if boards can be painted within maxTime
int isPossible(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int total = 0;

    for (int i = 0; i < n; i++) {
        // If one board itself is larger than maxTime
        if (boards[i] > maxTime)
            return 0;

        // Assign to next painter if limit exceeded
        if (total + boards[i] > maxTime) {
            painters++;
            total = boards[i];

            if (painters > k)
                return 0;
        } else {
            total += boards[i];
        }
    }
    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    int sum = 0, maxBoard = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        sum += boards[i];

        if (boards[i] > maxBoard)
            maxBoard = boards[i];
    }

    int low = maxBoard; // Minimum possible time
    int high = sum;     // Maximum possible time
    int ans = sum;

    // Binary Search on answer
    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1; // Try smaller time
        } else {
            low = mid + 1;  // Increase time
        }
    }

    printf("%d\n", ans);

    return 0;
}
