#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+10;
int n,a,b;
struct {
	int next,e;
}ed[maxn<<1];
int head[maxn],num,fa[maxn],vis[maxn];
int dep[maxn],ans[maxn],ace[maxn];
struct{
	int e,next;
	int index;
}req[2000010];
int head_req[maxn],req_num;
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void uni(int a,int b){
	int x=find(a);
	int y=find(b);
	if(x!=y)fa[y]=x;
}
void add(int s,int e){
	ed[num].e=e;ed[num].next=head[s];head[s]=num++;
}
void add_query(int s,int e,int sig){
	req[req_num].index=sig;req[req_num].e=e;req[req_num].next=head_req[s];head_req[s]=req_num++;
}
void dfs(int u,int pre,int d){
	dep[u]=d;
	for(int i=head[u];i!=-1;i=ed[i].next)
		if(ed[i].e!=pre)dfs(ed[i].e,u,d+1);
}
void LCA(int u){
	ace[u]=u;
	vis[u]=1;
	for(int i=head[u];i!=-1;i=ed[i].next){
		if(!vis[ed[i].e]){
			LCA(ed[i].e);
			uni(u,ed[i].e);
			ace[find(u)]=u;
		}
	}
	for(int i=head_req[u];i!=-1;i=req[i].next){
		if(vis[req[i].e]){
			ans[req[i].index]=ace[find(req[i].e)];
		}
	}
}
int tr[maxn<<2];
void pushup(int t){
	tr[t]=min(tr[t<<1],tr[t<<1|1]);
}
void build(int t,int l,int r){
	if(l==r){
		tr[t]=ans[l];
		return ;
	}	
	int mid=(l+r)>>1;
	build(t<<1,l,mid);
	build(t<<1|1,mid+1,r);
	pushup(t);
}
int query(int t,int L,int R,int l,int r){
	if(l>=L&&r<=R)return tr[t];
	int mid=(l+r)>>1,ret=1e9;
	if(L<=mid)ret=min(ret,query(t<<1,L,R,l,mid));
	if(R>mid)ret=min(ret,query(t<<1|1,L,R,mid+1,r));
	return ret;
}
int main(){
	memset(head,-1,sizeof(head));
	memset(head_req,-1,sizeof(head_req));
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		scanf("%d%d",&a,&b);
		add(a,b);add(b,a);
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	dfs(1,-1,0);
	int q;
	scanf("%d",&q);
	for(int i=1;i<n;i++){
		add_query(i,i+1,i);
		add_query(i+1,i,i);
	}
	LCA(1);
	build(1,1,n-1);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&a,&b);
		if(a==b)printf("%d\n",query(1,a,b,1,n-1));
		else printf("%d\n",query(1,a,b-1,1,n-1));
	}
}


