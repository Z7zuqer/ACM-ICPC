#include<bits/stdc++.h>
using namespace std;
const int maxn=100100;
int vis[maxn],d[maxn],d0[maxn],d1[maxn],d2[maxn];
vector<int>v[2][maxn];
void bfs(int n,int S,int f){
	queue<int>q;
	for(int i=1;i<=n;i++)vis[i]=0,d[i]=1e8;
	q.push(S);d[S]=0;vis[S]=1;
	while(!q.empty()){
		int k=q.front();q.pop();
		for(int i=0;i<v[f][k].size();i++){
			int e=v[f][k][i];
			if(!vis[e]){
				q.push(e);
				d[e]=d[k]+1;
				vis[e]=1;
			}
		}
	}
}
int n,m,k;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x;
		scanf("%d",&x);
		v[1][n+1].push_back(x);
	}
	for(int i=1;i<=k;i++){
		int x;
		scanf("%d",&x);
		v[1][n+2].push_back(x);
	}
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		for(int j=1;j<=x;j++){
			int b;
			scanf("%d",&b);
			v[0][i].push_back(b);
			v[1][b].push_back(i);
		}
	}
	bfs(n,1,0);
	for(int i=1;i<=n;i++)d0[i]=d[i];
	bfs(n,n+1,1);
	for(int i=1;i<=n;i++)d1[i]=d[i]-1;
	bfs(n,n+2,1);
	for(int i=1;i<=n;i++)d2[i]=d[i]-1;
	int ans=1e8;
	for(int i=1;i<=n;i++)
		ans=min(ans,d0[i]+d1[i]+d2[i]);
	if(ans>n)cout<<"impossible"<<endl;
	else cout<<ans<<endl;
}
