#include<bits/stdc++.h>
using namespace std;
const int maxn=410;
int vis[410][410];
double dp[410][410];
double dfs(int l,int r){
	if(vis[l][r])return dp[l][r];
	if(r-l==1)return dp[l][r]=20;
	if(l>r)return 0;
	//if(l==r)return dp[l][r]=10;
	vis[l][r]=1;
	double div=1.0/(r-l+1.0);
	for(int i=l;i<=r;i++)
		dp[l][r]+=div*(max(dfs(l,i-1),dfs(i+1,r)));
	return dp[l][r];
} 
int main(){
	int n;
	scanf("%d",&n);
	printf("%.8lf\n",dfs(1,n)+10);
}


