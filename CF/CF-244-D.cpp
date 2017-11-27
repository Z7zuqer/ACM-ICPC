#include<bits/stdc++.h>
using namespace std;
const int maxn=5010;
char A[maxn],B[maxn];
int maxA[maxn],maxB[maxn],dp[maxn][maxn];
void show(int n,int m){
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=m;j++)
			printf("%d ",dp[i][j]);
}
int main(){
	scanf("%s%s",A+1,B+1);
	int lenA=strlen(A+1);
	int lenB=strlen(B+1);
	for(int i=1;i<=lenA;i++)
		for(int j=1;j<=lenA;j++)
			if(i==j);
			else if(A[i]==A[j])dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=0;
	//show(lenA,lenA);
	for(int i=1;i<=lenA;i++){
		int mx=0;
		for(int j=1;j<=lenA;j++)
			mx=max(mx,dp[i][j]);
		maxA[i]=mx+1;
	}
	for(int i=1;i<=lenB;i++)
		for(int j=1;j<=lenB;j++)
			if(i==j);
			else if(B[i]==B[j])dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=0;
	for(int i=1;i<=lenB;i++){
		int mx=0;
		for(int j=1;j<=lenB;j++)
			mx=max(mx,dp[i][j]);
		maxB[i]=mx+1;
	}
	int ans=1e9;
	for(int i=1;i<=lenA;i++)
		for(int j=1;j<=lenB;j++){
			if(A[i]==B[j])dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=0;
			if(dp[i][j]>=maxA[i]&&dp[i][j]>=maxB[j])
				ans=min(ans,max(maxA[i],maxB[j]));
		}
	if(ans==1e9)cout<<"-1"<<endl;
	else cout<<ans<<endl;
}


