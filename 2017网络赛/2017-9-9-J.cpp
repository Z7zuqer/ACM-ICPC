#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=10010;
vector<pair<int,LL> >v[2][maxn];
map<string,int>mp;
bitset<10000>pre[2][maxn];
char a[100],b[100];
struct node{
	LL va;
	int e,
	bitset<10000>psta;
};
queue<node>r;
int vis[maxn];
int spfa(){
	queue<int>q;
	q.push(3);
	dis[3]=0;
	memset(vis,0,sizeof vis);
	while(!q.empty()){
		int k=q.front();q.pop();
		for(int i=0;i<v[1][k][i].size();i++){
			int e=v[1][k][i].first;LL va=v[1][k][i].second;
			if(dis[k]+va<dis[e]){
				dis[e]=dis[k]+va;
				if(!vis[e]){
					q.push(e);
					vis[e]=1;
				}
			}
			if(e==1)r.push({})
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int m;
		mp.clear();
		int n=0;
		mp["Dalian"]=++n;
		mp["Xian"]=++n;
		mp["Shanghai"]=++n;
		scanf("%d",&m);
		while(!r.empty())r.pop();
		for(int i=1;i<=m;i++)for(int j=0;j<=1;j++)v[i][j].clear();
		for(int i=1;i<=m;i++){
			LL va;
			scanf("%s%s%lld",a,b,&va);
			if(!mp[(string)a])mp[(string)a]=++n;
			if(!mp[(string)b])mp[(string)b]=++n;
			int s=mp[(string)a],e=mp[(string)b];
			v[0][s].push_back({e,va});
			v[1][e].push_back({s,va});
		}
		for(int i=1;i<=n;i++)pre[i].reset();
		for(int i=1;i<=n;i++)dis[i]=1e18;
		dij(0);
	}
}


