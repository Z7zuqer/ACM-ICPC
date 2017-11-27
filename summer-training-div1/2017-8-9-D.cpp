#include<bits/stdc++.h>
using namespace std;
const int maxn=200100;
vector<int>v[maxn];
int n,m,d,vis[maxn],del[maxn],deg[maxn],in[maxn];
vector<int>ans,now,tmp;
queue<int>q;
void dfs(int u){
	now.push_back(u);
	vis[u]=1;
	for(int i=0;i<v[u].size();i++)
		if(!vis[v[u][i]]&&!del[v[u][i]])
			dfs(v[u][i]);
}
int main(){
	//int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
		//ed[i].s=a;ed[i].e=b;
		deg[a]++;deg[b]++;
	}
	for(int i=1;i<=n;i++)
		if(deg[i]<d)
			in[i]=1,q.push(i);
	while(!q.empty()){
		int k=q.front();q.pop();del[k]=1;
		for(int i=0;i<v[k].size();i++){
			int e=v[k][i];
			if(del[e])continue;
			//deg[e]--;deg[k]--;
			//if(deg[e]==0)del[e]=1;
			//if(deg[k]==0)del[k]=1;
			if(--deg[e]<d&&!in[e])in[e]=1,q.push(e); 
		}
		//in[k]=0;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]&&!del[i]){
			now.clear();
			//cnt=0;
			dfs(i);
			if(now.size()>ans.size())ans=now;
		}
	if(ans.size()<=1)return 0*printf("NIE\n");
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());		
	for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);
}
