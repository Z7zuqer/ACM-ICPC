#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=1e5+107;
const int mod=1e9+7;
int dfs_num,col[maxn],size[maxn],minm[maxn],minsiz[maxn];
int dfn[maxn],low[maxn],insta[maxn],sta[maxn],top,col_num;
int A[maxn],vis[maxn];
vector<int>v[maxn];
void tarjan(int u){
	dfn[u]=++dfs_num;
	low[u]=dfs_num;
	insta[u]=1;
	vis[u]=1;
	sta[++top]=u;
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i];
		if(!dfn[e]){
			tarjan(e);
			low[u]=min(low[u],low[e]);
		}
		else if(insta[e])low[u]=min(low[u],dfn[e]);
	} 
	if(dfn[u]==low[u]){
		insta[u]=0;
		col[u]=++col_num;
		minsiz[col_num]=1;
		minm[col_num]=A[u];
		while(sta[top]!=u){
			col[sta[top]]=col_num;
			if(A[sta[top]]<minm[col_num]){
				minm[col_num]=A[sta[top]];
				minsiz[col_num]=1;
			}
			else if(A[sta[top]]==minm[col_num])minsiz[col_num]++;
			insta[sta[top--]]=0;
		}
		top--;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
			tarjan(i);
	LL ans1=0,ans2=1;
	for(int i=1;i<=col_num;i++)
		ans1=(ans1+minm[i]);
	for(int i=1;i<=col_num;i++)
		ans2=(ans2*minsiz[i])%mod;
	cout<<ans1<<" "<<ans2<<endl;
}


