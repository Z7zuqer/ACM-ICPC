#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int n,k,s;
struct {
	int e,next;
}ed[maxn<<1];
int head[maxn],num;
int dep[maxn],vis[maxn],maxm,wh[maxn],fa[maxn];
int ds[maxn];
vector<int>v[maxn];
void add(int s,int e){
	ed[num].e=e;ed[num].next=head[s];head[s]=num++;
}
void dfs(int u,int pre,int siz){
	vis[u]=1;dep[u]=siz;fa[u]=pre;
	if(ds[u]==2)v[siz].push_back(u);
	maxm=max(maxm,siz);
	for(int i=head[u];i!=-1;i=ed[i].next){
		if(!vis[ed[i].e]&&pre!=ed[i].e){
			dfs(ed[i].e,u,siz+1);
		}
	}
}
void dfs2(int u,int pre,int siz){
	if(siz>k)return ;
	wh[u]=1;
	for(int i=head[u];i!=-1;i=ed[i].next){
		if(ed[i].e!=pre)dfs2(ed[i].e,u,siz+1);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		maxm=num=0;
		for(int i=0;i<maxn;i++)v[i].clear();
		memset(head,-1,sizeof(head));
		memset(vis,0,sizeof(vis));
		memset(ds,0,sizeof(ds));
		memset(wh,0,sizeof(wh));
		memset(fa,-1,sizeof(fa));
		scanf("%d%d%d",&n,&s,&k);
		for(int i=1;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);add(b,a);
			ds[a]+=2;
			ds[b]+=2;
		}	
		dfs(s,-1,0);
		int ans=0;
	//	cout<<maxm<<endl;
		for(int i=n-1;i>k;i--){
			for(int j=0;j<v[i].size();j++){
				int u=v[i][j];//cout<<u<<endl;
				if(wh[u])continue;
				for(int t=0;t<k;t++)u=fa[u];
				//cout<<u<<endl;
				dfs2(u,-1,0);
				ans++;
				//cout<<ans<<endl;
			}
		}
		cout<<ans<<endl;
	}
}
