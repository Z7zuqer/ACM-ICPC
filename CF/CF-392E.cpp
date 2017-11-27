#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=1e5+10;
int n;
struct {
	int e,next;
	LL w,p;
}ed[maxn<<1];
int head[maxn],num;
void add(int s,int e,LL w,LL p){
	ed[num].w=w;ed[num].p=p;ed[num].e=e;ed[num].next=head[s];head[s]=num++;
}
LL W[maxn],P[maxn];
LL dfs1(int u,int pre,LL w){
	for(int i=head[u];i!=-1;i=ed[i].next){
		if(ed[i].e!=pre){
			W[u]+=dfs1(ed[i].e,u,w+ed[i].w);
		}
	}
	return W[u];
}
LL dfs2(int u,int pre,LL p){
	for(int i=head[u];i!=-1;i=ed[i].next){
		if(ed[i].e!=pre){
			P[u]+=dfs2(ed[i].e,u,p+ed[i].p);
		}
	}
	return P[u];
}
LL dp[maxn][2];
LL dfs(int u,int pre){
	for(int i=head[u];i!=-1;i=ed[i].next){
		if(ed[i].e!=pre){
			if(P[u]>=W[u])return W[u];
			dfs(ed[i].e,u);
			dp[u][1]+=max(dp[ed[i].e][0],dp[ed[i].e][1]);
		}
	}
	return max(dp[u][0],dp[u][1]);
}
int main(){
	scanf("%d",&n);
	memset(head,-1,sizeof(head));
	for(int i=0;i<n-1;i++){
		int a,b;
		LL c,d;
		scanf("%d%d%I64d%I64d",&a,&b,&c,&d);
		add(a,b,c,d);
		add(b,a,c,d);
	}
	dfs1(1,-1,0);
	dfs2(1,-1,0);
	cout<<dfs(1,-1)<<endl;
}


