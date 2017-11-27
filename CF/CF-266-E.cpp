#include<bits/stdc++.h>
using namespace std;
const int maxn=100100+7;
int fa[maxn],dep[maxn];
vector<int>v[maxn];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void dfs(int u,int pre){
	dep[u]=dep[pre]+1;
	for(int i=0;i<v[u].size();i++)	
		if(v[u][i]!=pre)dfs(v[u][i],u);
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int k;
		scanf("%d",&k);
		if(k==1){
			int x,y;
			scanf("%d%d",&x,&y);
			fa[x]=y;
			v[y].push_back(x);
			dfs(find(y));
		}
		if(k==2){
			
		}
		if(k==3){
			
		}
	}
}


