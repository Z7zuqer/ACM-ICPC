#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+1;
struct {
	int l1,r1,m1;
	int l0,r0,m0;
	int lz;
}tr[maxn*6];
void pushup(int t,int l,int r){
	int mid=(l+r)>>1;
	//if(!tr[t<<1].vis||!tr[t<<1|1].vis)return ;
	//if((t*2)>maxv||(t*2+1)>maxv)return ;
	tr[t].l1=tr[t<<1].l1;if(tr[t<<1].l1==mid-l+1)tr[t].l1=max(tr[t].l1,tr[t<<1|1].l1+mid-l+1);
	tr[t].l0=tr[t<<1].l0;if(tr[t<<1].l0==mid-l+1)tr[t].l0=max(tr[t].l0,tr[t<<1|1].l0+mid-l+1);
	tr[t].r1=tr[t<<1|1].r1;if(tr[t<<1|1].r1==r-mid)tr[t].r1=max(tr[t].r1,tr[t<<1].r1+r-mid);
	tr[t].r0=tr[t<<1|1].r0;if(tr[t<<1|1].r0==r-mid)tr[t].r0=max(tr[t].r0,tr[t<<1].r0+r-mid);
	tr[t].m1=max(tr[t<<1].m1,max(tr[t<<1|1].m1,tr[t<<1].r1+tr[t<<1|1].l1));
	tr[t].m0=max(tr[t<<1].m0,max(tr[t<<1|1].m0,tr[t<<1].r0+tr[t<<1|1].l0));
}
void sswap(int t){
	swap(tr[t].l1,tr[t].l0);
	swap(tr[t].r1,tr[t].r0);
	swap(tr[t].m1,tr[t].m0);
}
void pushdown(int t){
	if(tr[t].lz){
		tr[t<<1].lz^=1;
		tr[t<<1|1].lz^=1;
		sswap(t<<1);sswap(t<<1|1);
		tr[t].lz=0;
	}
}
void build(int t,int l,int r){
	tr[t].lz=0;
	if(l==r){
		int x;
		scanf("%d",&x);
		tr[t].l1=tr[t].r1=tr[t].m1=x;
		tr[t].l0=tr[t].r0=tr[t].m0=x^1;
		return ;
	}
	int mid=(l+r)>>1;
	build(t<<1,l,mid);
	build(t<<1|1,mid+1,r);
	pushup(t,l,r);
}
void update(int t,int l,int r,int L,int R){
	pushdown(t);
	if(L<=l&&r<=R){
		tr[t].lz^=1;
		sswap(t);
		//pushup(t,l,r);
		return ;
	}
	int mid=(l+r)>>1;
	pushdown(t);
	if(mid>=L)update(t<<1,l,mid,L,R);
	if(mid<R)update(t<<1|1,mid+1,r,L,R);
	pushup(t,l,r);
}
int query(int t,int l,int r,int L,int R){
	pushdown(t);
	//cout<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
	if(L<=l&&r<=R)return tr[t].m1;
	int mid=(l+r)>>1,res=0;pushdown(t);
	if(mid>=R)res=query(t<<1,l,mid,L,R);
	else if(mid<L)res=query(t<<1|1,mid+1,r,L,R);
	else res=max(max(query(t<<1,l,mid,L,mid),query(t<<1|1,mid+1,r,mid+1,R)),min(tr[t<<1].r1,mid-L+1)+min(tr[t<<1|1].l1,R-mid));
	pushup(t,l,r);
	return res;
}
/*
6
0 1 1 0 1 0
8
1 1 1
0 1 3
1 1 6
0 4 6
0 4 4
1 1 3
0 1 6
*/
int main(){
	int n;
	scanf("%d",&n);
	build(1,1,n);
	int m;
	scanf("%d",&m);
	while(m--){
		int k,l,r;
		scanf("%d%d%d",&k,&l,&r);
		//if(r<l)swap(l,r);
		if(k==1)update(1,1,n,l,r);
		if(k==0)printf("%d\n",query(1,1,n,l,r));
		//for(int i=1;i<=n;i++)printf("%d ",query(1,1,n,i,i));cout<<endl;
	}
	return 0;
}


