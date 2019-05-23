#include<stdio.h>
#include<string.h>
#define mx 50
int main()
{
    char str[mx],str2[mx];
    int i,j,n,t,r;
    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
        r=0;
        scanf("%s",str);
        n=strlen(str);
        for(i=n-1;i>=0;i--)
        {
            str2[r++]=str[i];
        }
        str2[r]='\0';
        if(!strcmp(str,str2))
            printf("Case %d: Yes\n",j);
            else
             printf("Case %d: No\n",j);
    }
}
 
