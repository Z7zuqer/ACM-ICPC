#include<bits/stdc++.h>
using namespace std;
int dp[210][5500]; 
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<=k;i++)
		for(int j=0;j<5500;j++)
			dp[i][j]=-1e9;
	dp[0][0]=0;
	for(int num=1;num<=n;num++){
		long long x;
		scanf("%I64d",&x);
		long long cnt1=0,tmp=x;while(tmp%2==0)cnt1++,tmp/=2;
		long long cnt2=0;tmp=x;while(tmp%5==0)cnt2++,tmp/=5;
		for(int i=k-1;i>=0;i--)
			for(int j=0;j+cnt2<5500;j++)
				dp[i+1][j+cnt2]=max(1LL*dp[i+1][j+cnt2],dp[i][j]+cnt1);
	}
	int maxm=0;
	for(int i=0;i<5000;i++)maxm=max(maxm,min(dp[k][i],i));
	cout<<maxm<<endl;
}


