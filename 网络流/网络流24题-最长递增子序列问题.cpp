#include<bits/stdc++.h>
using namespace std;
struct MAXF{
	const static int MAXN=2500+107;
	const static int MAXE=3000000;
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
}maxf,maxf2; 
int n,A[5100],dp[5010],B[5100],len;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	for(int i=1;i<=n;i++){
		int pos=upper_bound(B+1,B+1+len,A[i])-B;
		if(pos==len+1)len++;
		B[pos]=A[i];
		dp[i]=pos;
		//cout<<i<<" "<<pos<<" "<<len<<endl;
	}
	printf("%d\n",len);
	maxf.init(0,n*2+1);
	maxf2.init(0,n*2+1);
	for(int i=1;i<=n;i++){
		maxf.add(i,i+n,1);
		if(i==1||i==n){
			maxf2.add(i,i+n,1e8);
			if(dp[i]==1)maxf2.add(i+n,n*2+1,1e8);
			if(dp[i]==len)maxf2.add(0,i,1e8);
		}
		else {
			maxf2.add(i,i+n,1);
			if(dp[i]==1)maxf2.add(i+n,n*2+1,1);
			if(dp[i]==len)maxf2.add(0,i,1);
		}
		
		if(dp[i]==len)maxf.add(0,i,1);
		if(dp[i]==1)maxf.add(i+n,n*2+1,1);
		
		for(int j=1;j<i;j++){
			if(A[j]<=A[i]&&dp[j]+1==dp[i]){
				maxf.add(i+n,j,1);
				maxf2.add(i+n,j,1);
			}
		}
	}
	int ans=maxf.dinic();
	if(len==1)return 0*printf("%d\n%d\n",n,n);
	printf("%d\n",ans);
	printf("%d\n",maxf2.dinic());
	//else printf("%d\n",n);
}


