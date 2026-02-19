#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    
    scanf("%d", &n);

    int arr[n];

    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int minSum = arr[0] + arr[1];
    int num1 = arr[0], num2 = arr[1];

    
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];

            if(abs(sum) < abs(minSum))
            {
                minSum = sum;
                num1 = arr[i];
                num2 = arr[j];
            }
        }
    }

    
    if(num1 < num2)
        printf("%d %d", num1, num2);
    else
        printf("%d %d", num2, num1);

    return 0;
}
