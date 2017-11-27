#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=10010;
int T; 
vector<pair<int,LL> >v[maxn];
int deg[maxn];
LL dis[maxn];
void dij(){
	memset(dis,-1,sizeof dis);
	memset(deg,0,sizeof deg);
	dis[0]=0;
	priority_queue<pair<LL,int> >q;
	q.push({0,0});
	while(!q.empty()){
		LL va=q.top().first;int k=q.top().second;q.pop();
		//if(va<dis[k])continue;
		for(int i=0;i<v[k].size();i++){
			int e=v[k][i].first;
			LL ve=v[k][i].second;
			if(dis[k]+ve>dis[e]){
				//cout<<e<<" "<<k<<" "<<ve<<endl;
				dis[e]=dis[k]+ve;
				q.push({ve,e});
			}
		}
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++)v[i].clear();
		for(int i=1;i<=m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			v[a].push_back({b,c});
		//	v[b].push_back({a,c});
		}
		for(int i=1;i<=n;i++)v[0].push_back({i,0});
		dij();
		LL maxv=0;
		for(int i=1;i<=n;i++)maxv=max(maxv,dis[i]);
		printf("%lld\n",maxv);
	}
}


