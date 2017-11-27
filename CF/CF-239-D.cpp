#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=1010;
const int mod=1e9+7;
LL dp[maxn][maxn],A[maxn];
LL dfs(int l,int r){
	if(dp[l][r]!=-1)return dp[l][r];
	if(l==r)return dp[l][r]=1;
	dp[l][r]=0;
	dp[l][r]=(dfs(l,r-1)+dfs(A[r-1],r-1)+1)%mod;
	return dp[l][r];
}
int main(){
	memset(dp,-1,sizeof dp);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",&A[i]);
	printf("%I64d\n",(dfs(1,n+1)-1LL)%mod);
}
