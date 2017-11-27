#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int mod=1e9+7;
char s[1000010];
LL dp[1000010][4];
//0 0==0
//0 1==1
//1 0==2
//1 1==3
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	dp[0][1]=dp[0][0]=1;
	for(int i=1;i<n;i++){
		if(s[i]=='?'){
			dp[i][0]=(dp[i-1][0]+dp[i-1][2])%mod;
			dp[i][1]=dp[i][0];
			dp[i][2]=(dp[i-1][1]+dp[i-1][3])%mod;
			dp[i][3]=dp[i][2];
		}
		if(s[i]=='0')
			dp[i][0]=dp[i-1][0];
		if(s[i]=='1'){
			dp[i][1]=dp[i-1][0];
			dp[i][0]=dp[i-1][2];
		}
		if(s[i]=='2')
			dp[i][1]=dp[i-1][2];
		if(s[i]=='*'){
			dp[i][2]=(dp[i-1][1]+dp[i-1][3])%mod;
			dp[i][3]=(dp[i-1][1]+dp[i-1][3])%mod;
		}
	}
	if(s[n]=='?')printf("%d\n",(dp[n-1][0]+dp[n-1][1]+dp[n-1][2]+dp[n-1][3])%mod);
	if(s[n]=='0')printf("%d\n",dp[n-1][0]);
	if(s[n]=='1')printf("%d\n",dp[n-1][2]);
	if(s[n]=='2')printf("%d\n",0);
	if(s[n]=='*')printf("%d\n",(dp[n-1][1]+dp[n-1][3])%mod);
}


