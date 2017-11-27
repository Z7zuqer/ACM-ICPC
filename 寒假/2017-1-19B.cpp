#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
struct {
	int e,v,next,sig;
}ed[maxn<<1];
int head[maxn],num;
int dis[maxn],vis[maxn];
void add(int s,int e,int v,int sig){
	ed[num].sig=sig;ed[num].v=v;ed[num].e=e;ed[num].next=head[s];head[s]=num++;
}
int n,m;
struct node{
	int e,v;
	bool operator<(const node &A)const{
		return v>A.v;
	}
};
priority_queue<node>q;
struct nodee{
	int s,e,v;
	int lst,sig;
}ed_ans[maxn<<1];
int cmp(nodee m,nodee n){
	if(m.lst==n.lst)return m.s<n.s;
	return m.lst<n.lst;
}
void dij(int u){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[u]=0;
	int cnt=1;
	q.push({1,0}); 
	while(!q.empty()){
		int k=q.top().e,v=q.top().v;q.pop();
		if(vis[k])continue;
		vis[k]=1;
		for(int i=head[k];i!=-1;i=ed[i].next){
			if(!vis[ed[i].e]&&dis[k]+ed[i].v<dis[ed[i].e]){
				ed_ans[ed[i].sig].lst=cnt++;;
				dis[ed[i].e]=dis[k]+ed[i].v;
				q.push({ed[i].e,dis[ed[i].e]});
			}
		}
	}
}
int main(){
	freopen("algoritm.in","r",stdin);
	freopen("algoritm.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		memset(head,-1,sizeof(head));
		num=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			add(a,b,c,i);
			ed_ans[i].s=a;
			ed_ans[i].e=b;
			ed_ans[i].v=c;
			ed_ans[i].sig=i;
			ed_ans[i].lst=772002;
		}
		dij(1);
		sort(ed_ans,ed_ans+m,cmp);
		for(int i=0;i<m;i++)
			if(i!=m-1)printf("%d ",ed_ans[i].sig+1);
			else printf("%d\n",ed_ans[i].sig+1);
	}
}


