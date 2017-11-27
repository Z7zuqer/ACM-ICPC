#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
vector<int>v[maxn],en,res;
int vis[maxn],maxv,n,maxdis,idx,len,rt1,rt2,dis[maxn];
void dfs1(int u,int pre,int dist){
	if(dist>len){
		en.clear();
		en.push_back(u);
	}
	else if(dist==len)en.push_back(u);
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i];
		if(e!=pre)
			dfs1(e,u,dist+1);
	}
}
void dfs2(int u,int pre,int dist){
	if(dist>len){
		res.clear();
		res.push_back(u);
	}
	else if(dist==len)res.push_back(u);
	dis[u]=dist;
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i];
		if(e!=pre)
			dfs2(e,u,dist+1);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)v[i].clear();
		memset(vis,0,sizeof vis);
		memset(dis,0,sizeof dis); 
		for(int i=1;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		en.clear();len=1;
		dfs1(1,-1,1);cout<<len<<endl;while(1);
		for(auto e:en){
			res.clear();len=1;
			dfs2(e,-1,1);
			queue<pair<int,int> >q;
			for(auto x:res)q.push({x,len});
			while(!q.empty()){
				int k=q.front().first,lenk=q.front().second;q.pop();vis[k]=1;
				for(auto u:v[k]){
					if(dis[u]==lenk-1&&!vis[u]){
						q.push({u,lenk-1});
						vis[u]=1;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)if(vis[i])cout<<i<<endl;
	}
}


