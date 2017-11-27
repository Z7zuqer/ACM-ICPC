#include<bits/stdc++.h>
using namespace std;
const int maxn=30050;
int size[maxn],fa[maxn],dep[maxn];
int head[maxn],num=0;
int seq[maxn],pos[maxn],sz=0;
int v[maxn];
struct {
	int e,next;
}ed[maxn<<1];
struct {
	int l,r,sum,maxm;
}tr[maxn*4];
void add(int s,int e){
	ed[num].e=e;ed[num].next=head[s];head[s]=num++;
}
void dfs(int u){
	size[u]=1;
	for(int i=head[u];i!=-1;i=ed[i].next){
		if(ed[i].e!=fa[u]){
			fa[ed[i].e]=u;
			dep[ed[i].e]=dep[u]+1;
			dfs(ed[i].e);
			size[u]+=size[ed[i].e];
		}
	}
}
void dfs2(int u,int chain){
	pos[u]=++sz;
	seq[u]=chain;
	int k=0;
	for(int i=head[u];i!=-1;i=ed[i].next)
		if(dep[u]<dep[ed[i].e]&&size[ed[i].e]>size[k])
			k=ed[i].e;
	if(k==0)return ;
	dfs2(k,chain);
	for(int i=head[u];i!=-1;i=ed[i].next)
		if(k!=ed[i].e&&dep[u]<dep[ed[i].e])
			dfs2(ed[i].e,ed[i].e);
}
void pushup(int t){
	tr[t].sum=tr[t<<1].sum+tr[t<<1|1].sum;
	tr[t].maxm=max(tr[t<<1].maxm,tr[t<<1|1].maxm);
}
void build(int l,int r,int t){
	tr[t].l=l;tr[t].r=r;
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(l,mid,t<<1);
	build(mid+1,r,t<<1|1);
}
void change(int t,int x,int k){
	int mid=(tr[t].l+tr[t].r)>>1;
	if(tr[t].l==tr[t].r){
		tr[t].maxm=tr[t].sum=k;
		return ;
	}
	if(x<=mid)change(t<<1,x,k);
	else change(t<<1|1,x,k);
	pushup(t);
} 
int querysum(int t,int l,int r){
	if(tr[t].l>=l&&tr[t].r<=r)return tr[t].sum;
	int mid=(tr[t].l+tr[t].r)>>1,ret=0;
	if(mid>=r)return querysum(t<<1,l,r);
	else if(mid<l)return querysum(t<<1|1,l,r);
	else return querysum(t<<1,l,mid)+querysum(t<<1|1,mid+1,r);
}
int querymx(int t,int l,int r){
	if(tr[t].l>=l&&tr[t].r<=r)return tr[t].maxm;
	int mid=(tr[t].l+tr[t].r)>>1,ret=0;
	if(mid>=r)return querymx(t<<1,l,r);
	else if(mid<l)return querymx(t<<1|1,l,r);
	else return max(querymx(t<<1,l,mid),querymx(t<<1|1,mid+1,r));
}
int worksum(int x,int y){
	int sum=0;
	while(seq[x]!=seq[y]){
		if(dep[seq[x]]<dep[seq[y]])swap(x,y);
		sum+=querysum(1,pos[seq[x]],pos[x]);
		x=fa[seq[x]];
	}
	if(pos[x]>pos[y])swap(x,y);
	sum+=querysum(1,pos[x],pos[y]);
	return sum;
}
int workmax(int x,int y){
	int mx=-0x7fffffff;
	while(seq[x]!=seq[y]){
		if(dep[seq[x]]<dep[seq[y]])swap(x,y);
		mx=max(mx,querymx(1,pos[seq[x]],pos[x]));
		x=fa[seq[x]];
	}
	if(pos[x]>pos[y])swap(x,y);
	mx=max(mx,querymx(1,pos[x],pos[y]));
	return mx;
}
int main(){
	int n,q,a,b;
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		scanf("%d%d",&a,&b);
		add(a,b);add(b,a);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	dfs(1);
	dfs2(1,1);
	scanf("%d",&q);
	build(1,n,1);
	for(int i=1;i<=n;i++)
		change(1,pos[i],v[i]);
	char s[20];
	//cout<<"dsa"<<endl;
	while(q--){
		scanf("%s%d%d",s,&a,&b);
		if(s[0]=='C')change(1,pos[a],b);
		if(s[1]=='M')printf("%d\n",workmax(a,b));
		if(s[1]=='S')printf("%d\n",worksum(a,b));
	}
}
