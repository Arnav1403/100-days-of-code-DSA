#include <stdio.h>

int main() {
    int n, k, i;
    int comparisons = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter key to search: ");
    scanf("%d", &k);

    for (i = 0; i < n; i++) {
        comparisons++;             
        if (arr[i] == k) {
            printf("Key found at position %d\n", i + 1);
            printf("Number of comparisons: %d\n", comparisons);
            return 0;
        }
    }

    printf("Key not found\n");
    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}