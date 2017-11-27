#include<bits/stdc++.h>
using namespace std;
const int maxn=3010;
int n,m;
vector<pair<int,int> >v[maxn];
int dfn[maxn],low[maxn],Stack[maxn],top,tot;
int taj;
vector<int>rem[maxn];
int belong[maxn],vis[maxn],size[maxn];
void tarjan(int u,int fa){
	dfn[u]=low[u]=++tot;
	Stack[top++]=u;
	vis[u]=1;
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i].first;
		if(dfn[e]==-1){
			tarjan(e,u);
			low[u]=min(low[u],low[e]);
		}
		else if(vis[e])low[u]=min(low[u],dfn[e]);
	}
	if(low[u]==dfn[u]){
		int now;
		taj++;//size[taj]=top;
		do{
			now=Stack[--top];
			vis[now]=0;
			size[taj]++;
			belong[now]=taj;
			rem[taj].push_back(now);
		}while(now!=u);
	}
} 
struct node{
	int s,e,idx;
};
vector<node>edd;
void work(int k){
	for(int i=0;i<v[k].size();i++){
		int e=v[k][i].first,idx=v[k][i].second;
		if(belong[e]!=belong[k])
			edd.push_back({belong[k],belong[e],idx});
	}
}
int head[maxn],num;
struct {
	int e,next;
}ed[maxn*10];
void add(int s,int e){
	ed[num].e=e;ed[num].next=head[s];head[s]=num++;
}
int count=0,belong_now[maxn];
int size_now[maxn],taj_now;
void tarjan_now(int u,int fa){
	dfn[u]=low[u]=++tot;
	Stack[top++]=u;
	vis[u]=1;
	for(int i=head[u];i!=-1;i=ed[i].next){
		int e=ed[i].e;
		if(dfn[e]==-1){
			tarjan_now(e,u);
			low[u]=min(low[u],low[e]);
		}
		else if(vis[e])low[u]=min(low[u],dfn[e]);
	}
	if(low[u]==dfn[u]){
		int now;
		taj_now++;
		do{
			now=Stack[--top];
			vis[now]=0;
			belong_now[now]=taj_now;
			size_now[taj_now]+=size[now]; 
		}while(now!=u);
	}
}
vector<int>tmp;
vector<int>ans;
vector<int>q;
int main(){
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==0){
		cout<<1<<endl;
		cout<<0<<endl;
		return 0;
	}
	//mesmet(head,-1,sizeof head);
	memset(dfn,-1,sizeof dfn);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back({b,i});
	}
	for(int i=1;i<=n;i++)
		if(dfn[i]==-1)
			tarjan(i,-1);
	int maxm=0;
	for(int i=1;i<=n;i++)work(i);
	//cout<<edd.size()<<endl;
	//for(int i=1;i<=taj;i++)cout<<belong[i]<<" ";cout<<endl;
	//cout<<edd.size()<<endl;
	
	/*
	6 6
	1 2 2 3 3 1
	4 5 5 6 6 4
	*/
	if(edd.size()==0){
		int mx=0;
		for(int i=1;i<=taj;i++){
			if(mx<size[i]){
				mx=size[i];
				tmp.push_back(i);
			}
			else if(mx==size[i])tmp.push_back(i);
		}
		printf("%d\n",mx);
		int ans=0;
		for(int k=0;k<tmp.size();k++)
			for(int i=0;i<rem[tmp[k]].size();i++){
				int u=rem[tmp[k]][i];//cout<<u<<endl;
				for(int j=0;j<v[u].size();j++)
					q.push_back(v[u][j].second);
			}
		printf("%d\n",q.size());
		for(int i=0;i<q.size();i++)printf("%d ",q[i]);
		return 0;
	}
	for(int i=0;i<edd.size();i++){
		for(int j=1;j<=taj;j++)head[j]=-1,dfn[j]=-1,size_now[j]=low[j]=belong_now[j]=vis[j]=0;tot=num=0;
		top=0;taj_now=0;
		for(int j=0;j<edd.size();j++)
			if(j==i)add(edd[i].e,edd[j].s),add(edd[i].s,edd[i].e);
			else add(edd[j].s,edd[j].e);
		for(int j=1;j<=taj;j++)
			if(dfn[j]==-1)
				tarjan_now(j,-1);
		int mx=0;
		//cout<<taj_now<<endl;
		for(int j=1;j<=taj_now;j++)mx=max(mx,size_now[j]);
		//for(int j=1;j<=taj_now;j++)cout<<size_now[j]<<" ";cout<<endl;
		if(mx>maxm){
			maxm=mx;
			//cout<<edd[i].s<<" "<<edd[i].e<<endl;
			ans.clear();
			ans.push_back(edd[i].idx); 
		}
		else if(mx==maxm)ans.push_back(edd[i].idx);
	}
	printf("%d\n%d\n",maxm,ans.size());
	for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);
}


