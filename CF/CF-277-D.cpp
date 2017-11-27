#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=2010;
const int mod=1e9+7;
int n,d,A[maxn];
LL dp[maxn];
vector<int>v[maxn];
void dfs(int u,int pre){
	dp[u]=1;
	for(auto i:v[u]){
		if(i==pre)continue;
		dfs(i,u);
		dp[u]=dp[u]*dp[i]%mod;
	}
}
int main(){
	scanf("%d%d",&d,&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,-1);
}


