#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    long long low = 0, high = n, mid;
    long long ans = 0;

    // Binary Search
    while (low <= high) {
        mid = (low + high) / 2;

        if (mid * mid == n) {
            ans = mid;
            break;
        }
        else if (mid * mid < n) {
            ans = mid;   // store possible answer
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    // Print integer square root
    printf("%lld\n", ans);

    return 0;
}
