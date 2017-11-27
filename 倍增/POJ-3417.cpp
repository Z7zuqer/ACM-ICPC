#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=100100;
vector<int>v[maxn];
int n,fa[maxn][30],deep[maxn];
void init_bz(){
	for(int i=1;i<=n;i++)
		for(int j=1;(1<<j)<=n;j++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
}
int LCA(int u,int v){
	if(deep[u]<deep[v])swap(u,v);
	int cal=deep[u]-deep[v];
	for(int i=0;i<=(int)log2(cal);i++)if((1<<i)&cal)u=fa[u][i];
	if(u==v)return v;
	for(int i=log2(deep[v]);i;i--)
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
		}
	return fa[u][0];
}
void dfs(int u,int pre){
	deep[u]=deep[pre]+1;fa[u][0]=pre;
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i];
		if(e==pre)continue;
		dfs(e,u);
	}
}
int main(){
	int m;
	while(scanf("%d%d",&n,&m)==2){
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		long long ans=0;
		dfs(1,0);
		for(int i=1;i<=m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			ans+=deep[a]+deep[b]-2*deep[LCA(a,b)];
		}
		cout<<ans<<endl;	
	}
}

 
