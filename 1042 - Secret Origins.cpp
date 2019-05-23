
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
int ar[1001];
ll power(int num,int p)
{
    int i;
    ll sum=1;
    for(i=1; i<=p; i++)
        sum*=num;
    return sum;
}
ll  bi(ll num)
{
    int r=0;
    while(num>0)
    {
        ar[r++]=num%2;
        num/=2;
    }
    ar[r++]=0;
    reverse(ar,ar+r);
    // for(int i=0; i<r; i++) cout<<ar[i];
    next_permutation(ar,ar+r);
    // for(int i=0; i<r; i++) cout<<ar[i];
    //cout<<endl<<endl;
    int dig=r-1;
    ll sum=0;
    for(int i=0; i<r; i++)
    {
        if(ar[i]==1)
        {
            // power(2,dig)<<endl;
            sum+=power(2,dig);
        }
        dig--;
    }
    printf("%lld\n",sum);

}
int main()
{
    //freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
    ll i,j,n,m,a,c,b,ck,t,r,x,y,ans,rem,cnt,lo,hi,sum,cs=1;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        printf("Case %lld: ",cs++);
        bi(n);
    }

}
