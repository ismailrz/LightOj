
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

#define pf printf
#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
#define sc scanf
#define sc1(a) cin>>a
#define sc2(a,b) cin>>a>>b
#define pr1(a) cout<<a<<endl
#define pr2(a,b) cout<<a<<" "<<b<<endl
#define endl '\n'
#define pii pair(ll ,ll )
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180);
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
typedef long long ll;
using namespace std;
#define mx 100002
vector<ll >g[mx];
vector<ll >cost[mx];
ll  ar1[mx];
ll  r1=0;
struct node
{
    ll  u,w;
    node(ll  a,ll  b)
    {
        u=a;
        w=b;
    }
    bool operator < (const node& p) const
    {
        return p.w < w;
    }
};
ll  d[mx],par[mx];
ll  dijkstra(ll  n)
{
    memset(d,63,sizeof(d));
    memset(par,-1,sizeof(par));
    priority_queue<node>q;
    q.push(node(1,0));
    d[1]=0;
    while(!q.empty())
    {
        node top=q.top();
        q.pop();
        ll  u=top.u;
        if(u==n) return d[n];
        for(ll  i=0; i<(ll )g[u].size(); i++)
        {
            ll  v=g[u][i];
            if(d[u]+cost[u][i]<d[v])
            {
                d[v]=d[u]+cost[u][i];
                par[v]=u;
                q.push(node(v,d[v]));
            }
        }
    }
    return -1;
}
int  main()
{
    ll  n,e,i,ret,t,cs=1;
    sc("%lld",&t);
    while(t--)
    {
        sc("%lld%lld",&n,&e);
        for( i=0; i<e; i++)
        {
            ll  u,v,w;
            sc("%lld%lld%lld",&u,&v,&w);
            // cin>>u>>v>>w;
            g[u].push_back(v);
            g[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        ret=dijkstra(n);
        pf("Case %lld: ",cs++);
        if(ret==-1)
            cout<<"Impossible\n";
        else
        {
            ll  u=n;
            printf("%lld\n",d[n]);

        }
        for(i=0; i<=n; i++)
        {
            g[i].clear();
            cost[i].clear();
        }
    }
}

