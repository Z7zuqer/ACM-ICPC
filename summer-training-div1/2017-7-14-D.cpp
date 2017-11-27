#include<bits/stdc++.h>
using namespace std;
vector<int>v[1010];
int n,m,dis[1010],vis[1010],sg[1010];
vector<int>ord;
void bfs(){
	for(int i=1;i<=n;i++)dis[i]=1e8;
	dis[1]=0;
	queue<int>q;
	q.push(1);
	vis[1]=1;
	while(!q.empty()){
		int k=q.front();q.pop();
		ord.push_back(k);
		for(int i=0;i<v[k].size();i++){
			int e=v[k][i];
			if(vis[e])continue;
			dis[e]=dis[k]+1;
			q.push(e);
			vis[e]=1;
		}
	}
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs();
	for(int i=ord.size()-1;i>=1;i--){
		int k=ord[i];
		for(int j=0;j<v[k].size();j++){
			int e=v[k][j];
			if(dis[k]!=dis[e]+1)continue;
			if(sg[k]==0)sg[e]=1;
		}
	}
	if(sg[1]==0)cout<<"Nikolay"<<endl;
	else cout<<"Vladimir"<<endl;
}


