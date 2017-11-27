#include<bits/stdc++.h>
using namespace std;
struct {
	int a,b;
}A[1010];
int dp[1010];
int check(int u,int k){
	if(A[k].a>A[u].a&&A[k].b>A[u].b)return 1;
	if(A[k].a>A[u].b&&A[k].b>A[u].a)return 1;
	return 0;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d%d",&A[i].a,&A[i].b);
		dp[1]=1;
		for(int i=1;i<=n;i++){
			dp[i]=1;
			for(int j=i-1;j>=1;j--){
				if(check(j,i))dp[i]=max(dp[i],dp[j]+1);
			}	
		}
		int ans=0;
		for(int i=1;i<=n;i++)ans=max(ans,dp[i]);
		cout<<ans<<endl;
	}
}


