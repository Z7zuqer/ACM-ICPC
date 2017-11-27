#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
struct node{
	int s,e,next;
}ed[6*maxn],edge2[6*maxn];
int n,m,dfs_num,e_num2,tar_num,cnt;
int head[maxn],insta[maxn],low[maxn],dfn[maxn],col[maxn],req[maxn];
void add(int a,int b,node edge[],int &e_num){
	edge[e_num].s=a; edge[e_num].e=b; edge[e_num].next=head[a]; head[a]=e_num++;
}
stack<int>st;
void tarjan(int u){
	dfn[u]=low[u]=++tar_num;
	insta[u]=1;
	st.push(u);
	for(int j=head[u];j!=-1;j=ed[j].next){
		int e=ed[j].e;
		if(dfn[e]==-1){
			tarjan(e);
			low[u]=min(low[u],low[e]);
		}
		else if(insta[e] && low[u]>dfn[e])low[u]=dfn[e];
	}
	if(low[u]==dfn[u]){
		cnt++;
		int tmp;
		do{
			tmp=st.top();
			st.pop();
			insta[tmp]=0;
			col[tmp]=cnt;
		}while(tmp!=u);
	}
}

int topo(){
	int res=0,cur=-1;
	for(int i=1;i<=cnt;i++){
		if(req[i]==0){
			cur=i;res++;
		}
	}
	if(res>1)return 0;
	int num=cnt;
	while(num--){
		res=0;
		for(int i=head[cur];i!=-1;i=edge2[i].next){
			int u=edge2[i].e;
			req[u]--;
			if(req[u]==0){
				res++;cur=u;
			}
		}
		if(res>1)return 0;
	}
	return 1;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		dfs_num=0;
		memset(head,-1,sizeof(head));
		for(int i=1;i<=m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b,ed,dfs_num);
		}
		cnt=tar_num=0;
		memset(insta,0,sizeof(insta));
		memset(low,0,sizeof(low));
		memset(dfn,-1,sizeof(dfn));
		for(int i=1;i<=n;i++){
			if(dfn[i]==-1)tarjan(i);
		}
		e_num2=0;
		memset(head,-1,sizeof(head));
		memset(req,0,sizeof(req));
		for(int i=0;i<dfs_num;i++){
			int j=ed[i].s,k=ed[i].e;
			if(col[j]!=col[k]){
				add(col[j],col[k],edge2,e_num2);
				req[col[k]]++;
			}
		}
		int flg=topo();
		if(!flg)puts("Light my fire!");
		else puts("I love you my love and our love save us!");
	}
}

