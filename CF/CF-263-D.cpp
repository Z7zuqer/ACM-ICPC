#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=100010;
const int mod=1e9+7;
LL dp[maxn][2];
vector<int>v[maxn];
int col[maxn],size[maxn],dep[maxn],num[maxn];
void DP1(int u,int pre){
	if(col[u])dp[u][1]=1;
	else dp[u][0]=1;
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i];
		if(e==pre)continue;
		DP1(e,u);
		dp[u][1]=(dp[u][1]*dp[e][0]+dp[u][1]*dp[e][1]+dp[u][0]*dp[e][1])%mod;
		dp[u][0]=(dp[u][0]*dp[e][0]+dp[u][0]*dp[e][1])%mod;
	}
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		int x;
		scanf("%d",&x);
		v[x+1].push_back(i);
		v[i].push_back(x+1);
	} 
	for(int i=1;i<=n;i++)scanf("%d",&col[i]);
	DP1(1,0);
	cout<<dp[1][1]<<endl;
}


