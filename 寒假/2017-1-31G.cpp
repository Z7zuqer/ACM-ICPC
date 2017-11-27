#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int dp[50001][2];
int n,a,b;
int main(){
	cin>>n>>a>>b;
	dp[0][0]=dp[0][1]=1;
	for(int i=0;i<=n;i++){
		for(int j=1;i+j<=n&&j<=a;j++)
			dp[i+j][1]=(dp[i+j][1]+dp[i][0])%mod;
		for(int j=1;i+j<=n&&j<=b;j++)
			dp[i+j][0]=(dp[i+j][0]+dp[i][1])%mod;
	}
	cout<<(dp[n][1]+dp[n][0])%mod<<endl;
}


