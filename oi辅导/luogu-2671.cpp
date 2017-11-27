#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int mod=10007;
int A[100010],vis[100010];
LL sum[100010][2][2],res[100010][2],siz[100010][2];
int main(){
	int n,m,cnt=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if(!vis[x])vis[x]=++cnt;
		int now=vis[x];
		sum[now][i&1][0]=(sum[now][i&1][0]+A[i])%mod;
		sum[now][i&1][1]=(sum[now][i&1][1]+i)%mod;
		res[now][i&1]=(res[now][i&1]+1LL*A[i]*i%mod)%mod;
		siz[now][i&1]++;
	}
	LL ans=0;
	for(int i=1;i<=cnt;i++)
		for(int j=0;j<=1;j++)
			if(siz[i][j]>=2){
				ans=(ans+sum[i][j][0]*sum[i][j][1]+(siz[i][j]-2)*res[i][j])%mod;
			}
	printf("%lld\n",ans);
}


