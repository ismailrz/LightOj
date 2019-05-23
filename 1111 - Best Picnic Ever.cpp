
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
vector<int>vec[10001];
vector<int>vec2[10001];
int vis[siz],b,id;
int dis[siz];
int bfs(int src)
{
    queue<int>qe;
    int v;
    vis[src]=1;
    qe.push(src);
    dis[src]=0;
    while(!qe.empty())
    {
        int u=qe.front();
        qe.pop();
        for(int i=0; i<vec[u].size(); i++)
        {
            v=vec[u][i];
            if(vis[v]==0)
            {
                vis[v]=1;
                qe.push(v);
            }
        }
    }
    int sum=0;
    for(int i=1; i<=b; i++)
    {
        if(vis[i]==1)
            sum++;
    }
    return sum;

}
int main()
{

    int   i,j,n,m,a,c,ck,t,r,x,y,ans,rem,r1,lo,hi,sum,cs=1;
    si(t);
    while(t--)
    {
        id=0;
        mem(vis);
        si(a),si(b),si(c);
        for(i=0; i<a; i++) si(ar[i]);
        for(i=0; i<c; i++)
        {
            si(x),si(y);
            vec[x].pb(y);
        }
        mem(vis);
        sum=9999999;
        for(i=0; i<a; i++)
        {
            x=ar[i];
            ans=bfs(x);
            sum=min(sum,ans);
            mem(vis);
        }
        printf("Case %d: %d\n",cs++,sum);
        for(i=0; i<=b; i++) vec[i].clear();
    }
}

