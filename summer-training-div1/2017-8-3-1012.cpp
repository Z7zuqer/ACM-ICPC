#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int maxn=2007;
int dp[maxn][maxn][2];
int tr[2][maxn][maxn],A[maxn],B[maxn]; 
void add(int now,int x,int y,int v){
	tr[now][x][y]=(1LL*tr[now][x][y]+v*1LL)%mod;
	for(int i=x;i<maxn;i+=i&-i)
		for(int j=y;j<maxn;j+=j&-j)
			tr[now][i][j]=(1LL*tr[now][i][j]+v*1LL)%mod;
}
int getans(int now,int x,int y){
	int ans=0;
	for(int i=x;i;i-=i&-i)
		for(int j=y;j;j-=j&-j)
			ans=(ans*1LL+tr[now][i][j])%mod;
	return ans;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d",&A[i]);
		for(int i=1;i<=m;i++)scanf("%d",&B[i]);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				dp[i][j][0]=dp[i][j][1]=0;
		memset(tr,0,sizeof tr);
		int ans=0;
		dp[1][1][1]=dp[1][1][0]=1;
		add(0,0,0,1);
		add(1,0,0,1);
		for(int j=1;j<=m;j++)
			for(int i=1;i<=n;i++){
				if(A[i]==B[j]){
					dp[i][j][0]=(dp[i][j][0]*1LL+getans(1,i-1,A[i]-1))%mod;
					dp[i][j][1]=(dp[i][j][1]*1LL+getans(0,i-1,maxn-1)-getans(0,i-1,A[i]))%mod;
					add(0,i,A[i],dp[i][j][0]);
					add(1,i,A[i],dp[i][j][1]);
					ans=(ans*1LL+dp[i][j][1]+dp[i][j][0])%mod;
				}
			}
		printf("%d\n",ans);
	} 
}


