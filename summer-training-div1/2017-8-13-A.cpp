#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int mod=1e9+7;
const int maxn=110;
char s[maxn];
LL A[maxn],dp[maxn][maxn];
LL F[maxn][maxn],C[maxn][maxn];
LL dfs(int l,int r){
	if(dp[l][r]!=-1)return dp[l][r];
	if(l==r){
		F[l][r]=1;
		return dp[l][r]=A[l];
	}
	LL ans=0;
	dp[l][r]=0;
	F[l][r]=0;
	for(int i=l;i<r;i++){
		LL r1=dfs(l,i),r2=dfs(i+1,r); 
		if(s[i]=='*'){
			LL sum=(r1*r2%mod)*C[r-l-1][i-l]%mod;
			ans=(ans+sum+mod)%mod;
		}
		else if(s[i]=='+'){
			LL sum=(r1*F[i+1][r]%mod+r2*F[l][i]%mod+mod)%mod*C[r-l-1][i-l];
			ans=(ans+sum+mod)%mod;
		}
		else if(s[i]=='-'){
			LL sum=(r1*F[i+1][r]%mod-r2*F[l][i]%mod+mod)%mod*C[r-l-1][i-l];
			ans=(ans+sum+mod)%mod;
		}
		F[l][r]=(F[l][r]+(F[l][i]*F[i+1][r]%mod*C[r-l-1][i-l])%mod)%mod;
	/*
	2 3 3 2 1 -+
	*/
	}
	//cout<<l<<" "<<r<<" "<<F[l][r]<<endl;
	return dp[l][r]=(ans+mod)%mod;
}
void pre(){
	for(int i=0;i<maxn;i++){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }
}
int main(){
	int T;
	scanf("%d",&T);
	pre();
	while(T--){
		int n;
		memset(dp,-1,sizeof dp); 
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&A[i]);
		scanf("%s",s+1);
		printf("%lld\n",dfs(1,n)%mod);
	}
}


