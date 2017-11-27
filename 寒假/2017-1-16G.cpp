#include<bits/stdc++.h>
using namespace std;
int A[1000010],B[1000010],C[10000010];
int n1,n2,flg;
int dp[2010][2010];
//stack<int>A,B,C;/
int dfs(int now1,int now2){
	if(dp[now1][now2]!=-1)return dp[now1][now2];
	dp[now1][now2]=0; 
	if(A[now1]==C[now1+now2])dp[now1][now2]|=dfs(now1-1,now2);
	if(B[now2]==C[now1+now2])dp[now1][now2]|=dfs(now1,now2-1);
	return dp[now1][now2];
}
int main(){
	while(scanf("%d%d",&n1,&n2)!=EOF&&n1&&n2){
		memset(dp,-1,sizeof(dp));
		for(int i=1;i<=n1;i++)scanf("%d",&A[i]);
		for(int i=1;i<=n2;i++)scanf("%d",&B[i]);
		for(int i=1;i<=n1+n2;i++)scanf("%d",&C[i]);
		dp[1][0]=(A[1]==C[1]);
		dp[0][1]=(B[1]==C[1]);
		if(dfs(n1,n2))cout<<"possible"<<endl;
		else cout<<"not possible"<<endl;
	}
}


