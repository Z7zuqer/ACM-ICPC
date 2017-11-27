#include<bits/stdc++.h>
using namespace std;
int sumx[1000010],sumy[1000010];
struct node{
	int x,y,id;
}r[1000010];
int vis[1000010],ans[1000010];
int cmp1(node m,node n){
	return m.x<n.x;
}
int cmp2(node m,node n){
	return m.y<n.y;
} 
struct {
	int e,next;
}ed[1000010<<1];
int head[1000010],num,res;
void add(int s,int e){
	ed[num].e=e;ed[num].next=head[s];head[s]=num++;
}
void dfs(int u,int pre){
	if(!vis[u])vis[u]=1,res++;
	for(int i=head[u];i!=-1;i=ed[i].next)
		if(ed[i].e!=pre&&!vis[ed[i].e])dfs(ed[i].e,u);
}
int main(){
	freopen("codecoder.in","r",stdin);
	freopen("codecoder.out","w",stdout);
	int n;
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&r[i].x,&r[i].y);
		r[i].id=i;
	}
	sort(r+1,r+1+n,cmp1);
	for(int i=1;i<n;i++)add(r[i+1].id,r[i].id);
	sort(r+1,r+1+n,cmp2);
	for(int i=1;i<n;i++)add(r[i+1].id,r[i].id);
	for(int i=1;i<=n;i++){
		dfs(r[i].id,-1);
		if(res==0)ans[r[i].id]=0;
		else ans[r[i].id]=res-1;
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<endl;
}


