#include<bits/stdc++.h>
using namespace std;
int consume[17]={6,2,5,5,4,5,6,3,7,6,6,5,4,5,5,4};
#define LL long long
LL dp[21][1010];
int bits[21];
LL dfs(int len,LL sum,int mask){
	if(len<0)return sum;
	if(!mask&&dp[len][sum]!=-1)return dp[len][sum];
	LL tmp=0;
	int maxv=mask?bits[len]:15;
	for(int i=0;i<=maxv;i++)
		tmp+=dfs(len-1,sum+consume[i],mask&&i==maxv);
	if(!mask)dp[len][sum]=tmp;
	return tmp;
}
LL work(LL k){
	for(int i=0;i<8;i++){
		bits[i]=k%16;
		k/=16;
	}
	return dfs(7,0,1);
}
int main(){
	int T;
	cin>>T;
	memset(dp,-1,sizeof dp); 
	while(T--){
		LL r,n;
		scanf("%lld%llx",&r,&n);
		r--;
		LL l=n;
		r+=l;
		if(r>(LL)4294967295){
			r%=(LL)4294967296;
			printf("%lld\n",work((LL)4294967295)-work(l-1)+work(r));
			//cout<<work((LL)4294967295)-work(l-1)+work(r)<<endl;
		}
		else printf("%lld\n",work(r)-work(l-1));//cout<<work(r)-work(l-1)<<endl;
	}
}


