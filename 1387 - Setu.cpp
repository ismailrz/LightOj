#include<iostream>
#include<cstdio>
#include<cstring>
typedef long long int ll;
using namespace std;
int main()
{
    char str[100];
    ll k,i,n,sum,t,h=1;
    cin>>t;
    while(t--)
    {
        cout<<"Case "<<h++<<":\n";
        cin>>n;
        sum=0;
        for(i=1; i<=n; i++)
        {
            scanf("%s",str);
            if(!strcmp(str,"report"))
            {
                cout<<sum<<endl;
            }
            else
            {
                cin>>k;
                sum+=k;
            }
        }
    }
}
 
