#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
struct node{
	int e,ord;
};
vector<node>v[maxn]; 
int dp[maxn][2];
void DP1(int u,int fa){
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i].e,ord=v[u][i].ord;
		if(e==fa)continue;
		DP1(e,u);
		dp[u][1]+=dp[e][1]+ord;
		//dp[e][0]=dp[u][1]-dp[e][1]+1-ord+dp[u][0];
	}
	//if(fa!=-1)dp[u][0]=dp[u][1]-dp[e][1]+1-ord+dp[u][0];
}
void DP2(int u,int fa){
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i].e,ord=v[u][i].ord;
		if(fa==e)continue;
		dp[e][0]=dp[u][0]+dp[u][1]-dp[e][1]-ord+(1-ord);
		DP2(e,u);
	}
}
vector<int>r;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back({b,0});
		v[b].push_back({a,1});
	}
	DP1(1,-1);
	DP2(1,-1);
	int minm=1e9;
	//for(int i=1;i<=n;i++)cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
	for(int i=1;i<=n;i++)
		if(dp[i][1]+dp[i][0]<minm){
			r.clear();
			r.push_back(i);
			minm=dp[i][1]+dp[i][0];
		}
		else if(dp[i][1]+dp[i][0]==minm)r.push_back(i);
	printf("%d\n",minm);
	for(int i=0;i<r.size();i++)printf("%d ",r[i]);cout<<endl;
}


