#include<bits/stdc++.h>
using namespace std;
int bana[200][101];
int dp[200][101];
int n;
int fun(int line,int pos)
{
    int ret1,ret2,t_line;
    if(line>2*n-1) return 0;
    if(line<n) t_line=line;
    else t_line=2*n-line;
    if(pos<0||pos>t_line) return 0;
    if(dp[line][pos]!=-1) return dp[line][pos];
    if(line<n)
    {
        ret1=bana[line][pos]+fun(line+1,pos);
        ret2=bana[line][pos]+fun(line+1,pos+1);
        dp[line][pos]=max(ret1,ret2);
    }
    else
    {
        ret1=bana[line][pos]+fun(line+1,pos);
        ret2=bana[line][pos]+fun(line+1,pos-1);
        dp[line][pos]=max(ret1,ret2);
    }
    return dp[line][pos];
}
int main()
{
    int t,total,s;
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        int j;
        scanf("%d",&n);
        total=2*n-1;
        for(j=1; j<=n; j++)
        {
            for(int k=1; k<=j; k++) scanf("%d",&bana[j][k]);
        }
        for(s=n-1; j<=total; j++,s--)
        {
            for(int k=1; k<=s; k++) scanf("%d",&bana[j][k]);
        }
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",i,fun(1,1));
    }
    return 0;
}

