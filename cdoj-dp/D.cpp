#include<bits/stdc++.h>
using namespace std;
int dp[10101];
int A[20010],B[20010],C[20010];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&C[i],&A[i],&B[i]);
	for(int i=1;i<=n;i++){
		if(C[i]==1)
			for(int j=B[i];j<=k;j++)dp[j]=max(dp[j],dp[j-B[i]]+A[i]);
		if(C[i]==2)
			for(int j=k;j>=B[i];j--)dp[j]=max(dp[j],dp[j-B[i]]+A[i]);
	}
	int maxv=0;
	for(int i=0;i<=k;i++)if(maxv<dp[i])maxv=dp[i];
	cout<<maxv<<endl;
}


