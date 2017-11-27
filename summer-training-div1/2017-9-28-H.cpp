#include<bits/stdc++.h>
using namespace std;
vector<int>v[1010];
int k,col[1010],vis[1010],flg,pos;
void dfs(int u){
	pos++;
	for(auto i:v[u])if(col[i])vis[col[i]]=pos;
	for(int i=1;;i++)if(vis[i]<pos){
		col[u]=i;
		if(i>k)flg=1;
		break;
	}
	for(auto i:v[u])if(!col[i])dfs(i);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		flg=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<=m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		memset(col,0,sizeof col);
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++)
			if(!col[i])
				dfs(i);
		if(!flg){
			printf("coloring ");
			for(int i=1;i<=n;i++)printf("%d ",col[i]);
			puts("");
			continue;
		}
		int res=-1;
		for(int i=1;i<=n;i++)
			if(col[i]==k+1){
				res=i;
				break;
			}
		printf("path ");
		for(int i=k+1;i>=1;i--){
			printf("%d ",res);
			for(auto u:v[res])
				if(col[u]==i-1){
					res=u;
					break;
				}
		}
		puts("");
	}
}


