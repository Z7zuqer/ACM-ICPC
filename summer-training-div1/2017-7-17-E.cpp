#include<bits/stdc++.h>
using namespace std;
const int maxn=300100;
int n,m;
int sum[maxn],vis[maxn],sta[maxn*10];
int head[maxn],num;
struct node{
	int e,v;
	node *next;
}ed[maxn*10];
node *cnt;
node *adj[maxn]; 
void add(int s,int e,int v){
	node *p=++cnt;
	p->v=v;p->e=e;
	p->next=adj[s];adj[s]=p;
}
void euler(int u){
	vis[u]=1;
	for(node *p=adj[u];p;p=adj[u]){
		if(p->v==1)adj[u]=p->next;
		else --p->v;
		euler(p->e);
	}
	sta[++sta[0]]=u;
}
vector<int>ans;
int main(){
	//freopen("input.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		ans.clear();
		for(int i=0;i<=n;i++)sum[i]=vis[i]=0,head[i]=-1;
		memset(adj,0,sizeof adj);
		cnt=&ed[0];
		num=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			sum[a]-=c;
			sum[b]+=c;
			add(a,b,c);
		}
		for(int i=1;i<=n;i++)
			if(sum[i]>0)add(i,0,sum[i]);
			else if(sum[i]<0)add(0,i,-sum[i]);
		for(int i=0;i<=n;i++){
			if(vis[i])continue;
			sta[0]=0;
			euler(i);
			if(sta[0]==1)continue;
			for(int j=sta[0];j;--j)	
				if(sta[j])ans.push_back(sta[j]);
		}
		printf("%d\n",ans.size()-1);
		for(int i=0;i<ans.size()-1;i++)printf("%d ",ans[i]);printf("\n");
	}
} 
