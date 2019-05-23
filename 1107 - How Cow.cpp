#include<stdio.h>
int main()
{
    int x,y,x1,y1,x2,y2,n,t,i,k;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        k=0;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        scanf("%d",&n);
        while(n--)
        {
            if(k==0)
            {
                printf("Case %d:\n",i);
                k=1;
            }
            scanf("%d%d",&x,&y);
            if((x>x1&&x<x2)&&(y>y1&&y<y2))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
 
