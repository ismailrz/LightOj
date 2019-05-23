
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
int ar[20][20];
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
int dp[(1<<16)+2],n;
int cal(int mask,int column)
{
    if(mask==(1<<n)-1) return 0;
    if(dp[mask]!=0) return dp[mask];
    int ret,ck, mn=-1;
    for(int i=0; i<n; i++)
    {
        if(check(mask,i)==0)
        {
            ck=-1;
            for(int j=0; j<n; j++)
            {
                if(check(column,j)==0)
                {
                    ck=j;
                    break;
                }
            }
            if(ck!=-1)
            {
                ret=ar[i][ck]+cal(Set(mask,i),Set(column,ck));
                mn=max(mn,ret);
            }
        }
    }
    return dp[mask]=mn;

}
int main()
{
    int  i,j,m,a,c,b,d,ck,t,r,x,y,ans,rem,cnt,lo,hi,sum,cs=1;
    si(t);
    while(t--)
    {
        mem(dp);
        si(n);
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                si(ar[i][j]);
        printf("Case %d: %d\n",cs++,cal(0,0));
    }


}
