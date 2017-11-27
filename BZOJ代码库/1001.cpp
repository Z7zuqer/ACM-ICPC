#include<bits/stdc++.h>
using namespace std;
const int maxn=2000050;
int head[maxn],num=0,dis[maxn],vis[maxn];
struct {
	int e,v,next;
}ed[6000000];
void add(int s,int e,int v){
	ed[num].e=e;ed[num].v=v;ed[num].next=head[s];head[s]=num++;
	ed[num].e=s;ed[num].v=v;ed[num].next=head[e];head[e]=num++;
}
void spfa(int sta){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[sta]=0;
	vis[sta]=1;
	queue<int>q;
	q.push(sta);
	while(!q.empty()){
		int k=q.front();q.pop();vis[k]=0;
		for(int i=head[k];i!=-1;i=ed[i].next){
			if(dis[k]+ed[i].v<dis[ed[i].e]){
				dis[ed[i].e]=dis[k]+ed[i].v;
				if(!vis[ed[i].e]){
					vis[ed[i].e]=1;
					q.push(ed[i].e);
				}
			}
		}
	}
} 
int n,m;
int main(){
	while(~scanf("%d%d",&n,&m)){
		if(n==1||m==1){
			if(n>m)swap(n,m);
			int ans=0x3f3f3f3f;
			for(int i=1;i<m;i++){
				int a;
				scanf("%d",&a);
				if(a<ans)ans=a;
			}
			printf("%d\n",ans);
			return 0;
		}
		memset(head,-1,sizeof(head));
		num=0;
		int sta=0,end=(n-1)*(m-1)*2+1;
		int a,b,c;
		for(int i=0;i<n;i++)
			for(int j=1;j<m;j++){
				scanf("%d",&c);
				if(i==0)add(sta,j*2-1,c);
				else if(i==n-1)add((i-1)*(m-1)*2+j*2,end,c);
				else add((i-1)*(m-1)*2+(j)*2,(i)*(m-1)*2+j*2-1,c);
			} 
		for(int i=0;i<n-1;i++)
			for(int j=1;j<=m;j++){
				scanf("%d",&c);
				if(j==m)add(sta,(i+1)*(m-1)*2-1,c);
				else if(j==1)add(j+(i)*(m-1)*2+j,end,c);
				else add((i)*(m-1)*2+2*j-3,(j*2)+(i)*(m-1)*2,c);
			}
		for(int i=1;i<n;i++)
			for(int j=1;j<m;j++){
				scanf("%d",&c);
				add((i-1)*(m-1)*2+(j-1)*2+1,(i-1)*(m-1)*2+(j)*2,c);
			}
		spfa(sta);
		printf("%d\n",dis[end]);
	}
}
