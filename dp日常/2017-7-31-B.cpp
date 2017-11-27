#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=20010;
int dp[maxn][2],n,size[maxn];
vector<int>v[maxn];
void dfs(int u,int pre){
	size[u]=1;
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i];
		if(e==pre)continue;
		dfs(e,u);
		size[u]+=size[e];
		dp[u][0]=max(dp[u][0],size[e]);
	}
}
void DP(int u,int pre){
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i];
		if(e==pre)continue;
		dp[e][1]=size[u]-size[e]-1+dp[u][1];
		DP(e,u);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			v[i].clear();
			size[i]=0;
			dp[i][0]=dp[i][1]=0;
		}
		for(int i=1;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		dfs(1,0);
		DP(1,0);
		//for(int i=1;i<=n;i++)cout<<dp[i][1]<<" ";cout<<endl;
		int minm=1e9,ans=-1;
		for(int i=1;i<=n;i++)
			if(max(dp[i][0],dp[i][1])<minm){
				minm=max(dp[i][0],dp[i][1]);
				ans=i;
			}
		cout<<ans<<" "<<minm<<endl;
	} 
}


