#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int>v[10100];
set<int>s[10100];
int col[10100];
void dfs(int u){
	for(int i=1;i<=k;i++)
		if(s[u].find(i)==s[u].end()){
			col[u]=i;
			break;
		}
	for(int i=0;i<v[u].size();i++)
		s[v[u][i]].insert(col[u]);
	for(int i=0;i<v[u].size();i++)
		if(!col[v[u][i]])dfs(v[u][i]);
}
int main(){
	freopen("kgraph.in","r",stdin);
	freopen("kgraph.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
		k=max(k,max((int)v[a].size(),(int)v[b].size()));
	}
	if(!(k&1))k++;
	dfs(1);
	printf("%d\n",k);
	for(int i=1;i<=n;i++)printf("%d\n",col[i]);
}


