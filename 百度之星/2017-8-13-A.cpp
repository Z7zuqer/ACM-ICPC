#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int mod=1e9+7;
LL dp[1010][1010],sum[1010];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		memset(dp,0,sizeof dp);
		memset(sum,0,sizeof sum);
		for(int i=1;i<=m;i++)dp[1][i]=1;
		for(int i=1;i<=m;i++)sum[i]=sum[i-1]+dp[1][i];
		for(int i=2;i<=n;i++){
			for(int j=1;j<=m;j++){
				dp[i][j]=(sum[j-1]+dp[i][j]+1)%mod;
			}
			for(int j=1;j<=m;j++)sum[j]=(sum[j]+sum[j-1]+dp[i][j])%mod;
		}
		LL ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				ans=(ans+dp[i][j])%mod;
		//ans=(ans+1LL*n*m-1)%mod;
		printf("%I64d\n",ans);
	}
}


