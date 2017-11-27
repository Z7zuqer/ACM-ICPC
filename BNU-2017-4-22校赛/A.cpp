#include<bits/stdc++.h>
using namespace std;
int n;
int mp[101][101];
int ans=1e9;
void dfs(int u,int pre,int now){
	if(u==n){
		ans=min(ans,now);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(mp[u][i]&&u!=i&&i!=pre)
			dfs(i,u,min(now,mp[i][u]));
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ans=1e9;
		scanf("%d",&n);
		memset(mp,0,sizeof mp);
		for(int i=1;i<=n*2-2;i++){
			int x;
			scanf("%d",&x);
			mp[(i+1)/2][(i+1)/2+1]=mp[(i+1)/2+1][(i+1)/2]+=x;
		}
		dfs(1,-1,1e9);
		cout<<ans<<endl;
	}
}


