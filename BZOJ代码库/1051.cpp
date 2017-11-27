#include<bits/stdc++.h>
using namespace std;
const int maxn=10050;
int head[maxn],num,head1[maxn],num1;
struct {
	int e,next;
}ed[maxn*5],ed1[maxn*5];
int dfn[maxn],low[maxn],ans[maxn],t[maxn],index2,index1,stack1[maxn],top;
int instack[maxn],vis[maxn];
int dep[maxn];
void add(int s,int e){
	ed[num].e=e;ed[num].next=head[s];head[s]=num++;
}
void add1(int s,int e){
	ed1[num1].e=e;ed1[num1].next=head1[s];head1[s]=num1++;dep[s]++;
}
void tarjan(int u){
	low[u]=dfn[u]=index2++;
	vis[u]=instack[u]=1;
	stack1[++top]=u;
	for(int i=head[u];i!=-1;i=ed[i].next){
		if(!vis[ed[i].e]){
			tarjan(ed[i].e);
			low[u]=min(low[u],low[ed[i].e]);
		}
		else if(instack[ed[i].e])low[u]=min(low[u],dfn[ed[i].e]);
	}
	if(low[u]==dfn[u]){
		++index1;
		int v=0;
		while(v!=u){
			t[stack1[top]]=index1;
			v=stack1[top];
			ans[index1]++;
			instack[stack1[top--]]=0;
		}
	}
}
void work(int u){
	for(int i=head[u];i!=-1;i=ed[i].next){
		if(t[u]!=t[ed[i].e])add1(t[u],t[ed[i].e]);
	}
}
int main(){
	memset(head,-1,sizeof(head));
	memset(head1,-1,sizeof(head1));
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		add(a,b);
	}
	tarjan(1);
	//for(int i=1;i<=n;i++)cout<<t[i]<<endl;
	for(int i=1;i<=n;i++)work(i);
	//for(int i=1;i<=index1;i++)cout<<ans[i]<<endl;
	for(int i=1;i<=index1;i++)
		if(!dep[i]){
			cout<<ans[i]<<endl;
			return 0;
		}
	cout<<0<<endl;
}
