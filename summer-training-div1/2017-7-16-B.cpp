#include<bits/stdc++.h>
using namespace std;
const int maxn=100100;
vector<int>v[maxn];
int vis[maxn],maxm;
void dfs(int u,int fa,int dist){
	vis[u]=1;
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i];
		if(e==fa)continue;
		if(!vis[e]){
			maxm=max(maxm,dist+1);
			dfs(e,u,dist+1);
		}
	}
}
int deg[maxn];
vector<int>r;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		deg[b]++;
	}
	for(int i=1;i<=n;i++)
		if(!deg[i])
			r.push_back(i);
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		dfs(i,-1,1);
	}
	printf("%d\n",maxm);
}


