#include<iostream>
#include<string.h>
#include<queue>
#include<cstdio>
using namespace std;
const int maxn=350;
struct {
	int e,next,v;
}ed[maxn*maxn];
int head[maxn],num,dis[maxn],S=0,T,m;
void add(int s,int e,int v){
	ed[num].e=e;ed[num].v=v;ed[num].next=head[s];head[s]=num++;
}
int bfs(){
	queue<int>q;q.push(S);
	memset(dis,-1,sizeof dis);dis[S]=0;
	while(!q.empty()){
		int k=q.front();q.pop();
		for(int i=head[k];i!=-1;i=ed[i].next){
			if(dis[ed[i].e]==-1&&ed[i].v>0){
				dis[ed[i].e]=dis[k]+1;
				q.push(ed[i].e);
			}
		}
	}
	return dis[T]>=0;
}
int dfs(int u,int low){
	if(u==T)return low;int k;
	for(int i=head[u];i!=-1;i=ed[i].next){
		if(dis[ed[i].e]==dis[u]+1&&ed[i].v>0&&(k=dfs(ed[i].e,min(low,ed[i].v)))){
			ed[i].v-=k;
			ed[i^1].v+=k;
			return k;
		}
	}
	return 0;
}
int dinic(){
	int ans=0,cur=0;
	while(bfs())
		while(cur=dfs(S,0x3f3f3f3f))
			ans+=cur;
	return ans; 
}
int d[maxn][maxn],k,c;
int work(int r){
	memset(head,-1,sizeof head);num=0;
	for(int i=1;i<=k;i++){
		add(i,S,0);
		add(S,i,m);
	}
	for(int i=k+1;i<=k+c;i++){
		add(T,i,0);
		add(i,T,1);
	}
	for(int i=1;i<=k;i++)
		for(int j=k+1;j<=k+c;j++)
			if(d[i][j]<=r){
				add(i,j,1);
				add(j,i,0);
			}
	return dinic()==c;
}
int main(){
	scanf("%d%d%d",&k,&c,&m);T=k+c+5;
	memset(head,-1,sizeof head);
	memset(d,0x3f,sizeof d);
	for(int i=1;i<=k+c;i++)d[i][i]=0; 
	for(int i=1;i<=k+c;i++)
		for(int j=1;j<=k+c;j++){
			scanf("%d",&d[i][j]);
			if(!d[i][j])d[i][j]=0x3f3f3f3f;
		}
	for(int u=1;u<=k+c;u++)
		for(int i=1;i<=k+c;i++)
			for(int j=1;j<=k+c;j++)
				d[i][j]=min(d[i][u]+d[u][j],d[i][j]);
	int l=0,r=40000;
	while(l<r){
		int mid=(l+r)>>1;
		if(work(mid))r=mid;
		else l=mid+1;
	}		
	printf("%d\n",r);
}


