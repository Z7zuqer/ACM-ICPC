#include<bits/stdc++.h>
using namespace std;
struct MAXF{
	const static int MAXN=200+3;
	const static int MAXE=10000+7;
	int head[MAXN],num,dis[MAXN],S,T,cur[MAXN];
	struct {
		int e,next,v;
	}ed[MAXE<<1];
	void init(int S,int T){
		memset(head,-1,sizeof head);
		num=0;
		this->S=S;
		this->T=T;
	}
	void add(int s,int e,int v){
		ed[num].e=e;ed[num].v=v;ed[num].next=head[s];head[s]=num++;
		ed[num].e=s;ed[num].v=v;ed[num].next=head[e];head[e]=num++;
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
}maxf; 
struct {
	int x,y;
}E[10010];
int main(){
	int n,m,k;
	while(scanf("%d%d%d",&n,&m,&k)==3){
		maxf.init(0,n+m+1);
		for(int i=1;i<=n;i++)maxf.add(0,i,1);
		for(int i=1;i<=m;i++)maxf.add(i+n,n+m+1,1);
		for(int i=1;i<=k;i++){
			scanf("%d%d",&E[i].x,&E[i].y);
			maxf.add(E[i].x,E[i].y+n,10000);
		}
		int ans=maxf.dinic();
		cout<<ans<<endl;
	}
}


