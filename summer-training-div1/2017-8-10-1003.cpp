#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int dp[maxn][22],n,A[maxn],B[maxn];
void init(){
	for(int i=1;i<=n;i++)dp[i][0]=A[i];
	for(int j=1;j<=20;j++)
		for(int i=1;i<=n;i++)
			if(i+(1<<j)-1<=n)
				dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int query(int l,int r){
	int k=(int)(log2((double)r-l+1));
	return max(dp[l][k],dp[r-(1<<k)+1][k]);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&A[i]),B[i]=0;
		memset(dp,0,sizeof dp);
		init();
		for(int i=2;i<=n;i++){
			for(int j=1;(j-1)*i+1<=n;j++){
				B[i]=max(B[i],query((j-1)*i+1,min(n,j*i-1)));
				//cout<<(j-1)*i+1<<" "<<j*i-1<<endl;
			}
		}
		for(int i=2;i<=n;i++)
			if(i!=n)printf("%d ",B[i]);
			else printf("%d\n",B[i]);
	}
}


