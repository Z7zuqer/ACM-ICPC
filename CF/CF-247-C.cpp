#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int mod=1e9+7;
LL dp[11000][110]; 
int main(){
	int n,k,d;
	scanf("%d%d%d",&n,&k,&d);
	//dp[1][1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(i==j)dp[i][j]++;
			for(int u=1;u<=k;u++){
				dp[i+u][max(j,u)]=(dp[i][j]+dp[i+u][max(j,u)])%mod;
			}
		}
	}
	LL ans=0;
	for(int i=d;i<=k;i++)ans=(ans+dp[n][i])%mod;
	cout<<ans<<endl;
}


