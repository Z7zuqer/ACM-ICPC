#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

char s[5005];
int t,m,ans;

int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d%s",&m,s);
        int len=strlen(s);
        for(int l1=0,l2=1;l2<len;l1++,l2++)
        {
            int sum=0;
            int tl1=l1,tl2=l2,tmpr,tmpl;
            for(int r1=l1,r2=l2;r1>=0&&r2<len;r1--,r2++)
            {
                tmpr=s[r1]-s[r2];
                if(tmpr<0)tmpr=-tmpr;
                sum+=tmpr;
                while(sum>m)
                {
                    tmpl=s[tl1]-s[tl2];
                    if(tmpl<0)tmpl=-tmpl;
                    sum-=tmpl;
                    tl1--;tl2++;
                }
                if(ans<r2-tl2+1)ans=r2-tl2+1;
            }
        }
        for(int l1=0,l2=2;l2<len;l1++,l2++)
        {
            int sum=0;
            int tl1=l1,tl2=l2,tmpr,tmpl;
            for(int r1=l1,r2=l2;r1>=0&&r2<len;r1--,r2++)
            {
                tmpr=s[r1]-s[r2];
                if(tmpr<0)tmpr=-tmpr;
                sum+=tmpr;
                while(sum>m)
                {
                    tmpl=s[tl1]-s[tl2];
                    if(tmpl<0)tmpl=-tmpl;
                    sum-=tmpl;
                    tl1--;tl2++;
                }
                if(ans<r2-tl2+1)ans=r2-tl2+1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

