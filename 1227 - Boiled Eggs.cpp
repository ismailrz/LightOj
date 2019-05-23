#include<iostream>
#include<cstdio>
#include<cstring>
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
using namespace std;
vector<int>v;
int ar[35];
int main()
{
    int n,p,q,sum,cnt,i,t,cs=1;
    sc("%d",&t);
    while(t--)
    {
        sc("%d%d%d",&n,&p,&q);
        for(i=0; i<n; i++)
            sc("%d",&ar[i]);
        sum=cnt=0;
        for(i=0; i<n; i++)
        {
            sum+=ar[i];
            if(sum<=q&&cnt<p)
                cnt++;
        }
        pf("Case %d: %d\n",cs++,cnt);
    }
}
 
 
 
