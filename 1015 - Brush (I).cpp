#include<stdio.h>
int main()
{
    long int n,i,j,sum,d,t;
    scanf("%ld",&t);
    for(j=1; j<=t; j++)
    {
        scanf("%ld",&n);
        sum=0;
        for(i=1; i<=n; i++)
        {
            scanf("%ld",&d);
            if(d>0)
            {
                sum+=d;
            }
        }
        printf("Case %ld: %ld\n",j,sum);
    }
    return 0;
}
