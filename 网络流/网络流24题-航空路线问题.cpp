#include<bits/stdc++.h>
using namespace std;
struct MCMFMINE{
	const static int MAXP=500;
	const static int MAXE=2000000;
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
}mcmf; 
map<string,int>mp;
map<int,string>mpp;
int vis[1010],n;
void dfs(int now,int flg){
	//cout<<now<<endl;
	vis[now]=1;
	//cout<<flg<<" "<<now<<endl;
	if(flg)cout<<mpp[now]<<endl;
	if(now==n)return ;
	for(int i=mcmf.head[now];i!=-1;i=mcmf.ed[i].next){
		if(i%2==0&&0!=mcmf.ed[i].flow&&!vis[mcmf.ed[i].to]){
			//cout<<mcmf.ed[i].to<<endl;
			//if(flg)dfs(mcmf.ed[i].to-n,flg^1);
			dfs(mcmf.ed[i].to,flg^1);
			break;
		}
	}
}
void dfs2(int now,int flg){
	vis[now]=1;
	int fflg=0,rt;
	for(int i=mcmf.head[now];i!=-1;i=mcmf.ed[i].next){
		if(i%2==0&&mcmf.ed[i].flow!=0&&!vis[mcmf.ed[i].to]){
			//if(flg)dfs2(mcmf.ed[i].to-n,flg^1);
			if(mcmf.ed[i].to!=n&&mcmf.ed[i].to!=n+n)dfs2(mcmf.ed[i].to,flg^1),fflg=-1;
			else if(fflg!=-1)fflg=mcmf.ed[i].to,rt=i;
			break;
		}
	}
	if(fflg>0)dfs2(mcmf.ed[rt].to,flg^1);
	if(flg&&now!=n&&now!=n*2)cout<<mpp[now]<<endl;
}
int main(){
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		string a;
		cin>>a;
		mp[a]=i;
		mpp[i]=a;
	}
	mcmf.init(1,n*2);
	for(int i=2;i<n;i++)mcmf.add(i,i+n,1,-1);
	mcmf.add(1,1+n,2,-1);
	mcmf.add(n,n+n,2,-1);
	for(int i=1;i<=m;i++){
		string a,b;
		cin>>a>>b;
		int s=mp[a],e=mp[b];
		if(s>e)swap(s,e);
		if(s==1&&e==n)mcmf.add(s+n,e,2,0);
		else mcmf.add(s+n,e,1,0);
	}
	int anscost,ansflow;
	mcmf.MCMF(anscost,ansflow);
	if(ansflow!=2)return 0*printf("No Solution!");
	printf("%d\n",-anscost-2);
	dfs(1,1);
	vis[1]=vis[1+n]=vis[n]=vis[n+n]=0;
	dfs2(1,1); 
}


