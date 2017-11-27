#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int pos[maxn][maxn],A[maxn][maxn];
int dp[maxn];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++){
			scanf("%d",&A[i][j]);
			pos[i][A[i][j]]=j;
		}
	for(int i=1;i<=n;i++)dp[i]=1;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
				int flg=0;
				for(int u=2;u<=k;u++)	
					if(pos[u][A[1][j]]<pos[u][A[1][i]]){
						flg=1;
						break;
					}
				if(!flg)dp[j]=max(dp[j],dp[i]+1);
			}
	int maxm=0;
	for(int i=1;i<=n;i++)maxm=max(maxm,dp[i]);	
	cout<<maxm<<endl;
}


