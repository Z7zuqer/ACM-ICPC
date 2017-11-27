#include<bits/stdc++.h>
using namespace std;
const int maxn=1007;
int n;
int dp[maxn][maxn],a[maxn];
int dfs(int l,int r){
	if(dp[l][r]!=-1)return dp[l][r];
	//if(l==r-1)return dp[l][r]=a[l]*a[r]+max(a[l],a[r]);
	for(int i=l+1;i<r;i++)dp[l][r]=max(dp[l][r],dfs(l+1,i-1)+dfs(i+1,r-1)+a[l]*a[r]*a[i]);
	return dp[l][r];
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(dp,-1,sizeof(dp));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),dp[i][i]=a[i];
		a[0]=a[n]=1;
		cout<<dfs(1,n)<<endl;
	}
}
