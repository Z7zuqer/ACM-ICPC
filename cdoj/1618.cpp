#include<bits/stdc++.h>
using namespace std;
int n,m,A[110];
vector<pair<int,int> >v[110];
int vis[110],dis[110],req[110];
int spfa(){
	memset(dis,0x3f,sizeof dis);
	vis[1]=1;
	dis[1]=0;req[1]=A[1];
	queue<int>q;
	q.push(1);
	while(!q.empty()){
		int k=q.front();q.pop();vis[k]=0;
		for(int i=0;i<v[k].size();i++){
			int x=v[k][i].first,y=v[k][i].second;
			if(dis[k]+y<dis[x]){
				dis[x]=dis[k]+y;
				req[x]=req[k]+A[x];
				if(!vis[x]){
					vis[x]=1;
					q.push(x);
				}
			}
			else if(dis[k]+y==dis[x]){
				req[x]=max(req[x],req[k]+A[x]);
				if(!vis[x]){
					vis[x]=1;
					q.push(x);
				}
			}
		}
	}
	if(dis[n]==dis[n+1])return -1;
	return req[n];
}
int main(){
	 scanf("%d",&n);
	 for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	 scanf("%d",&m);
	 for(int i=1;i<=m;i++){
	 	int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		v[x].push_back({y,z});
		v[y].push_back({x,z});
	 }
	 int r=spfa();
	 if(r==-1)cout<<"impossible"<<endl;
	 else cout<<dis[n]<<" "<<r<<endl;
}


