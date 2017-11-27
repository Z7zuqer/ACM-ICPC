#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=1e5+7; 
LL tr[maxn<<2],flg[maxn<<2];
void pushdown(int t,int l,int r){
	if(flg[t]){
		flg[t<<1]+=flg[t];
		flg[t<<1|1]+=flg[t];
		int mid=(l+r)>>1;
		tr[t<<1]+=1LL*(mid-l+1)*flg[t];
		tr[t<<1|1]+=1LL*(r-mid)*flg[t];
		flg[t]=0;
	}
}
void update(int t,int l,int r,int L,int R,LL v){
	if(L<=l&&r<=R){
		tr[t]+=(r-l+1LL)*v;
		flg[t]+=v;
		return ;
	}
	pushdown(t,l,r);
	int mid=(l+r)>>1;
	if(mid>=L)update(t<<1,l,mid,L,R,v);
	if(mid<R)update(t<<1|1,mid+1,r,L,R,v);
	tr[t]=tr[t<<1|1]+tr[t<<1];
}
LL query(int t,int l,int r,int L,int R){
	if(L<=l&&r<=R)return tr[t];
	LL res=0;
	int mid=(l+r)>>1;
	pushdown(t,l,r);
	if(mid>=L)res+=query(t<<1,l,mid,L,R);
	if(mid<R)res+=query(t<<1|1,mid+1,r,L,R);
	tr[t]=tr[t<<1]+tr[t<<1|1];
	return res;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		LL l,r,d;
		scanf("%lld%lld%lld",&l,&r,&d);
		update(1,1,n,l,r,d);
	}
	int k,ans=0;
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		LL h,x;
		scanf("%lld%lld",&h,&x);
		if(query(1,1,n,x,n)<h)ans++;
	}
	printf("%d\n",ans);
}


