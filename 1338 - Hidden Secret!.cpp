#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define mx 104
char str2[mx],sa[mx],sb[mx],t;
void srt(char str[])
{
 
    char k;
    int i,j,n;
    n=strlen(str);
    for(i=0; i<n-1; i++)
    {
        for(j=i+0; j<n; j++)
        {
            if(str[i]>str[j])
            {
                k=str[i];
                str[i]=str[j];
                str[j]=k;
            }
        }
    }
    if(t==0)
    {
        strcpy(sa,str);
        t=1;
    }
    else
        strcpy(sb,str);
}
void rev(char str[])
{
    int i,j,n,r=0;
    n=strlen(str);
    r=0;
    for(i=0; i<n; i++)
    {
        if(str[i]!=' ')
        {
            str2[r++]=tolower(str[i]);
        }
        str2[r]='\0';
    }
    srt(str2);
}
int main()
{
    char str[mx],str3[mx];
    int tes,i;
    scanf("%d\n",&tes);
    for(i=1; i<=tes; i++)
    {
        gets(str);
        gets(str3);
        rev(str);
        rev(str3);
        if(!strcmp(sa,sb))
            printf("Case %d: Yes\n",i);
        else
            printf("Case %d: No\n",i);
        t=0;
    }
}
 
