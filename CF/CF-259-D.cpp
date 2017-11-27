#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL dp[110][65536+7],A[110];
LL num[17]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
LL pre[110][65536+7],ans[110][65536+7];
int stat[60];
vector<LL>v;
int main(){
	int n;
	for(int i=1;i<=58;i++)
		for(int j=0;j<16;j++)
			if(i%num[j]==0)
				stat[i]|=(1<<j);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",&A[i]);
	memset(dp,0x3f,sizeof dp);
	for(int i=0;i<65536;i++)dp[0][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<65536;j++){
			/*
			10
			22 17 28 14 14 26 20 28 21 27
			*/
			for(int k=1;k<59;k++){
					int sta=stat[k];
					if((sta&j)!=0)continue;
					if(dp[i][j|sta]>dp[i-1][j]+abs(A[i]-k)){
						dp[i][j|sta]=dp[i-1][j]+abs(A[i]-k);
						pre[i][j|sta]=j;//cout<<"Dsada"<<endl;
						ans[i][j|sta]=k;
					}
			}
		}
	}
	LL endsta=0,minm=1e9;
	for(int i=0;i<65536;i++)
		if(dp[n][i]<minm){
			minm=dp[n][i];
			endsta=i;
		}
	//cout<<minm<<endl;
	for(int i=n;i>=1;i--){
		v.push_back(ans[i][endsta]);
		endsta=pre[i][endsta];
	} 
	for(int i=v.size()-1;i>=0;i--)printf("%I64d ",v[i]);printf("\n");
}


