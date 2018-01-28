#include<bits/stdc++.h>
using namespace std;
int dp[1010],son[1010],ans,rtans,n;
vector<int>v[1010];
void dfs(int u,int pre){
	son[u]=1;
	for(auto i:v[u]){
		if(i==pre)continue;
		dfs(i,u);
		son[u]+=son[i];
	}
}
int check(int u,int pre){
	int check_ans=-1;
	for(auto i:v[u]){
		if(i==pre)continue;
		if(check_ans==-1)check_ans=son[i];
		else if(son[i]!=check_ans)return 0;
	}
	if(pre==-1)return 0*(rtans=max(rtans,check_ans))+1;
	else {
		if(check_ans==-1)return 0;
		if(son[pre]-son[u]!=check_ans)return 0;
	}
	rtans=max(rtans,check_ans);
	return 1;
}
void DP(int u,int pre){
	if(check(u,pre))ans=min(ans,u);
	for(auto i:v[u]){
		if(i==pre)continue;
		DP(i,u);
	}
}
int main(){
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++)v[i].clear(),son[i]=0,dp[i]=0;
		for(int i=1;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		dfs(1,-1);
		ans=1e9;rtans=0;
		DP(1,-1);
		printf("%d %d\n",ans,rtans);
	}
}


