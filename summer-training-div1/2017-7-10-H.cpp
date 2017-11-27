#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,A[250101],B[250101],tr[250101*4*8];
void build(int t,int l,int r){
	if(l==r){
		if(l>n)tr[t]=0;
		else tr[t]=A[l]-l;
		return ;
	}
	int mid=(l+r)>>1;
	build(t<<1,l,mid);
	build(t<<1|1,mid+1,r);
	tr[t]=max(tr[t<<1],tr[t<<1|1]);
}
void update(int t,int l,int r,int x,int v){
	if(l==r){
		tr[t]=v;
		return ;
	}
	int mid=(l+r)>>1;
	if(mid>=x)update(t<<1,l,mid,x,v);
	else update(t<<1|1,mid+1,r,x,v);
	tr[t]=max(tr[t<<1],tr[t<<1|1]);
}
int query(int t,int l,int r,int L,int R){
	if(L<=l&&r<=R)return tr[t];
	int mid=(l+r)>>1,re=0;
	if(mid>=L)re=max(re,query(t<<1,l,mid,L,R));
	if(mid<R)re=max(re,query(t<<1|1,mid+1,r,L,R));
	return re; 
}
int main(){
	while(scanf("%d",&n)==1){
		for(int i=1;i<=n;i++)scanf("%d",&A[i]);
		for(int i=1;i<=n;i++)scanf("%d",&B[i]);
		build(1,1,n*2);
		sort(B+1,B+1+n);
		int ans=0;
		for(int i=1;i<=n;i++){
			int k=query(1,1,n*2,B[i],i+n-1);
			ans+=k;if(ans>=mod)ans-=mod;
			update(1,1,n*2,i+n,k-i-n);
		}
		printf("%d\n",ans);
	}
}


