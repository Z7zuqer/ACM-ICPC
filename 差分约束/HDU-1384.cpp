#include<bits/stdc++.h>
using namespace std;
const int maxn=50100;
int n,insta[maxn],incnt[maxn],dis[maxn];
vector<pair<int,int> >v[maxn];
int spfa(){
	queue<int>q;
	memset(insta,0,sizeof insta);
	memset(incnt,0,sizeof incnt);
	memset(dis,-63,sizeof dis);
	q.push(1);
	insta[1]=1;
	incnt[1]++;
	dis[1]=0;
	while(!q.empty()){
		int k=q.front();q.pop();
		for(int i=0;i<v[k].size();i++){
			int e=v[k][i].first,va=v[k][i].second;
			if(dis[k]+va>dis[e]){
				dis[e]=dis[k]+va;
				if(!insta[e]){
					insta[e]=1;
					q.push(e);
					if(++incnt[e]>n)return 0;
				}
			}
		}
	}
	int maxm=0;
	for(int i=1;i<=n+1;i++)maxm=max(maxm,dis[i]);
	return maxm;
}
int main(){
	while(~scanf("%d",&n)){
		for(int i=1;i<=n+1;i++)v[i].clear();
		for(int i=1;i<=n;i++){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			x++;y++;
			v[x-1].push_back({y,z});
		}
		for(int i=1;i<=n+1;i++)v[i].push_back({i-1,-1});
		for(int i=1;i<=n+1;i++)v[i-1].push_back({i,0});
		printf("%d\n",spfa());
	}
}


