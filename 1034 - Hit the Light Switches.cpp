
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
#define sf(t) scanf("%f",&t)
#define sd(t) scanf("%lf",&t)
#define sii(a,b) scanf("%d%d",&a,&b)
#define sll(a,b) scanf("%I64d%I64d",&a,&b)
#define P(a) printf("%dn",a)
#define PL(a) printf("%lldn",a)
#define PF(a) printf("%fn",a)
#define PDB(a) printf("%lfn",a)
#define PN(a) printf("%d ",a)
#define PLN(a) printf("%I64d ",a)
#define PDBN(a) printf("%lf ",a)
#define pf printf

#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second

#define pr1(a) cout<<a<<endl
#define pr2(a,b) cout<<a<<" "<<b<<endl

#define pii pair<int,int>
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
typedef long long ll;
using namespace std;
int indegree[siz];
queue<int>qe;
vector<int>vec[10001];
vector<int>v2;
int ar1[siz];
int visi[siz];
int main()
{
    int node,edge,i,j,k,x,y,u,v,n,t,cnt,cs=1;
    sc("%d",&t);
    while(t--)
    {
        sc("%d%d",&node,&edge);
        cnt=0;
        for(i=0; i<edge; i++)
        {
            sc("%d%d",&x,&y);
            vec[x].push_back(y);
            indegree[y]++;
        }
        for(i=1; i<=node; i++)
        {
            if(indegree[i]==0)
            {
                qe.push(i);
                cnt++;
                ar1[i]=1;
            }
        }
        while(!qe.empty())
        {
            u=qe.front();
            qe.pop();
            for(i=0; i<vec[u].size(); i++)
            {
                v=vec[u][i];
                if(visi[v]==0)
                {
                    ar1[v]=1;
                    visi[v]=1;
                    qe.push(v);
                }
            }
        }
        int ck=0;
        for(i=1; i<=node; i++)
        {
            if(ar1[i]==0)
            {
                ck=1;
                break;
            }
        }
        if(ck==1)
            cnt+=1;
        if(cnt==0)
            cnt+=1;
        pf("Case %d: %d\n",cs++,cnt);
        cnt=0;
        for(i=1; i<=node; i++)
            vec[i].clear();
        mem(indegree);
        mem(ar1);
        mem(visi);
        v2.clear();
    }

}


