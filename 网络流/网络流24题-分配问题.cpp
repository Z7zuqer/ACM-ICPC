#include<bits/stdc++.h>
using namespace std;
struct MCMFMINE{
	const static int MAXP=210;
	const static int MAXE=100000;
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
	void maxc(int &cost,int &flow){
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
	int n;
	scanf("%d",&n);
	mcmf.init(0,n*2+1);
	mcmf2.init(0,n*2+1);
	for(int i=1;i<=n;i++)mcmf.add(0,i,1,0),mcmf.add(i+n,n*2+1,1,0);
	for(int i=1;i<=n;i++)mcmf2.add(0,i,1,0),mcmf2.add(i+n,n*2+1,1,0);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			int x;
			scanf("%d",&x);
			mcmf.add(i,j+n,1,x);
			mcmf2.add(i,j+n,1,-x);
		}
	int mincost,ansflow;
	int maxcost;
	mcmf.maxc(mincost,ansflow);
	mcmf2.maxc(maxcost,ansflow);
	printf("%d\n%d\n",mincost,-maxcost);
}


