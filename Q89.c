#include <stdio.h>

// Check if books can be allocated with maxPages limit
int isPossible(int books[], int n, int m, int maxPages) {
    int students = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {
        // If a single book has more pages than maxPages
        if (books[i] > maxPages)
            return 0;

        // Allocate to next student if limit exceeded
        if (pagesSum + books[i] > maxPages) {
            students++;
            pagesSum = books[i];

            if (students > m)
                return 0;
        } else {
            pagesSum += books[i];
        }
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int books[n];
    int sum = 0, maxBook = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &books[i]);
        sum += books[i];
        if (books[i] > maxBook)
            maxBook = books[i];
    }

    int low = maxBook; // Minimum possible max pages
    int high = sum;    // Maximum possible max pages
    int ans = sum;

    // Binary Search on answer
    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(books, n, m, mid)) {
            ans = mid;
            high = mid - 1; // Try smaller maximum
        } else {
            low = mid + 1;  // Increase limit
        }
    }

    printf("%d\n", ans);

    return 0;
}
