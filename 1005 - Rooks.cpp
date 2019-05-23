
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
typedef unsigned long long ull;
using namespace std;
map<ll,bool>visi;
ll dp[35][35];
ll ret;
ll cal(ll n,ll m)
{
    if(dp[n][m]!=-1) return dp[n][m];
    if(m==1) return n;
    if(n==m) return 1;
    ret =cal(n-1,m)+cal(n-1,m-1);
    dp[n][m]=ret;
    return dp[n][m];
}
int main()
{
    int  i,j,n,m,a,c,b,d,ck,t,r,x,y,rem,cnt,lo,hi,cs=1;
    ull ans,sum;
    si(t);
    while(t--)
    {
        si(n),si(m);
        memset(dp,-1,sizeof dp);
        printf("Case %d: ",cs++);
        if(n<m) printf("0\n");
        else if(m==0) printf("1\n");
        else
        {
            ans=1;
            for(i=n-m+1; i<=n; i++)
                ans*=i;
            printf("%llu\n",ans*cal(n,m));
        }
    }

}

