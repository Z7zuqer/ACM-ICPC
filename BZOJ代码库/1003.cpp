#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+50;
const int inf=0x3f3f3f3f;
int n,m,e,k;
int head[maxn],num;
struct {
	int e,v,next;
}ed[maxn<<1];
int dis[105],dp[105],vis[105],path[105][105];
void add(int s,int e,int v){
	ed[num].e=e;ed[num].v=v;ed[num].next=head[s];head[s]=num++;
	ed[num].e=s;ed[num].v=v;ed[num].next=head[e];head[e]=num++;
}
int spfa(int sta,int end){
	queue<int>q;
	for(int i=0;i<=m;i++)dis[i]=inf;
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	dis[1]=0;
	q.push(1);
	while(!q.empty()){
		int k=q.front();q.pop();vis[k]=0;
		for(int i=head[k];i!=-1;i=ed[i].next){
			if(dis[k]+ed[i].v<dis[ed[i].e]&&path[ed[i].e][end]-path[ed[i].e][sta]==end-sta){
				dis[ed[i].e]=dis[k]+ed[i].v;
				if(!vis[ed[i].e]){
					vis[ed[i].e]=1;
					q.push(ed[i].e);
				}
			}
		}
	}
	if(dis[m]==inf)return inf;
	return dis[m]*(end-sta);
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&e);
	memset(head,-1,sizeof(head));
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int i=0;i<=m;i++)
		for(int j=0;j<=n;j++)
			path[i][j]=1;
	int a,b,c;
	for(int i=0;i<e;i++){
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
	}
	int d;
	scanf("%d",&d);
	for(int i=0;i<d;i++){
		scanf("%d%d%d",&a,&b,&c);
		for(int j=b;j<=c;j++)path[a][j]=0;//0²»ÄÜÓÃ 
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			path[i][j]+=path[i][j-1];
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++){
			int tmp=spfa(j,i);
			if(tmp!=inf)dp[i]=min(dp[i],dp[j]+k+tmp);
		}
	printf("%d\n",dp[n]-k);
}
