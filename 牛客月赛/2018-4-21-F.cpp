#include<bits/stdc++.h>
using namespace std;
vector<int>v[10010];
int res[10010],vis[10010],dep[10010];
queue<int>q;
void dfs(int u,int pre,int dept){
	int flg=0;
	dep[u]=dept;
	for(auto x:v[u]){
		if(x==pre)continue;
		flg=1;
		dfs(x,u,dept+1);
	}
	if(!flg)res[u]=(dept+1)&1,q.push(u),vis[u]=1;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,r;
		scanf("%d%d",&n,&r);
		while(q.size())q.pop();
		for(int i=1;i<=n;i++)vis[i]=0,v[i].clear(),res[i]=-1;
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(r,-1,0);
		while(q.size()){
			int k=q.front();q.pop();
			for(auto x:v[k]){
				if(vis[x])continue;
				if(dep[x]%2==0){
					if(res[x]==-1)res[x]=res[k];
					else res[x]&=res[k];
				} 
				else{
					if(res[x]==-1)res[x]=res[k];
					else res[x]|=res[k];
				} 
				q.push(x);
				vis[x]=1;
			}
		}
		if(res[r]==0)puts("Gen");
		else puts("Dui");
	}
}


