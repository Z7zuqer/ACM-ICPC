#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=100100;
LL tr[maxn<<2],flgadd[maxn<<2],flgcol[maxn<<2];
void pushup(int t){
	tr[t]=tr[t<<1]+tr[t<<1|1];
	if(flgcol[t<<1]==flgcol[t<<1|1]&&flgcol[t<<1|1]!=-1)flgcol[t]=flgcol[t<<1];
	else flgcol[t]=-1;
}
void pushdown(int t,int l,int r){
	if(flgadd[t]){
		flgadd[t<<1]+=flgadd[t];
		flgadd[t<<1|1]+=flgadd[t];
		int mid=(l+r)>>1;
		tr[t<<1]+=flgadd[t]*(mid-l+1)*1LL;
		tr[t<<1|1]+=flgadd[t]*(r-mid)*1LL;
		flgadd[t]=0;
	}
	if(flgcol[t]!=-1)flgcol[t<<1]=flgcol[t<<1|1]=flgcol[t];
}
void build(int t,int l,int r){
	if(l==r){
		tr[t]=0;
		flgcol[t]=l;
		return ;
	}
	int mid=(l+r)>>1;
	build(t<<1,l,mid);
	build(t<<1|1,mid+1,r);
	pushup(t);
}
void update(int t,int l,int r,int L,int R,LL x){
	if(L<=l&&r<=R&&flgcol[t]!=-1){
		tr[t]+=(1LL*abs(x-flgcol[t])*(r-l+1));
		flgadd[t]+=(1LL*abs(x-flgcol[t]));
		flgcol[t]=x;
		return ;
	}
	pushdown(t,l,r);
	int mid=(l+r)>>1;
	if(mid>=L)update(t<<1,l,mid,L,R,x);
	if(mid<R)update(t<<1|1,mid+1,r,L,R,x);
	pushup(t);
}
LL query(int t,int l,int r,int L,int R){
	if(L<=l&&r<=R)return tr[t];
	pushdown(t,l,r);
	int mid=(l+r)>>1;
	LL res=0;
	if(mid>=L)res+=query(t<<1,l,mid,L,R);
	if(mid<R)res+=query(t<<1|1,mid+1,r,L,R);
	return res;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int k;
		scanf("%d",&k);
		if(k==1){
			int l,r;LL x;
			scanf("%d%d%I64d",&l,&r,&x);
			update(1,1,n,l,r,x);
		}
		//cout<<query(1,1,n,2,2)<<endl;
		if(k==2){
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%I64d\n",query(1,1,n,l,r));
		}
	}
}
