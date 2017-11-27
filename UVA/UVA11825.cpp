#include<bits/stdc++.h>
using namespace std;
const int maxn=1<<16+10;
int dp[maxn],A[17],cover[maxn];
int main(){
	int n,k,x,cas=1;
	while(scanf("%d",&n)&&n){
		memset(A,0,sizeof(A));
		memset(cover,0,sizeof(cover));
		for(int i=0;i<n;i++){
			scanf("%d",&k);
			A[i]|=(1<<i);
			for(int j=1;j<=k;j++){
				scanf("%d",&x);
				A[i]|=(1<<x);
			}
		}
		int num=1<<n;
		for(int i=0;i<num;i++){
			for(int j=0;j<n;j++)
				if(i&(1<<j))cover[i]|=A[j];
		}
		memset(dp,0,sizeof(dp));
		for(int s=1;s<num;s++){
			for(int i=s;i;i=(i-1)&s)
				if(cover[i]==num-1)
					dp[s]=max(dp[s],dp[i^s]+1);
		}
		printf("Case %d: ",cas++);
		cout<<dp[num-1]<<endl;
	}
}


