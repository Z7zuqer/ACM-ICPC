#include<bits/stdc++.h>
using namespace std;
struct MAXF{
	const static int MAXN=50000;
	const static int MAXE=1000000;
	const static int MINF=1e8;
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
		ed[num].e=s;ed[num].v=0;ed[num].next=head[e];head[e]=num++;
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
			while(cur_flow=dfs(S,MINF))ans+=cur_flow;
		}
		return ans; 
	}
}maxf; 
int n,m,A[210][210];
int dy[8]={-1,-2,-2,-1,1,2,2,1};
int dx[8]={-2,-1,1,2,2,1,-1,-2};
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		A[a][b]=1;
	}
	maxf.init(0,n*n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(A[i][j])continue;
			if((i+j)&1)maxf.add((i-1)*n+j,n*n+1,1);
			else maxf.add(0,(i-1)*n+j,1);
			if((i+j)%2==1)continue;
			for(int k=0;k<8;k++){
				int tx=i+dx[k];
				int ty=j+dy[k];
				if(tx>=1&&ty>=1&&tx<=n&&ty<=n&&!A[tx][ty])
					maxf.add((i-1)*n+j,(tx-1)*n+ty,1e8);
			}
		}
	}
	int ans=n*n-m-maxf.dinic();
	printf("%d\n",ans);
}


