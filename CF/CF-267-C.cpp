#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL A[5010],sum[5010],dp[5010][5010],maxv[5010];
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%I64d",&A[i]),sum[i]=sum[i-1]+A[i];
	for(int j=1;j<=k;j++)
		for(int i=j*m;i<=n;i++)
			dp[i][j]=max(dp[i-1][j],dp[i-m][j-1]+sum[i]-sum[i-m]);
	cout<<dp[n][k]<<endl;
}


