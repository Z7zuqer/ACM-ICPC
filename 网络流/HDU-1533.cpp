#include<bits/stdc++.h>
using namespace std;
struct MCMFMINE{
	const static int MAXP=210;
	const static int MAXE=10000*4;
	const static int MINF=1e8;
	struct EDGE{
		int from,to,cap,flow,cost,next;
	}ed[MAXE];
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
}mcmf; 
char s[410][410];
int n,mm;
struct {
	int x,y;
}m[110],h[110];
int main(){
	while(scanf("%d%d",&n,&mm)!=EOF){
		if(!n)break;
		int cntm=0,cnth=0;
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]+1);
			for(int j=1;j<=mm;j++){
				if(s[i][j]=='m')m[++cntm]={i,j};
				if(s[i][j]=='H')h[++cnth]={i,j};
			}
		}
		mcmf.init(0,cntm+cnth+1);
		for(int i=1;i<=cntm;i++)
			for(int j=1;j<=cnth;j++)
				mcmf.add(i,j+cntm,1,abs(m[i].x-h[j].x)+abs(m[i].y-h[j].y));
		for(int i=1;i<=cntm;i++)mcmf.add(0,i,1,0);
		for(int i=1;i<=cnth;i++)mcmf.add(i+cntm,cntm+cnth+1,1,0);
		int ansflow,anscost;
		mcmf.MCMF(anscost,ansflow);
		printf("%d\n",anscost);
	}
}


