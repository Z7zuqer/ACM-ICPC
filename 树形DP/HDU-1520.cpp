#include<bits/stdc++.h>
using namespace std;
const int maxn=6010;
int n;
int dp[maxn][2],vis[maxn],A[maxn],deg[maxn]; 
// 0 qu
vector<int>v[maxn];
void dfs(int u,int fa){
	vis[u]=1;
	dp[u][1]=A[u];
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i];
		if(!vis[e])dfs(e,u);
		dp[u][0]+=max(dp[e][1],dp[e][0]);
		dp[u][1]+=dp[e][0];
	}
}
int main(){
	//scanf("%d",&n);
	while(~scanf("%d",&n)){
		memset(vis,0,sizeof vis);
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<=n;i++)scanf("%d",&A[i]);
		int a,b;
		scanf("%d%d",&a,&b);
		while(a||b){
			v[b].push_back(a);
			deg[a]++;
			scanf("%d%d",&a,&b);
		}
		for(int i=1;i<=n;i++)
			if(!deg[i])
				dfs(i,-1);
		int maxm=0;
		for(int i=1;i<=n;i++)
			maxm=max(maxm,max(dp[i][0],dp[i][1]));
		cout<<maxm<<endl;
	}
}


