#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
struct {
	int e,next;
}ed[maxn<<1];
int head[maxn],num;
int rt,rt2,edge,vis[maxn];
long long dp[maxn][2],seq[maxn];
void add(int s,int e){
	ed[num].e=e;ed[num].next=head[s];head[s]=num++;
} 
void dfs(int u,int pre){
	vis[u]=1;
	for(int i=head[u];i!=-1;i=ed[i].next){
		if(ed[i].e==pre)continue;
		if(!vis[ed[i].e])dfs(ed[i].e,u);
		else {
			rt=u;rt2=ed[i].e;edge=i;
		}
	}
}
void trdp(int u,int pre){
	dp[u][1]=seq[u];dp[u][0]=0;
	for(int i=head[u];i!=-1;i=ed[i].next){
		if(ed[i].e==pre||i==edge||i==(edge^1))continue;
		trdp(ed[i].e,u);
		dp[u][0]+=max(dp[ed[i].e][1],dp[ed[i].e][0]);
		dp[u][1]+=dp[ed[i].e][0];
	}
}
long long maxx(long long a,long long b){
	if(a>b)return a;
	return b;
}
long long work(int u){
	dfs(u,-1);
	trdp(rt,-1);
	long long ans=dp[rt][0];
	trdp(rt2,-1);
	ans=maxx(ans,dp[rt2][0]);
	return ans;
}
int main(){
	int n,a;
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&seq[i],&a);
		add(i,a);add(a,i);
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(!vis[i])ans+=work(i);
	}
	cout<<ans<<endl;
}

