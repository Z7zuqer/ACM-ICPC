#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int vis[maxn],flg[maxn*20],dis[maxn],ans,mx,mi;
int head[maxn],num;
struct {
	int e,v,next;
}ed[maxn*20];
void add(int s,int e,int v){
	ed[num].e=e;ed[num].next=head[s];ed[num].v=v;head[s]=num++;
}
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
void dfs1(int u){
	vis[u]=1;
	for(int i=head[u];i!=-1;i=ed[i].next){
		if(!vis[ed[i].e]){
			dis[ed[i].e]=dis[u]+ed[i].v;
			dfs1(ed[i].e);
		}
		else ans=gcd(ans,abs(dis[u]+ed[i].v-dis[ed[i].e]));
	}
}
void dfs2(int u){
	mx=max(mx,dis[u]);
	mi=min(mi,dis[u]);
	vis[u]=1;
	for(int i=head[u];i!=-1;i=ed[i].next){
		if(!flg[i]){
			flg[i]=flg[i^1]=1;
			dis[ed[i].e]=dis[u]+ed[i].v;
			dfs2(ed[i].e);
		}
	}
}
int main(){
	//cout<<gcd(10,20)<<endl;
	//cout<<(0^1)<<" "<<(2^1)<<" "<<(3^1)<<" "<<(4^1)<<endl;
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		add(a,b,1);add(b,a,-1);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs1(i);
	if(ans){
		if(ans<3){
			cout<<"-1 -1"<<endl;
			return 0;
		}
		for(int i=3;i<=ans;i++)
			if(ans%i==0){
				cout<<ans<<" "<<i<<endl;
				return 0;
			}
	}
	memset(vis,0,sizeof(vis));
	memset(dis,0,sizeof(dis));
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			mx=mi=dis[i]=0;
			dfs2(i);
			ans+=mx-mi+1;
		}
	}
	if(ans>=3){
		cout<<ans<<" "<<3<<endl;
	}
	else cout<<"-1 -1"<<endl;
} 
