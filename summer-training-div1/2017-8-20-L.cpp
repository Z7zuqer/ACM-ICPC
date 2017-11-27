#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int v[5005],p[5005],n,link[5005];
long long l[5005],r[5005],dp[5005],ans=1e18;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&v[i]);
    for(int i=1;i<=n;i++)scanf("%d",&p[i]);
    for(int i=1;i<=n;i++)dp[i]=1e18;
    for(int i=1;i<=n;i++)l[i]=l[i-1]+v[i];
    for(int i=n;i>=1;i--)r[i]=r[i+1]+v[i];
    int pos=n;
    link[0]=n+1;
    for(int i=1;i<=n;i++)
    {
        while(l[i]>r[pos]&&pos>1)pos--;
        if(l[i]==r[pos]) link[i]=pos;
        else link[i]=-1;
    }
    for(int i=0;i<=n;i++)
    {
        if(link[i]==-1)continue;
        if(link[i]<=i)break;
        for(int j=0;j<i;j++)
        {
            if(link[j]==-1)continue;
            long long tmp=dp[j];
            tmp+=p[i-j]+p[link[j]-link[i]];
            dp[i]=min(dp[i],tmp);
        }
        long long tmpp=dp[i];
        tmpp+=p[link[i]-i-1];
        ans=min(ans,tmpp);
    }
    cout<<ans;
    return 0;
}

