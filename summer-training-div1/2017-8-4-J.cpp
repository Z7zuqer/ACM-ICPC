#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define PB push_back
typedef long long LL;
typedef pair<int,int> PII;
const double eps=1e-8;
const double pi=acos(-1.0);
const int K=1e6+7;
const int mod=1e9+7;

int n,m,k;
LL ls[3000],rd[3000],cnt[3000];
LL ans=2e18;
bool dp[2][101005];
bool cmp(int a,int b)
{
    return ls[a]<ls[b];
}
int main(void)
{
    //freopen("in.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++) rd[i]=i;
    for(int i=1,x;i<=n;i++)
        scanf("%d",&x),ls[x]=i,cnt[x]++;
    sort(rd+1,rd+m+1,cmp);
    dp[0][0]=1;
    for(int i=1,now=1,pre=0;i<=m;i++)
    {
        //printf("%d\n",rd[i]);
        for(int j=0;j<=k;j++)
        if(dp[pre][j]&&j+cnt[rd[i]]<=k&&n-j-cnt[rd[i]]<=k)
            ans=min(ans,1LL*(j+cnt[rd[i]])*ls[rd[i]]+1LL*(n-j-cnt[rd[i]])*n);
        for(int j=0;j<=k;j++)
        {
            dp[now][j]|=dp[pre][j];
            if(j+cnt[rd[i]]<=k)
               dp[now][j+cnt[rd[i]]]|=dp[pre][j];
            dp[pre][j]=0;
        }
        swap(now,pre);
    }
    if(ans==2e18) printf("-1\n");
    else printf("%lld\n",ans);
    return 0;
}
