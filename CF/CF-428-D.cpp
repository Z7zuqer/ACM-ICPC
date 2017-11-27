#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=1000010;
const int mod=1e9+7;
int vis[1000100];
LL A[200100],dp[1000100],maxm,cnt[1000100];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",&A[i]),maxm=max(maxm,A[i]),cnt[A[i]]++;
	LL ans=0;
	for(int i=maxn-1;i>=2;i++){
		int x=0;
		for(int j=i;j<maxn;j+=i)x+=cnt[j];
		if(x){
			for(int j=)
		}
	} 
	for(int i=2;i<=maxm;i++)ans=(ans+dp[i])%mod;
	for(int i=1;i<=n;i++)if(A[i]>1)ans=(ans+dp[i])%mod;
	printf("%I64d\n",ans);
}


