#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int dp[maxn][maxn][11];
int a[maxn][2],f[maxn][11];
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]+=a[i-1][j];
	if(m==1){
		for(int i=1;i<=n;i++)
			for(int u=1;u<=k;u++){
				f[i][u]=f[i-1][u];
				for(int x=0;x<i;x++)f[i][u]=max(f[i][u],f[x][u-1]+a[i][1]-a[x][1]);
		}
		cout<<f[n][k]<<endl;
	}
	else {
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int u=1;u<=k;u++){
					dp[i][j][u]=max(dp[i-1][j][u],dp[i][j-1][u]);
					for(int x=0;x<i;x++)dp[i][j][u]=max(dp[i][j][u],dp[x][j][u-1]+a[i][1]-a[x][1]);
					for(int y=0;y<j;y++)dp[i][j][u]=max(dp[i][j][u],dp[i][y][u-1]+a[j][2]-a[y][2]);
					if(i==j)for(int x=0;x<i;x++)dp[i][j][u]=max(dp[i][j][u],dp[x][x][u-1]+a[i][2]-a[x][2]+a[i][1]-a[x][1]);
				}
		cout<<dp[n][n][k]<<endl;
	}
}
