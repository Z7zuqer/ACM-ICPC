#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int dp[maxn][maxn],A[maxn],s[maxn],vis[maxn][maxn];
int dfs(int l,int r){
	//cout<<l<<" "<<r<<endl;
	if(vis[l][r])return dp[l][r];
	vis[l][r]=1;
	if(l==r)return dp[l][r]=A[l];
	int mx=0;
	for(int i=l;i<r;i++)mx=min(mx,dfs(l,i));
	for(int i=r;i>l;i--)mx=min(mx,dfs(i,r));
	return dp[l][r]=s[r]-s[l-1]-mx;
}
int main(){
	int n;
	while(scanf("%d",&n)==1&&n){
		//memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		s[0]=0;
		for(int i=1;i<=n;i++)scanf("%d",&A[i]),s[i]=s[i-1]+A[i];
		cout<<2*dfs(1,n)-s[n]<<endl;
	}
}


