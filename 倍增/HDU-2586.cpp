#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=50010;
#define EDGE(x,y) make_pair(x,y)
vector<pair<int,int> >v[maxn];
int n,fa[maxn][20],dis[maxn],vis[maxn];
LL dis[maxn];
void init_bz(){
	for(int i=1;i<=n;i++)
		for(int j=1;(1<<j)<=n;j++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
}
int LCA(int u,int v){
	if(dis[u]<dis[v])swap(u,v);
	int d=dis[u]-dis[v];
	for(int i=0;i<=log2(d)+1;++i)if((1<<i)&d)u=fa[u][i];
	if(u==v)return v;
	for(int i=(int)log2(dis[v]);i;--i)
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
		}
	return fa[u][0];
}
void dfs(int u,int pre,LL dist){
	dis[u]=dist;fa[u][0]=pre;dis[u]=dis[pre]+1;
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i].first,va=v[u][i].second;
		if(e==pre)continue;
		dfs(e,u,dist+va);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<=n-1;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			v[a].push_back(EDGE(b,c));
			v[b].push_back(EDGE(a,c));
		}
		dfs(1,0,0);
		init_bz();
		for(int i=1;i<=m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%I64d\n",dis[a]+dis[b]-2*dis[LCA(a,b)]);
		}
	}
}


