#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=170;
int n,p;
int dp[maxn][maxn],deg[maxn],son[maxn],size[maxn];
vector<int>v[maxn];
void DP1(int u,int fa){
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i];
		if(e==fa)continue;
		DP1(e,u);
		size[u]+=size[e];
	}
}
void DP2(int u,int fa){
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i];
		if(e==fa)continue;
		DP2(e,u);
		int r1=min(p,size[u]),r2=min(p,size[e]);
		for(int j=r1;j>=1;j--)
			for(int k=1;k<=min(r2,j-1);k++)
				dp[u][j]=min(dp[u][j],dp[u][j-k]+dp[e][k]);
	}
}
int main(){
	scanf("%d%d",&n,&p);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		deg[b]++;
		son[a]++;
	}
	int rt=-1;
	//for(int i=1;i<=n;i++)dp[i][1]=son[i];
	for(int i=1;i<=n;i++)
		if(!deg[i])
			DP1(i,-1),rt=i;
	for(int i=1;i<=n;i++)dp[i][1]=size[i],dp[i][size[i]]=1;
	DP2(rt,-1);
	printf("%d\n",dp[rt][p]);
}


