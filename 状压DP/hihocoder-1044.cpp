#include<bits/stdc++.h>
using namespace std;
#define LL long long
int dp[1001][1<<11];
int n,m,q; 
int A[1001];
int get(int k){
	int r=0;
	while(k){
		if(k&1)r++;
		k>>=1;
	}
	return r;
}
int main(){
	while(cin>>n>>m>>q){
		for(int i=1;i<=n;i++)cin>>A[i];
		int end=1<<m,ans=0;
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;i++){
			for(int st=0;st<end;st++){ 
				if(get(st)<=q)dp[i][st]=max(dp[i-1][(st>>1)+(1<<(m-1))],dp[i-1][st>>1])+(st&1)*A[i];
				ans=max(ans,dp[i][st]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}















