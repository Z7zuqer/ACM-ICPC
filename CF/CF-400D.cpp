#include<bits/stdc++.h>
using namespace std;
const int maxn=200100;
int A[maxn],n,m,flg;
int head[maxn<<1],num,vis[maxn<<1];
struct {
	int e,next;
}ed[maxn<<2];
vector<int>v[maxn];
void add(int s,int e){
	ed[num].e=e;ed[num].next=head[s];head[s]=num++;
}
void dfs(int u,int pre,int col){
	vis[u]=col;
	if(u>m&&vis[u]==vis[u-m]){
		flg=1;
		return ;
	}
	if(u<=m&&vis[u]==vis[u+m]){
		flg=1;
		return ;
	}
	for(int i=head[u];i!=-1;i=ed[i].next)
		if(!vis[ed[i].e])dfs(ed[i].e,u,col);
}
int main(){
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	for(int i=1;i<=m;i++){
		int k,a;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d",&a);
			v[a].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		int s=v[i][0];
		int e=v[i][1];
		if(!A[i]){
			add(s,e+m);add(e+m,s);
			add(e,s+m);add(s+m,e);
		}
		else {
			add(s,e);add(e,s);
			add(s+m,e+m);add(e+m,s+m);
		}
	}
	for(int i=1;i<=m+m;i++){
		if(!vis[i]){
			dfs(i,-1,i);
			if(flg){
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
}


