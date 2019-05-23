
#include<bits/stdc++.h>
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
vector<int>G[100001];
int vis[siz];
int ar[siz];
int vis2[siz],vis3[siz];
queue<int>q,q2,q3;
int sum1;
int bfs(int src)
{
    vis[src]=1;
    vis2[src]=0;
    int cnt,cnt2,sum2,ck=1;
    q.push(src);
    cnt2=cnt=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<G[u].size(); i++)
        {
            int v=G[u][i];
            if(vis[v]==0)
            {

                vis[v]=1;
                if(vis2[u]==0)
                {

                    vis2[v]=1;
                    cnt2++;
                }
                else
                {
                    vis2[v]=0;
                    cnt++;

                }
            }
        }
    }
    cnt++;
    sum1+=max(cnt,cnt2);

}
int main()
{
    int i,j,n,k,x,y,r,r2,sum,ck,ans,t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        mem(vis);
        mem(vis2);
        scanf("%d",&n);
        sum1=r=0;
        for(i=0; i<n; i++)
        {
            scanf("%d%d",&x,&y);
            G[x].pb(y);
            G[y].pb(x);
            if(vis[x]==0)
                ar[r++]=x;
            if(vis[y]==0)
                ar[r++]=y;
            vis[x]=vis[y]=1;
        }
        mem(vis);
        for(i=0; i<r; i++)
        {
            x=ar[i];
            if(vis[x]==0)
            {
                bfs(x);
            }
        }
        printf("Case %d: %d\n",cs++,sum1);
        for(i=0; i<r; i++)
        {
            x=ar[i];
            G[x].clear();
        }
    }
}

