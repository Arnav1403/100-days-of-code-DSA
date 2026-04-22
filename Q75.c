#include <stdio.h>

int maxLen(int arr[], int n) {
    int sum = 0, maxLength = 0;


    int prefixSum[1000];
    int index[1000];
    int size = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

       
        if (sum == 0) {
            maxLength = i + 1;
        }

       
        int found = 0;
        for (int j = 0; j < size; j++) {
            if (prefixSum[j] == sum) {
                int length = i - index[j];
                if (length > maxLength)
                    maxLength = length;
                found = 1;
                break;
            }
        }

       
        if (!found) {
            prefixSum[size] = sum;
            index[size] = i;
            size++;
        }
    }

    return maxLength;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLen(arr, n));

    return 0;
}
