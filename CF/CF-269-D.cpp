#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=2010;
int faa[maxn];
LL d[maxn][maxn];
int find(int x){
	if(faa[x]==x)return x;
	return faa[x]=find(faa[x]);
}
void uni(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)faa[fx]=fy;
}
struct node{
	int x,y,z;
	bool operator <(const node rhs)const{
		return z>rhs.z;
	}
};
int n,vis[maxn];
LL deep[maxn],fa[maxn][30],dis[maxn];
vector<pair<int,int> >v[maxn];
void dfs(int u,int pre,LL dist){
	fa[u][0]=pre;deep[u]=deep[pre]+1;dis[u]=dist;vis[u]=1;
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i].first,va=v[u][i].second;
		if(e==pre||vis[e])continue;
		dfs(e,u,dist+va);
	}
}
void init_bz(){
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
}
int LCA(int u,int v){
	if(deep[u]<deep[v])swap(u,v);
	int cal=deep[u]-deep[v];
	for(int i=0;(1<<i)<=cal;++i)if((1<<i)&cal)u=fa[u][i];
	if(u==v)return v;
	for(int i=(int)log2(n);i>=0;--i)
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
		}
	return fa[u][0];
}
priority_queue<node>q;
LL getdis(int a,int b){
	int LCAab=LCA(a,b);
	return dis[a]+dis[b]-dis[LCAab]*2;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)faa[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			scanf("%d",&d[i][j]);
			if(i<j)q.push({i,j,d[i][j]});
			if(i==j&&d[i][j]!=0)return 0*printf("NO\n");
			if(i!=j&&d[i][j]==0)return 0*printf("NO\n");
		}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(d[i][j]!=d[j][i])return 0*printf("NO\n");
	int cnt=0;
	while(!q.empty()){
		int s=q.top().x,e=q.top().y,va=q.top().z;q.pop();
		if(find(s)==find(e))continue;
		v[s].push_back({e,va});
		v[e].push_back({s,va});
		cnt++;
		uni(s,e);
	}
	if(cnt!=n-1)return 0*printf("NO\n");
	dfs(1,0,0);
	init_bz();
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++) 
			if(getdis(i,j)!=d[i][j])
				return 0*printf("NO\n");
	puts("YES");
}


