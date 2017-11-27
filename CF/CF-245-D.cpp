#include<bits/stdc++.h>
using namespace std; 
#define LL long long
const int maxn=1003;
LL dp[maxn][maxn];
LL mp[4][maxn][maxn],A[maxn][maxn];
int n,m,vis[4][maxn][maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&A[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			mp[0][i][j]=max(mp[0][i-1][j],mp[0][i][j-1])+A[i][j];
	for(int i=n;i>=1;i--)
		for(int j=m;j>=1;j--)
			mp[1][i][j]=max(mp[1][i+1][j],mp[1][i][j+1])+A[i][j];
	for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--)
			mp[2][i][j]=max(mp[2][i-1][j],mp[2][i][j+1])+A[i][j];
	for(int i=n;i>=1;i--)
		for(int j=1;j<=m;j++)
			mp[3][i][j]=max(mp[3][i+1][j],mp[3][i][j-1])+A[i][j];
	LL ans=0;
	for(int i=2;i<n;i++)
		for(int j=2;j<m;j++){
			ans=max(ans,mp[0][i-1][j]+mp[1][i+1][j]+mp[2][i][j+1]+mp[3][i][j-1]);
			ans=max(ans,mp[0][i][j-1]+mp[1][i][j+1]+mp[2][i-1][j]+mp[3][i+1][j]);
		}
	cout<<ans<<endl;
}


