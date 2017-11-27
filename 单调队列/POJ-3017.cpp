#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=100100;
LL que[maxn],A[maxn],dp[maxn],tr[maxn<<2],sum[maxn];
void build(int t,int l,int r){
	if(l==r){
		tr[t]=A[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(t<<1,l,mid);
	build(t<<1|1,mid+1,r);
	tr[t]=max(tr[t<<1],tr[t<<1|1]);
}
LL query(int t,int l,int r,int L,int R){
	if(L<=l&&r<=R)return tr[t];
	int mid=(l+r)>>1;
	LL res=0;
	if(mid>=L)res=max(res,query(t<<1,l,mid,L,R));
	if(mid<R)res=max(res,query(t<<1|1,mid+1,r,L,R));
	return res;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&A[i]);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+A[i];
	build(1,1,n);
	int T=1,H=1;
	for(int i=1;i<=n;i++){
		while(T<=H&&sum[i]-sum[que[T]]>1LL*m)T++;
		//cout<<sum[i]<<" "<<sum[que[T]]<<endl;
		dp[i]=dp[que[T]]+query(1,1,n,que[T]+1,i);
		cout<<que[T]<<" "<<que[H]<<" "<<i<<" "<<dp[i]<<endl;
		//while(T<=H&&dp[que[H]]+query(1,1,n,que[H]+1,i)>=dp[i])H--;
		que[++H]=i;
	}
	printf("%lld\n",dp[n]);
}


