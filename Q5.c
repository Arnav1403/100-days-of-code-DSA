#include <stdio.h>

int main() {
    int n1, n2;
    
    
    printf("Enter number of entries in Server 1 log: ");
    scanf("%d", &n1);

    printf("Enter number of entries in Server 2 log: ");
    scanf("%d", &n2);

    int log1[n1], log2[n2], merged[n1 + n2];

    
    printf("Enter arrival times for Server 1 (sorted):\n");
    for (int i = 0; i < n1; i++)
        scanf("%d", &log1[i]);

    printf("Enter arrival times for Server 2 (sorted):\n");
    for (int i = 0; i < n2; i++)
        scanf("%d", &log2[i]);

    int i = 0, j = 0, k = 0;

    
    while (i < n1 && j < n2) {
        if (log1[i] <= log2[j])
            merged[k++] = log1[i++];
        else
            merged[k++] = log2[j++];
    }

    
    while (i < n1)
        merged[k++] = log1[i++];

    while (j < n2)
        merged[k++] = log2[j++];

    
    printf("Merged Chronological Log:\n");
    for (int i = 0; i < n1 + n2; i++)
        printf("%d ", merged[i]);

    return 0;
}