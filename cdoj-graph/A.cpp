#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int vis[maxn<<1+1010],ans=1e9,vis_ed[maxn<<1];
struct {
	int e,next,idx,v;
}ed[maxn<<1];
int head[maxn],n,num,m;
void add(int s,int e,int v,int idx){
	ed[num].e=e;ed[num].v=v;ed[num].idx=idx;ed[num].next=head[s];head[s]=num++;
}
void work(int k){
	if(k>=m)vis_ed[k]=vis_ed[k-m]=1;
	else vis_ed[k]=vis_ed[k+m]=1;
}
void dfs(int u,int pre,int maxv,int minv){
	if(u==n){
		ans=min(ans,maxv-minv);
		return ;
	}
	if(maxv-minv>=ans)return ;
	vis[u]=1;
	for(int i=head[u];i!=-1;i=ed[i].next){
		if(maxv-minv>=ans)return ;
		if(!vis[ed[i].e])work(ed[i].idx),dfs(ed[i].e,u,max(maxv,ed[i].v),min(minv,ed[i].v));
		else if(!vis_ed[ed[i].idx]&&(ed[i].v>maxv||ed[i].v<minv))work(ed[i].idx),dfs(ed[i].e,u,max(maxv,ed[i].v),min(minv,ed[i].v));
	}
}
int main(){	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)head[i]=-1;
	for(int i=0;i<m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z,i);
		add(y,x,z,i+m);
		if(x==1&&y==n)return 0*printf("0\n");
		if(x==n&&y==1)return 0*printf("0\n");
	}
	dfs(1,-1,-1,1e9);
	printf("%d\n",ans);
}


