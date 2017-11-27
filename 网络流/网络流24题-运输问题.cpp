#include<bits/stdc++.h>
using namespace std;
struct MCMFMINE{
	const static int MAXP=500;
	const static int MAXE=1000000;
	const static int MINF=1e8;
	struct EDGE{
		int from,to,cap,flow,cost,next;
	}ed[MAXE<<1];
	int S,T,head[MAXP],num,pre[MAXP],vis[MAXP],dis[MAXP];
	void init(int S,int T){
		memset(head,-1,sizeof head);
		num=0;
		this->S=S;this->T=T;
	}
	void add(int u,int v,int w,int c){
		ed[num]={u,v,w,0,c,head[u]};head[u]=num++;
		ed[num]={v,u,0,0,-c,head[v]};head[v]=num++;
	}
	bool spfa(){
		queue<int>q;
		for(int i=S;i<=T;i++)dis[i]=MINF,vis[i]=0,pre[i]=-1;
		dis[S]=0,vis[S]=1;q.push(S);
		while(!q.empty()){
			int u=q.front();q.pop();vis[u]=0;
			for(int i=head[u];i!=-1;i=ed[i].next){
				EDGE E=ed[i];
				if(dis[E.to]>dis[u]+E.cost&&E.cap>E.flow){
					dis[E.to]=dis[u]+E.cost;
					pre[E.to]=i;
					if(!vis[E.to]){
						vis[E.to]=1;
						q.push(E.to);
					}
				}
			}
		}
		return pre[T]!=-1;
	}
	void MCMF(int &cost,int &flow){
		flow=cost=0;
		while(spfa()){
			int minv=MINF;
			for(int i=pre[T];i!=-1;i=pre[ed[i^1].to])minv=min(minv,ed[i].cap-ed[i].flow);
			for(int i=pre[T];i!=-1;i=pre[ed[i^1].to]){
				ed[i].flow+=minv;
				ed[i^1].flow-=minv;
				cost+=ed[i].cost*minv;
			}
			flow+=minv;
		}
	}
}mcmf,mcmf2; 
int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	mcmf.init(0,n+m+1);
	mcmf2.init(0,n+m+1);
	for(int i=1;i<=m;i++){
		int x;
		scanf("%d",&x);
		mcmf.add(0,i,x,0);
		mcmf2.add(0,i,x,0);
	}
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		mcmf.add(i+m,n+m+1,x,0);
		mcmf2.add(i+m,n+m+1,x,0);
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++){
			int x;
			scanf("%d",&x);
			mcmf.add(i,j+m,1e8,x);
			mcmf2.add(i,j+m,1e8,-x);
		}
	int ans1,ans2,flow;
	mcmf.MCMF(ans1,flow);
	mcmf2.MCMF(ans2,flow);
	printf("%d\n%d\n",ans1,-ans2);
}


