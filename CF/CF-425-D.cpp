#include<bits/stdc++.h>
using namespace std;
const int maxn=100100;
int n,q,fa[maxn][27],dis[maxn];
vector<int>v[maxn];
void dfs(int u,int pre,int dist){
	fa[u][0]=pre;dis[u]=dist;
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i];
		if(e==pre)continue;
		dfs(e,u,dist+1);
	}
}
int LCA(int u,int v){
	if(dis[u]<dis[v])swap(u,v);
	int d=dis[u]-dis[v];
	for(int i=0;(1<<i)<=d;++i)if((1<<i)&d)u=fa[u][i];
	if(u==v)return v;
	for(int i=(int)log2(n);i>=0;--i)
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
		}
	return fa[u][0];
}
int getans(int a,int b,int c){
	int x=LCA(a,b);
	int y=LCA(b,c);
	if(dis[x]<dis[y]){
		int dis_1=dis[b]-dis[y]+1;
		return dis_1;
	}
	else if(dis[x]>dis[y]){
		int dis_1=dis[b]-dis[x]+1;
		return dis_1;
	}
	else {
		int z=LCA(a,c);
		int dis_1=dis[z]-dis[x]+1;
		int dis_2=dis[b]-dis[x]+1;
		return dis_1+dis_2-1;
	}
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++){
		int x;
		scanf("%d",&x);
		v[x].push_back(i);
		v[i].push_back(x);
	}
	dfs(1,0,0); 
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
	while(q--){
		int a,b,c,ans=0;
		scanf("%d%d%d",&a,&b,&c);
		ans=max(ans,getans(a,b,c));
		ans=max(ans,getans(c,a,b));
		ans=max(ans,getans(c,b,a));
		ans=max(ans,getans(a,c,b));
		ans=max(ans,getans(b,a,c));
		ans=max(ans,getans(b,c,a));
		printf("%d\n",ans);
	}
}


