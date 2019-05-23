#include<stdio.h>
#include<math.h>
int ar[50];
int main()
{
    int n,i,t,r;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d",&n);
        if(n==0)
            printf("0 0\n");
        else if(n==20)
            printf("10 10\n");
        else if(n<11)
            printf("%d %d\n",abs(ar[n]),abs(n-(ar[n])));
        else
        {
            r=n-10+ar[n];
            printf("%d %d\n",abs(10)-ar[n],abs(r));
        }
        ar[n]++;
    }
    return 0;
}
