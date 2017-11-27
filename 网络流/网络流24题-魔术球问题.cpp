#include<bits/stdc++.h>
using namespace std;
struct MAXF{
	const static int MAXN=40000;
	const static int MAXE=3000000;
	const static int MINF=0x3f3f3f3f;
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
int work(int k){
	maxf.init(0,k*2+1);
	for(int i=1;i<=k;i++)
		for(int j=i+1;j<=k;j++){
			int tmp=sqrt(i+j);
			if(tmp*tmp==i+j)
				maxf.add(i,j+k,1);//,cout<<i<<" "<<j<<endl;	
		}
	for(int i=1;i<=k;i++){
		maxf.add(0,i,1);
		maxf.add(i+k,k*2+1,1);
	}
	return k-maxf.dinic();
}
int vis[1607],nextn[1607];
void dfs(int now){
	printf("%d ",now);
	vis[now]=1;
	if(nextn[now]==-1)return ;
	dfs(nextn[now]);
}
int main(){
	int n;
	scanf("%d",&n);
	int l=0,r=1600,ans;
	while(l<=r){
		int mid=(l+r)>>1;
		if(work(mid)<=n)l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%d\n",ans);
	work(ans);
	memset(nextn,-1,sizeof nextn);
	for(int i=1;i<=ans;i++){
		for(int j=maxf.head[i];j!=-1;j=maxf.ed[j].next){
			if(j%2==0&&maxf.ed[j].v==0){
				int s=maxf.ed[j].e-ans,e=i;
				nextn[e]=s;
				//cout<<e<<" "<<s<<endl;
			}
		}
	}
	//while(1);
	for(int i=1;i<=ans;i++){
		if(vis[i])continue;
		dfs(i);
		printf("\n");
	}
}


