#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=200010;
int n,col[maxn];
vector<pair<int,int> >v[maxn];
LL dp[maxn][2],A[maxn],sum[maxn][2];
void dfs(int u,int pre){
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i].first,va=v[u][i].second;
		if(e==pre)continue;
		dfs(e,u);
		if(col[e]==0){
			if(col[u]==0){
				dp[u][1]+=min(dp[e][1],dp[e][2]+va);
				dp[u][2]+=min(dp[e][1]+va,dp[e][2]);
				continue;
			}
			dp[u][col[u]]+=min(dp[e][3-col[u]]+va,dp[e][col[u]]);
			continue;
		}
		if(col[u]==0){
			if(col[e]==0){
				dp[u][1]+=min(dp[e][1],dp[e][2]+va);
				dp[u][2]+=min(dp[e][1]+va,dp[e][2]);
				continue;
			}
			if(col[e]==1)dp[u][1]+=dp[e][1],dp[u][2]+=(dp[e][1]+va);
			else dp[u][2]+=dp[e][2],dp[u][1]+=(dp[e][2]+va);
			continue;
		}
		if(col[u]==col[e])dp[u][col[u]]+=dp[e][col[u]];
		else dp[u][col[u]]+=(va+dp[e][col[e]]);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		int a,c,b;
		scanf("%d%d%d",&a,&b,&c);
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int x;
		scanf("%d",&x);
		col[x]=1;
	}
	int k;
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		int x;
		scanf("%d",&x);
		col[x]=2;
	}
	dfs(1,0);
	printf("%lld\n",(col[1]==0)?min(dp[1][1],dp[1][2]):dp[1][col[1]]);
}


