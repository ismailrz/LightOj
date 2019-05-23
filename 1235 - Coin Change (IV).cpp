#include<bits/stdc++.h>

using namespace std;
typedef long long i64;
vector< i64 > Lt, Rt;
i64 a[20];
void generate(i64 sum, int st, int en, vector< i64 > &v)
{
    int i;
    if(st == en)
    {
        v.push_back(sum);
        return;
    }
    for(i = 0; i < 3; i++) generate(sum + a[st] * i, st + 1, en, v);
}

int main()
{
    int test,m, n, i, mid, sz,sz2,lo,hi,ck,t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; i++) scanf("%lld", &a[i]);
        Lt.clear();
        Rt.clear();
        mid = n >> 1;
        generate(0, 0, mid, Lt);
        generate(0, mid, n, Rt);
        sz=Lt.size();
        sz2=Rt.size();
        sort(Lt.begin(),Lt.end());

        for(i = 0; i < sz2; i++)
        {

            if(m >= Rt[i])
            {

                if(*lower_bound(Lt.begin(), Lt.end(), m- Rt[i]) == m - Rt[i]) break;
            }
        }
        if(i == sz2) printf("Case %d: No\n", cs++);
        else printf("Case %d: Yes\n", cs++);

    }
    return 0;
}

