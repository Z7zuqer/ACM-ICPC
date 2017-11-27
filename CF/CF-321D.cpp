#include<bits/stdc++.h>
using namespace std;
#define LL long long
int A[21];
int comb[21][21];
LL dp[1<<20][20],ans;
int getnum(int k){
	int r=0;
	while(k){
		if(k&1)r++;
		k>>=1;
	}
	return r;
} 
int main(){
	int n,m,k;
	cin>>n>>m>>k; 
	for(int i=0;i<n;i++)scanf("%d",&A[i]);
	for(int i=1;i<=k;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		x--;y--;
		comb[x][y]=z;
	} 
	int end=(1<<n);
	for(int st=0;st<end;st++){
		for(int j=0;j<n;j++){
			if(st&(1<<j)){
				dp[st][j]=A[j];
				for(int k=0;k<n;k++){
					if(k!=j&&st&(1<<k)){
						dp[st][j]=max(dp[st][j],dp[st^(1<<j)][k]+comb[k][j]+A[j]);
					}
				}
			}
			if(getnum(st)==m)ans=max(ans,dp[st][j]);
		}
	}
	cout<<ans<<endl;
}


