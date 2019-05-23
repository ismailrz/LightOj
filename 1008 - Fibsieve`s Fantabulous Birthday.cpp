#include<iostream>
#include<cmath>
#include<cstdio>
typedef long long li;
using namespace std;
int main()
{
    li x,y,row,col,i,j,t,cs=1;
    double n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        x=ceil(sqrt(n));
        if(x%2==1)
        {
            y=n-(x-1)*(x-1);
            if(x>=y)
            {
                row=y;
                col=x;
            }
            else
            {
                row=x;
                col=1+x*x-n;
            }
        }
        else
        {
            y=n-(x-1)*(x-1);
            if(x>=y)
            {
                row=x;
                col=y;
            }
            else
            {
                row=1+x*x-n;
                col=x;
            }
        }
        printf("Case %lld: ",cs++);
        cout<<col<<' '<<row<<endl;
    }
}
