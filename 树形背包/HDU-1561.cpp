#include<bits/stdc++.h>
using namespace std;
const int maxn=210;
int n,m,A[maxn];
vector<int>v[maxn];
int dp[maxn][maxn];
void DP(int u,int fa){
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i];
		if(e==fa)continue;
		DP(e,u);
		for(int j=m;j>1;j--)
			for(int k=1;k<j;k++)
				dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[e][k]);
	}
}
int main(){
	while(~scanf("%d%d",&n,&m)&&n&&m){
		memset(dp,0,sizeof dp);m+=1;
		for(int i=0;i<=n;i++)v[i].clear();
		for(int i=1;i<=n;i++){
			int a;
			scanf("%d%d",&a,&A[i]);
			v[a].push_back(i);
		}
		for(int i=1;i<=n;i++)
			dp[i][1]=A[i];
		DP(0,-1);
		cout<<dp[0][m]<<endl;
	}
}


