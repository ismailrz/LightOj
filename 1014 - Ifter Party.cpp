#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<cmath>
#include<cctype>
#include<stack>
#include<cstdlib>
#include<utility>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>
#define ff first
#define ss second
#define sc scanf
#define pf printf
#define endl '\n'
#define pii pair(int,int)
#define pi acos(-1.0)
#define siz 1000001
#define one(x) __builtin_popcount(x)
typedef long long li;
using namespace std;
vector<li>v;
int ar[siz];
int main()
{
    li i,j,n,k,hi,l,x,t,ck,cs=1;
    sc("%lld",&t);
    while(t--)
    {
        sc("%lld %lld",&k,&l);
        n=k-l;
        ck=0;
        pf("Case %lld: ",cs++);
        x=sqrt(n);
        for(i=1; i<=x; i++)
        {
            if(n%i==0)
            {
                if(i>l)
                    v.push_back(i);
                if(i*i!=n&&(n/i>l))
                    v.push_back(n/i);
            }
        }
        sort(v.begin(),v.end());
        hi=v.size();
        for(i=0; i<hi; i++)
        {
            ck=1;
            pf("%lld",v[i]);
            if(i<hi-1)
                pf(" ");
        }
        if(ck==0)
            pf("impossible");
        pf("\n");
        v.clear();
    }
}
 
 
 
