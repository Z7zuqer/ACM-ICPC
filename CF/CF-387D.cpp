#include<bits/stdc++.h>
using namespace std;
int dp[200010][2];
int tim[200010][2];
//0 a
//1 b
//2 no
int r[200010];
int main(){
	int n,k;
	memset(dp,0x3f,sizeof(dp));
	scanf("%d%d",&n,&k);
	dp[0][0]=0;
	for(int i=1;i<=n;i++)scanf("%d",&r[i]);
	for(int i=1;i<=n;i++){
		if(r[i]>=0){
			if(dp[i-1][0]>dp[i-1][1]+1){
				dp[i][0]=dp[i-1][1]+1;
				tim[i][0]=tim[i-1][1]+1;
			}
			else {
				dp[i][0]=dp[i-1][0];
				tim[i][0]=tim[i-1][0];
			}
		}
		else {
			if(dp[i-1][0]+1>dp[i-1][1]){
				dp[i][0]=dp[i-1][1];
				tim[i][0]=tim[i-1][1]+1;
			}
			else {
				dp[i][0]=dp[i-1][0]+1;
				tim[i][0]=tim[i-1][0]+1;
			}
		}
		
		if(dp[i-1][0]+1>dp[i-1][1]+1){
			dp[i][1]=dp[i-1][1]+1;
			tim[i][1]=tim[i-1][1]+1;
		}
		else {
			dp[i][1]=dp[i-1][0]+1;
			tim[i][1]=tim[i-1][0]+1;
		}
	}
	if(dp[n][0]>k){
		if(dp[n][1]<=k)cout<<tim[n][1]<<endl;
		else cout<<"-1"<<endl;
		return 0;
	}
	if(dp[n][1]>k){
		if(dp[n][0]<=k)cout<<tim[n][0]<<endl;
		else cout<<"-1"<<endl;
		return 0;
	}
	int ans=min(tim[n][0],tim[n][1]);
	cout<<ans<<endl;
}
