#include<iostream>
#include<string.h>
#include<queue>
#include<cstdio>
using namespace std;
const int maxn=150;
struct {
	int e,next,v;
}ed[200010];
int head[maxn],num,dis[maxn],S=1,T,n,cur[maxn];
void add(int s,int e,int v){
	ed[num].e=e;ed[num].v=v;ed[num].next=head[s];head[s]=num++;
}
int bfs(){
	queue<int>q;q.push(S);
	for(int i=S;i<=T;i++)dis[i]=-1;dis[S]=0;
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
	if(u==T||low==0)return low;int k,flow=0;
	for(int &i=cur[u];i!=-1;i=ed[i].next){
		int e=ed[i].e;
		if(dis[e]==dis[u]+1&&ed[i].v>0&&(k=dfs(e,min(low,ed[i].v)))>0){
			ed[i].v-=k;ed[i^1].v+=k;
			flow+=k;low-=k;
			if(low==0)break;
		}
	}
	return flow;
}
int dinic(){
	int ans=0,cur_flow=0;
	while(bfs()){
		for(int i=S;i<=T;i++)cur[i]=head[i];
		while(cur_flow=dfs(S,1e8+1))ans+=cur_flow;
	}
	return ans; 
}
int num[1010];
int main(){
	int m;
	//while(~scanf("%d%d%d",&n,&p,&t)){
		scanf("%d%d",&m,&n);
		S=0;T=n+1;
		for(int i=1;i<=m;i++)scanf("%d",&num[i]);
		int kk;
		while(l<r){
			int mid=(l+r)>>1;
			if(work(mid)>=t)r=mid;
			else l=mid+1;
		}
		printf("%d\n",r); 
	//}
} 
