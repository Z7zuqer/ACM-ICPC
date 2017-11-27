#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=100000+107;
LL tr[maxn<<2],LA[maxn<<2],LB[maxn<<2],mod;//AX+B
void pushdown(int t,int l,int r){
	if(LA[t]==1&&LB[t]==0);
	else {
		LA[t<<1]=LA[t]*LA[t<<1]%mod;
		LA[t<<1|1]=LA[t<<1|1]*LA[t]%mod;
		LB[t<<1]=(LB[t<<1]*LA[t]%mod+LB[t])%mod;
		LB[t<<1|1]=(LB[t<<1|1]*LA[t]%mod+LB[t])%mod;
		int mid=(l+r)>>1;
		tr[t<<1]=(tr[t<<1]*LA[t]%mod+LB[t]*(LL)(mid-l+1)%mod)%mod;
		tr[t<<1|1]=(tr[t<<1|1]*LA[t]%mod+LB[t]*(LL)(r-mid)%mod)%mod;
		LA[t]=1;LB[t]=0;
	}
}
void pushup(int t){
	tr[t]=(tr[t<<1]+tr[t<<1|1])%mod;
}
void build(int t,int l,int r){
	LA[t]=1;LB[t]=0;
	if(l==r){
		scanf("%lld",&tr[t]);tr[t]%=mod;
		return ;
	}
	int mid=(l+r)>>1;
	build(t<<1,l,mid);
	build(t<<1|1,mid+1,r);
	pushup(t);
}
void update_1(int t,int l,int r,int L,int R,LL v){
	if(L<=l&&r<=R){
		LA[t]=LA[t]*v%mod;
		LB[t]=LB[t]*v%mod;
		tr[t]=tr[t]*v%mod;
		return ;
	}
	int mid=(l+r)>>1;
	pushdown(t,l,r);
	if(mid>=L)update_1(t<<1,l,mid,L,R,v);
	if(mid<R)update_1(t<<1|1,mid+1,r,L,R,v);
	pushup(t);
}
void update_2(int t,int l,int r,int L,int R,LL v){
	if(L<=l&&r<=R){
		LB[t]=(LB[t]+v)%mod;
		tr[t]=(tr[t]+(v*(LL)(r-l+1))%mod)%mod;
		return ;
	}
	int mid=(l+r)>>1;
	pushdown(t,l,r);
	if(mid>=L)update_2(t<<1,l,mid,L,R,v);
	if(mid<R)update_2(t<<1|1,mid+1,r,L,R,v);
	pushup(t);
}
LL query(int t,int l,int r,int L,int R){
	if(l>=L&&r<=R)return tr[t];
	int mid=(l+r)>>1;LL res=0;
	pushdown(t,l,r);
	if(L<=mid)res=(res+query(t<<1,l,mid,L,R))%mod;
	if(mid<R)res=(res+query(t<<1|1,mid+1,r,L,R))%mod;
	pushup(t);
	return res; 
}
int main(){
	int n,m;
	scanf("%d%lld",&n,&mod);
	build(1,1,n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int k,l,r;LL c;
		scanf("%d%d%d",&k,&l,&r);
		if(k==1){
			scanf("%lld",&c);
			update_1(1,1,n,l,r,c);
		}
		if(k==2){
			scanf("%lld",&c);
			update_2(1,1,n,l,r,c);
		}
		if(k==3)printf("%lld\n",query(1,1,n,l,r));
	}
}
