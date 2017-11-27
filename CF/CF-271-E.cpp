#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=100100;
int dp[maxn];
int tr[maxn<<2];
LL A[maxn],B[maxn];
int find(LL x){
	int l=0,r=n+1;
	while(l<r){
		int mid=(l+r)>>1;
		if(B[mid]>=x)r=mid;
		else l=mid+1;
	}
	return r;
}
void insert(int t,int l,int r,int pos,int v){
	if(l==r){
		tr[pos]=max(tr[pos],v);
		return ;
	}
	int mid=(l+r)>>1;
	if(mid>=pos)insert(t<<1,l,mid,pos,v);
	else insert(t<<1|1,mid+1,r,pos,v);
	tr[t]=max(tr[t<<1],tr[t<<1|1]);
}
int query(int t,int l,int r,int L,int R){
	if(L>r||R<l)return 0;
	if(L<=l&&r<=R)return tr[t];
	int mid=(l+r)>>1,res=0;
	if(mid>=L)res=max(res,query(t<<1,l,mid,L,R));
	if(mid<R)res=max(res,query(t<<1|1,mid+1,r,L,R));
	return res;
}
int main(){
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++)scanf("%I64d",&A[i]),B[i]=A[i];
	sort(B+1,B+1+n);
	for(int i=1;i<=n;i++)A[i]=find(A[i]);	
	for(int i=1;i<=n;i++){
		dp[i]=1;
		dp[i]=max(dp[i],find())
	}
}


