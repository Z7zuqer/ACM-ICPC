#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
vector<pair<int,int> >v[maxn];
int maxm,rt,dp[maxn],dis[maxn][2],path[maxn][2];
void dfs(int u,int fa){
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i].first,va=v[u][i].second;
		if(e!=fa){
			dfs(e,u);
			if(dis[e][1]+va>dis[u][1]){
				dis[u][0]=dis[u][1];
				dis[u][1]=dis[e][1]+va;
			}
			else if(dis[e][1]+va>dis[u][0])dis[u][0]=va+dis[e][1];
		}
	}
}
void DP(int u,int fa){
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i].first,va=v[u][i].second;
		if(e!=fa){
			//cout<<e<<" "<<u<<" ";
			dp[e]=max(dp[u],(dis[e][1]+va==dis[u][1])?dis[u][0]:dis[u][1])+va;
			//cout<<dp[e]<<endl;
			DP(e,u);
		}
	}
}
int main(){
	int n;
	while(~scanf("%d",&n)&&n){
		for(int i=1;i<=n;i++)v[i].clear();
		memset(dp,0,sizeof dp);
		memset(dis,0,sizeof dis);
		for(int i=2;i<=n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			v[a].push_back({i,b});
			v[i].push_back({a,b});
		}
		dfs(1,-1);
		DP(1,-1);
		dp[1]=max(dis[1][1],dis[1][0]);//dis[1][1]+dis[1][0];
		for(int i=1;i<=n;i++)cout<<max(dp[i],dis[i][1])<<endl;
	}
}


