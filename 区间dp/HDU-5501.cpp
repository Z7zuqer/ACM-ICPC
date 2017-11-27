#include<bits/stdc++.h>
using namespace std;
#define LL long long 
const int mod=1e9+7;
LL dp[110][110],col[110],C[110][110];
void pre(){
	C[0][0]=1;
	for(int i=1;i<110;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
}
LL dfs(int l,int r){
	if(dp[l][r]!=-1)return dp[l][r];
	if(l==r)return dp[l][r]=1;
	if(l>r)return dp[l][r]=0;
	LL ans=(dfs(l+1,r)+dfs(l,r-1))%mod;
	for(int i=l+1;i<r;i++){
		if(col[i-1]^col[i+1])continue;
		ans=(ans+dfs(l,i-1)*dfs(i+1,r)%mod*C[r-l][i-l]%mod)%mod;
	}
	return dp[l][r]=ans;
} 
int main(){
	int n;
	pre();
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++)scanf("%lld",&col[i]);
		memset(dp,-1,sizeof dp);
		printf("%lld\n",dfs(1,n));
	}
}


