#include<iostream>
#include<string.h>
#include<queue>
#include<cstdio>
using namespace std;
const int maxn=501;
struct {
	int e,next,v;
}ed[maxn*maxn];
int head[maxn],num;
int dis[maxn],n,m,S,T;
void add(int s,int e,int v){
	ed[num].v=v;ed[num].e=e;ed[num].next=head[s];head[s]=num++;
}
int bfs(){
	memset(dis,-1,sizeof(dis));
	queue<int>q;
	dis[S]=0;q.push(S);
	while(!q.empty()){
		int k=q.front();q.pop();
		for(int i=head[k];i!=-1;i=ed[i].next)
			if(dis[ed[i].e]==-1&&ed[i].v>0){
				dis[ed[i].e]=dis[k]+1;
				q.push(ed[i].e);
			}
	}
	return dis[T]>=0;
}
int dfs(int x,int low){
	if(x==T)return low;int k;
	for(int i=head[x];i!=-1;i=ed[i].next){
		if(dis[ed[i].e]==dis[x]+1&&ed[i].v>0&&(k=dfs(ed[i].e,min(ed[i].v,low)))){
			ed[i].v-=k;
			ed[i^1].v+=k;
			return k;
		}
	}
	return 0;
}
int dinic(){
	int ans=0;
	while(bfs())
		ans+=dfs(S,0x3f3f3f3f);//,cout<<ans<<endl;
	return ans;
}
int tmp[8];
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		scanf("%d",&n);S=0,T=450;
		memset(head,-1,sizeof head);num=0;
		int sum=0,maxv=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=7;j++)scanf("%d",&tmp[j]);
			int d,w;
			scanf("%d%d",&d,&w);
			add(S,i,d);add(i,S,0);sum+=d;maxv=max(maxv,w);
			for(int j=1;j<=7;j++){
				if(tmp[j]){
					for(int k=0;k<w;k++){
						add(i,n+k*7+j,1);
						add(n+k*7+j,i,0);
						//add(n+k*7+j,T,1);
						//add(T,n+k*7+j,0);
					}
				}
			}
		}
		for(int i=0;i<maxv;i++){
			for(int j=1;j<=7;j++){
				add(n+i*7+j,T,1);
				add(T,n+i*7+j,0);
			}
		}
		//cout<<dinic()<<endl;
		if(dinic()==sum)printf("Yes\n");
		else printf("No\n");
	}
}


