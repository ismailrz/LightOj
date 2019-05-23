#include<bits/stdc++.h>
using namespace std;
vector<int>G[100001];
vector<int>cost[100001];
int d[100001];
int bfs(int src)
{
    queue<int>q;
    memset(d,63,sizeof d);
    q.push(src);
    d[src]=0;
    int i,j,u,v;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=0; i<G[u].size(); i++)
        {
            v=G[u][i];
            if(max(d[u],cost[u][i])<d[v])
            {
                d[v]=max(d[u],cost[u][i]);
                q.push(v);
            }
        }
    }
}
int main()
{
    int i,j,n,m,k,x,y,cst,t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&x,&y,&cst);
            G[x].push_back(y);
            G[y].push_back(x);
            cost[x].push_back(cst);
            cost[y].push_back(cst);
        }
        //cin>>x;
        scanf("%d",&x);
        bfs(x);
        printf("Case %d:\n",cs++);
        for(i=0; i<n; i++)
        {
            if(d[i]>20000)
                printf("Impossible\n");
            else
                printf("%d\n",d[i]);
        }
        for(i=0; i<n; i++)
            G[i].clear();
        for(i=0; i<=20000; i++)
            cost[i].clear();
    }
 
}
 
