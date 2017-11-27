#include<bits/stdc++.h>
using namespace std;
const int maxn=35000+107;
int tr[maxn<<2],flg[maxn<<2];
int dp[maxn][51],LAST[maxn],A[maxn];
void build(int t,int l,int r,int k){
	flg[t]=0;tr[t]=0;
	if(l==r){
		//cout<<l<<endl;
		tr[t]=dp[l-1][k];
		return ;
	}
	int mid=(l+r)>>1;
	build(t<<1,l,mid,k);
	build(t<<1|1,mid+1,r,k);
	tr[t]=max(tr[t<<1],tr[t<<1|1]);
}
void pushdown(int t){
	if(flg[t]){
		flg[t<<1]+=flg[t];
		flg[t<<1|1]+=flg[t];
		tr[t<<1]+=flg[t];
		tr[t<<1|1]+=flg[t];
		flg[t]=0;
	}
}
void update(int t,int l,int r,int L,int R){
	if(L<=l&&r<=R){
		flg[t]++;
		tr[t]++;
		return ; 
	}
	pushdown(t);
	int mid=(l+r)>>1;
	if(mid>=L)update(t<<1,l,mid,L,R);
	if(mid<R)update(t<<1|1,mid+1,r,L,R);
	tr[t]=max(tr[t<<1],tr[t<<1|1]);
}
int query(int t,int l,int r,int L,int R){
	if(L<=l&&r<=R)return tr[t];
	pushdown(t);
	int mid=(l+r)>>1,res=0;
	if(mid>=L)res=max(res,query(t<<1,l,mid,L,R));
	if(mid<R)res=max(res,query(t<<1|1,mid+1,r,L,R));
	tr[t]=max(tr[t<<1],tr[t<<1|1]);
	return res; 
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	for(int sta=1;sta<=k;sta++){
		build(1,1,n,sta-1);
		for(int i=1;i<=n;i++)LAST[i]=0;
		for(int r=1;r<=n;r++){
			//cout<<LAST[A[r]]<<" "<<r<<endl;
			update(1,1,n,LAST[A[r]]+1,r);
			dp[r][sta]=query(1,1,n,1,r);
			//cout<<r<<" "<<sta<<" "<<dp[r][sta]<<endl;
			LAST[A[r]]=r;
		}
	}
	printf("%d\n",dp[n][k]);
}


