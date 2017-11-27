#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001][11][2];
char s[1002],t[1002];
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s%s",s+1,t+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(s[i]==t[j]){
				int l=min(i,min(j,k));
				for(int u=1;u<=l;u++)
					dp[i][j][u][0]=max(dp[i-1][j-1][u][0],dp[i-1][j-1][u-1][1])+1;
			}
			int l=min(i,min(j,k));
			for(int u=1;u<=l;u++)
				dp[i][j][u][1]=max(max(dp[i-1][j][u][1],dp[i][j-1][u][1]),max(dp[i-1][j-1][u][1],dp[i][j][u][0]));
		}
	cout<<dp[n][m][k][1]<<endl;
}


