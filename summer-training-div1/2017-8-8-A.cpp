#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+177;
int tr[maxn<<2],flg[maxn<<2];
int n,m,L[maxn],R[maxn],A[maxn];
void build(int t,int l,int r,int x){
	flg[t]=-1;
	if(l==r){
		tr[t]=(A[l]>x);
		return ;
	}
	int mid=(l+r)>>1;
	build(t<<1,l,mid,x);
	build(t<<1|1,mid+1,r,x);
	tr[t]=tr[t<<1]+tr[t<<1|1];
}
void pushdown(int t,int l,int r){
	if(flg[t]!=-1){
		int mid=(l+r)>>1;
		flg[t<<1]=flg[t<<1|1]=flg[t];
		tr[t<<1]=flg[t]*(mid-l+1);
		tr[t<<1|1]=flg[t]*(r-mid);
	}
	flg[t]=-1;
}
int query(int t,int l,int r,int L,int R){
	if(L<=l&&r<=R)return tr[t];
	pushdown(t,l,r);
	int mid=(l+r)>>1,res=0;
	if(mid>=L)res+=query(t<<1,l,mid,L,R);
	if(mid<R)res+=query(t<<1|1,mid+1,r,L,R);
	tr[t]=tr[t<<1]+tr[t<<1|1];
	return res; 
}
void update(int t,int l,int r,int L,int R,int v){
	if(L>R)return ;
	if(L<=l&&r<=R){
		flg[t]=v;
		tr[t]=v*(r-l+1);
		return ;
	}
	pushdown(t,l,r);
	int mid=(l+r)>>1;
	if(mid>=L)update(t<<1,l,mid,L,R,v);
	if(mid<R)update(t<<1|1,mid+1,r,L,R,v);
	tr[t]=tr[t<<1]+tr[t<<1|1];
}
int check(int x){
	build(1,1,n,x);
	for(int i=1;i<=m;i++){
		if(L[i]==R[i])continue;
		if(L[i]<R[i]){
			int r_0=R[i]-L[i]+1-query(1,1,n,L[i],R[i]);
			update(1,1,n,L[i],L[i]+r_0-1,0);
			update(1,1,n,L[i]+r_0,R[i],1);
		}
		else {
			int r_1=query(1,1,n,R[i],L[i]);
			update(1,1,n,R[i],R[i]+r_1-1,1);
			update(1,1,n,R[i]+r_1,L[i],0);
		}
	}
	return query(1,1,n,(n+1)/2,(n+1)/2)==0;
}
int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++)scanf("%d",&A[i]);
		for(int i=1;i<=m;i++)scanf("%d%d",&L[i],&R[i]);
		int l=1,r=n;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid))r=mid;
			else l=mid+1;
		}
		printf("%d\n",r);
	}
}


