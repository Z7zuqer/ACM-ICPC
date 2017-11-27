#include<bits/stdc++.h>
using namespace std;
const int maxn=50100;
vector<int>v[maxn];
int dp[maxn][2],sum[maxn];
void dfs(int u,int fa){
	//dp[u][1]=1;
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i];
		if(e==fa)continue;
		dfs(e,u);
		sum[u]+=sum[e]+1;
	}
}
void DP1(int u,int fa){
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i];
		if(e==fa)continue;
		dp[u][1]=max(dp[u][1],sum[e]+1);
		DP1(e,u);
	}
}
void DP2(int u,int fa){
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i];
		if(e==fa)continue;
		DP2(e,u);
		//if(u==1)dp[u][0]=max(dp[u][0],dp[e][1]);
		dp[e][0]=max(dp[u][0]+1+sum[u]-sum[e]-1,dp[e][0]);
	} 
}
vector<int>r;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,-1);
	DP1(1,-1);
	DP2(1,-1);
	cout<<endl;for(int i=1;i<=n;i++)printf("%d %d %d\n",dp[i][0],dp[i][1],sum[i]);
	int minm=1e9,rt=-1;
	for(int i=1;i<=n;i++)
		if(minm>max(dp[i][0],dp[i][1])){
			r.clear();
			r.push_back(i);
			minm=max(dp[i][0],dp[i][1]);
		}
		else if(minm==max(dp[i][0],dp[i][1]))r.push_back(i);
	for(int i=0;i<r.size();i++)printf("%d ",r[i]);cout<<endl;
}


