#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL A[100010],cnt[100010];
LL dp[100010]; 
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",&A[i]),cnt[A[i]]++;
	for(int i=1;i<=100010;i++){
		dp[i]=max(dp[i-1],dp[i-2]+1LL*cnt[i]*i);
	}
	LL maxm=0;
	for(int i=1;i<=100010;i++)maxm=max(maxm,dp[i]);
	printf("%I64d\n",maxm); 
}


