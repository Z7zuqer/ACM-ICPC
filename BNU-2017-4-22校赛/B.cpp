#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int head[maxn],num,n,q;
struct {
	int e,next;
}ed[maxn*2];
struct {
	int e,next,sig;
}req[maxn*4];
int head_req[maxn*2],num_req;
void add(int s,int e){
	ed[num].e=e;ed[num].next=head[s];head[s]=num++;
}
void add_req(int s,int e,int sig){
	req[num_req].sig=sig;req[num_req].e=e;req[num_req].next=head_req[s];head_req[s]=num_req++;
}
int lca[maxn*2],fa[maxn],vis[maxn*2],dis[maxn];
void dfs(int u,int pre){
	dis[u]=dis[pre]+1;
	for(int i=head[u];i!=-1;i=ed[i].next)
		if(ed[i].e!=pre)dfs(ed[i].e,u);
}
struct {
	int a,b,c;
}r[maxn];
int find(int x){
	return x==fa[x]?fa[x]:fa[x]=find(fa[x]);
}
void uni(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)fa[fx]=fy;
}
int anc[maxn*2];
void tarjan(int u,int pre){
	anc[u]=u;
	for(int i=head[u];i!=-1;i=ed[i].next){
		if(ed[i].e==pre)continue;
		tarjan(ed[i].e,u);
		uni(u,ed[i].e);
		anc[find(u)]=u;
	}
	vis[u]=1;
	for(int i=head_req[u];i!=-1;i=req[i].next){
		if(vis[req[i].e])
			lca[req[i].sig]=anc[find(req[i].e)];
	}
}
int main(){
	int T;
	cin>>T;dis[0]=-1;
	while(T--){
		memset(head,-1,sizeof head);
		memset(head_req,-1,sizeof head_req);
		num=num_req=0;
		memset(lca,0,sizeof lca);
		memset(vis,0,sizeof vis);
		scanf("%d%d",&n,&q);
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);add(y,x);
		}
		for(int i=1;i<=q;i++){
			scanf("%d%d%d",&r[i].a,&r[i].b,&r[i].c);
			add_req(r[i].a,r[i].c,i);
			add_req(r[i].c,r[i].a,i);
			add_req(r[i].b,r[i].c,i+q);
			add_req(r[i].c,r[i].b,i+q);
		}
		for(int i=1;i<=n;i++)fa[i]=i;
		tarjan(1,-1);
		dfs(1,0);
		//for(int i=1;i<=q+q;i++)cout<<lca[i]<<endl;
		for(int i=1;i<=q;i++){
			int d1=dis[r[i].b]+dis[r[i].c]-2*dis[lca[i+q]]+dis[r[i].c];
			int d2=dis[r[i].a];
			if(d1>d2)printf("YES\n");
			else if(d1==d2&&lca[i]!=1)printf("YES\n");
			else printf("NO\n");
		}
	}
}
