#include<stdio.h>
int main()
{
    int a[100], n, i, j, count;

    printf("Enter n: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    for(i=0;i<n;i++)
    {
        count=1;
        if(a[i]!=-1)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[i]==a[j])
                {
                    count++;
                    a[j]=-1;
                }
            }
            printf("%d occurs %d times\n",a[i],count);
        }
    }
}
