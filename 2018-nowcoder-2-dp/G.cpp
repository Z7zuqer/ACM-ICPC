#include<bits/stdc++.h>
using namespace std;
int dp[50][4],bits[50];
int dfs(int len,int is3,int mask){
	if(len==0)return 1;
	if(!mask&&dp[len][is3]>=0)return dp[len][is3];
	int cnt=0,maxv=(mask?bits[len]:9);
	for(int i=0;i<=maxv;i++){
		if(i==4||(is3&&i==8))continue;
		cnt+=dfs(len-1,i==3,mask&&i==maxv);
	}
	return mask?cnt:dp[len][is3]=cnt;
}
int getans(int k){
	int len=0;
	while(k){
		bits[++len]=k%10;
		k/=10;
	}
	return dfs(len,0,1);
}
int main(){
	memset(dp,-1,sizeof dp);
	int l,r;
	while(~scanf("%d%d",&l,&r)&&(l||r))printf("%d\n",r-l+1-getans(r)+getans(l-1));
}


