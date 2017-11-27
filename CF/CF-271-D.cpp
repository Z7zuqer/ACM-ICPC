#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int mod=1e9+7;
LL dp[100000+7];
LL tr[100007<<2];
void build(int t,int l,int r){
	if(l==r){
		tr[t]=dp[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(t<<1,l,mid);
	build(t<<1|1,mid+1,r);
	tr[t]=(tr[t<<1]+tr[t<<1|1])%mod;
}
LL query(int t,int l,int r,int L,int R){
	if(L<=l&&r<=R)return tr[t];
	int mid=(l+r)>>1;
	LL res=0;
	if(mid>=L)res+=query(t<<1,l,mid,L,R);
	if(mid<R)res+=query(t<<1|1,mid+1,r,L,R);
	return res%mod;
}
int main(){
	int t,k;
	scanf("%d%d",&t,&k);
	dp[0]=1;
	for(int i=1;i<=100000;i++){
		dp[i]=dp[i-1];
		if(i-k>=0)dp[i]=(dp[i]+dp[i-k])%mod;
	}
	//for(int i=1;i<=10;i++)cout<<dp[i]<<" ";cout<<endl;
	build(1,1,100000);
	while(t--){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%I64d\n",query(1,1,100000,a,b));
	}
}


