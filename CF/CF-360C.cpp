#include<bits/stdc++.h>
using namespace std;
vector<int>v[100100];
int vis[100100],col[100100],flg=1;
vector<int>r[3];
void dfs(int u,int pre){
	if(pre!=-1)col[u]=3-col[pre];
	r[col[u]].push_back(u);
	if(!flg)return ;
	for(int i=0;i<v[u].size();i++){
		if(!col[v[u][i]]){
			if(!flg)return ;
			dfs(v[u][i],u);
		}
		else if(col[v[u][i]]){
			if(col[v[u][i]]==col[u]){
				flg=0;
				return ;
			}
		}
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		if(!col[i]){
			col[i]=1;
			dfs(i,-1);
			if(!flg)break;
		}
	if(!flg)cout<<"-1"<<endl;
	else {
		cout<<r[1].size()<<endl;
		for(int i=0;i<r[1].size();i++)printf("%d ",r[1][i]);cout<<endl;
		cout<<r[2].size()<<endl;
		for(int i=0;i<r[2].size();i++)printf("%d ",r[2][i]);cout<<endl;
	}
}


