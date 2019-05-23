
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<set>
#include<cmath>
#include<cctype>
#include<stack>
#include<cstdlib>
#include<utility>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>

#define sc scanf
#define si(t) scanf("%d",&t)
#define sl(t) scanf("%I64d",&t)
#define sii(a,b) scanf("%d%d",&a,&b)

#define P(a) printf("%d\n",a)
#define PLN(a) printf("%I64d ",a)
#define pf printf

#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
#define pr1(a) cout<<a<<endl
#define pr2(a,b) cout<<a<<" "<<b<<endl
#define pb push_back
#define pii pair<int,int>
#define mk make_pair
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
typedef long long ll;
using namespace std;


map<ll,bool>visi;
int ar[siz];
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
#define mx 100002
int L[mx];
int sparse_t[mx][22],edge_t[mx][22];
int T[mx],pr[mx],edge[mx];
vector<int>g[mx],cost[mx];

int n,m;
struct node
{
    int u,v,cst;
} graph[100001];
bool cmp(node x,node y)
{
    return x.cst<y.cst;
}
int find(int x )
{
    if ( pr[x] == x ) return x ;
    else return pr[x] = find(pr[x]);
}
void dfs(int from,int u,int dep,int cst)
{
    T[u]=from;
    L[u]=dep;
    edge[u]=cst;
    for(int i=0; i<(int)g[u].size(); i++)
    {
        int v=g[u][i];
        int w=cost[u][i];
        if(v==from) continue;
        dfs(u,v,dep+1,w);
    }
}

int lca_query(int N, int p, int q)
{
    int tmp, log, i,ans;

    if (L[p] < L[q])
        tmp = p, p = q, q = tmp;
    log=1;

    while(1)
    {
        int next=log+1;
        if((1<<next)>L[p])break;
        log++;
    }

    ans=-1;
    for (i = log; i >= 0; i--)
    {
        if (L[p] - (1 << i) >= L[q])
        {
            ans=max(ans,edge_t[p][i]);
            p=sparse_t[p][i];
        }

    }

    if (p == q)
        return ans;
    for (i = log; i >= 0; i--)
    {

        if (sparse_t[p][i] != -1 && sparse_t[p][i] != sparse_t[q][i])
        {
            ans=max(ans,edge_t[p][i]);

            ans=max(ans,edge_t[q][i]);


            p = sparse_t[p][i], q = sparse_t[q][i];
        }
    }
    ans=max(ans,max(edge_t[p][0],edge_t[q][0]));
    return ans;
}
void lca_init(int N)
{
    memset (sparse_t,-1,sizeof(sparse_t));
    memset (edge_t,-1,sizeof(edge_t));
    int i, j;
    for (i = 0; i < N; i++)
    {
        sparse_t[i][0] = T[i];
        edge_t[i][0]=edge[i];
    }

    for (j = 1; 1 << j < N; j++)
    {
        for (i = 0; i < N; i++)
        {
            if (sparse_t[i][j - 1] != -1)
            {
                sparse_t[i][j] = sparse_t[sparse_t[i][j - 1]][j - 1];
                edge_t[i][j]=max(edge_t[i][j-1],edge_t[sparse_t[i][j-1]][j-1]);
            }
        }
    }


}
void kruskal()
{
    sort(graph,graph+m,cmp);
    int  i,x,y,u,v;
    for(i=0; i<=n; i++)
        pr[i]=i;
    int  count=0,s=0;
    for(i=0; i<m; i++)
    {
        x=graph[i].u;
        y=graph[i].v;
        u=find(graph[i].u);
        v=find(graph[i].v);
        if(u!=v)
        {
            // cout<<x<<"--"<<y<<endl;
            g[x].pb(y);
            g[y].pb(x);
            pr[u]=v;
            count++;
            s=graph[i].cst;
            cost[x].pb(s);
            cost[y].pb(s);
            if(count==n-1) break;
        }
    }
}

int main()
{

    int i,j,x,y,c,lg,lcaa,ans,p,t,r,cs=1;
    si(t);
    while(t--)
    {
        si(n),si(m);
        for(i=0; i<m; i++)
        {
            si(x),si(y),si(c);
            x--,y--;
            graph[i].u=x,graph[i].v=y,graph[i].cst=c;
        }
        kruskal();
        dfs(0,0 , 0,0);
        lca_init(n);
        si(r);
        printf("Case %d:\n",cs++);
        while(r--)
        {
            si(x),si(y);
            x--,y--;
            printf("%d\n",lca_query(n,x,y));
        }
        for(i=0; i<=n; i++)
        {
            g[i].clear();
            cost[i].clear();
        }

    }
}
