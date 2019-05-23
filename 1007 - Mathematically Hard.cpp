#include<cstdio>
#include<iostream>
#define sc scanf
#define pf printf
typedef unsigned long long li;
using namespace std;
#define M 5000005
li ar[M];
int phi[M];
void calculatePhi()
{
    li i,j,p,k,sum,x;
    for(i=2; i<M; i++)
    {
        if(!phi[i]==1)
        {
            phi[i]=i-1;
            for(j=i*2; j<M; j+=i)
            {
                if(!phi[j]==1)
                {
                    phi[j]=j;
                }
                phi[j] -= (phi[j]/i);
            }
        }
    }
    sum=0;
    for(i=1; i<M; i++)
    {
        x=phi[i];
        sum+=x*x;
        ar[i]=sum;
    }
}
int main()
{
    calculatePhi();
    li a,b,c,cs=1;
    sc("%llu",&c);
    while(c--)
    {
        sc("%llu%llu",&a,&b);
        pf("Case %llu: ",cs++);
        pf("%llu\n",ar[b]-ar[a-1]);

    }
}

