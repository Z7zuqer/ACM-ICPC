#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int W[1010],A[1010],B[1010];
int dp[2010];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(dp,0,sizeof dp);
		scanf("%d%d",&m,&n);
		for(int i=1;i<=n;i++)scanf("%d%d%d",&W[i],&A[i],&B[i]);
		for(int i=1;i<=n;i++){
			for(int j=m;j>=W[i];j--)dp[j]=max(dp[j],dp[j-W[i]]+A[i]+B[i]);
			for(int j=W[i];j<=m;j++)dp[j]=max(dp[j],dp[j-W[i]]+A[i]);
		}
		int ans=0;
		for(int i=0;i<=m;i++)ans=max(ans,dp[i]);
		cout<<ans<<endl;
	}
}


