#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int A[151],B[151];
long long dp[2][15005];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,m,k,w;
		scanf("%d%d%d%d",&n,&m,&k,&w);
		for(int i=1;i<=n;i++)scanf("%d",&A[i]);
		for(int i=1;i<=m;i++)scanf("%d",&B[i]);
		memset(dp,0,sizeof(dp));
		dp[0][0]=dp[1][0]=1;
		for(int i=1;i<=n;i++)
			for(int j=w;j>=A[i];j--)
				dp[0][j]=(dp[0][j]+dp[0][j-A[i]])%mod;	
		for(int i=1;i<=m;i++)
			for(int j=w;j>=B[i];j--)
				dp[1][j]=(dp[1][j]+dp[1][j-B[i]])%mod;
		long long ans=0;
		for(int i=0;i<=w;i++)
			if(abs((w-i)-i)<=k)
				ans=(ans+dp[0][i]*dp[1][w-i])%mod;
		cout<<ans<<endl;
		//¸Õ¸Õ¿ª´íºÅÁË 
	}
}
